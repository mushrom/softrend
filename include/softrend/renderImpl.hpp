#pragma once

#include <softrend/renderContext.hpp>
#include <softrend/math.hpp>

#include <vector>
#include <array>
#include <algorithm> // sort
#include <list>

namespace softrend {

struct line {
	Coord coord;
	Coord end;

	float dx;
	float dy;
	float unit;

	// from point pair
	line(const Coord& a, const Coord& b) {
		coord = a;
		end = b;

		dx = b.first - a.first;
		dy = b.second - a.second;
		// abs is fine since it'll always be an integer distance
		unit = max(abs(dx), abs(dy));
		unit = (unit == 0)? 1 : unit;

		dx /= unit;
		dy /= unit;
	}

	inline Coord atY(int y) {
		//float i = abs((y - coord.second))*dy;
		float i = (y - coord.second)/dy;
		//float i = ((y - coord.second))/dy;
		//float i = ((y - coord.second))/dy;

		return {
			coord.first  + i*dx,
			//coord.second + i*dy
			y,
		};
	}

	inline Coord atX(int x) {
		float i = (x - coord.first)*dx;

		return {
			coord.first  + i*dx,
			coord.second + i*dy
		};
	}

	inline float unitFromY(int y) {
		return float(y - coord.second) / float(end.second - coord.second);
	}

	inline Coord atUnit(float u) {
		return {
			coord.first  + u*dx,
			coord.second + u*dy,
		};
	}
};

template <Renderable T>
void drawLine(T& ctx, T color, int x1, int y1, int x2, int y2) {
	float dx = x2 - x1;
	float dy = y2 - y1;
	float unit = (abs(dx) > abs(dy))? abs(dx) : abs(dy);
	dx /= unit;
	dy /= unit;

	for (int i = 0; i <= unit && i < ctx.buffers.color->width; i++) {
		int x = x1 + i*dx;
		int y = y1 + i*dy;

		if (x < 0 || y < 0
		    || x >= ctx.buffers.color->width
		    || y >= ctx.buffers.color->height)
			continue;

		ctx.buffers.color->setPixel(x, y, color);
	}
}

template <Renderable T>
void drawHorizontalLine(T& ctx,
                        const typename T::uniformType& uniforms,
                        const screenRect& bounds,
                        int x1, int x2, int y,
                        vertexOut& avert, vertexOut& bvert)
{
	if (y < 0 || y >= ctx.buffers.color->height) return;
	if (y < bounds.ybegin || y >= bounds.yend)   return;

	int start = (x1 < x2)? x1 : x2;
	int end   = (x1 < x2)? x2 : x1;
	int diff  = max(1, end - start);

	//vec2 suv = (x1 < x2)? uva : uvb;
	//vec2 euv = (x1 < x2)? uvb : uva;
	vertexOut& startvert = (x1 < x2)? avert : bvert;
	vertexOut& endvert   = (x1 < x2)? bvert : avert;

	int bostart = clamp(start, bounds.xbegin, bounds.xend);
	int boend   = clamp(end,   bounds.xbegin, bounds.xend);

	for (int x = bostart; x < boend; x++) {
		float amount = float(x - start)/diff;

		//vertexOut vertattr = mix(startvert, endvert, amount);
		float depth = mix(startvert.depth, endvert.depth, amount);

		if (depth < ctx.buffers.depth->getPixel(x, y)) {
			typename T::vertexAttr attr = mix(startvert, endvert, amount);

			bool shaded =
				T::shaders::fragmentShader(uniforms, attr, ctx.buffers, x, y);

			if (shaded) {
				ctx.buffers.depth->setPixel(x, y, depth);
			}
		}
	}
};

template <Renderable T>
void drawFlatTopTri(T& ctx,
                    const typename T::uniformType& uniforms,
                    const screenRect& bounds,
                    const typename T::geomOutTri& vs)
{
	// first is assumed to be bottom vert
	line left(vs[0].screenpos, vs[1].screenpos);
	line right(vs[0].screenpos, vs[2].screenpos);

	//int start = min((int)ctx.buffers.color->height-1, vs[0].screenpos.second);
	//int end   = max(0, vs[1].screenpos.second);
	int start = min(bounds.yend - 1, vs[0].screenpos.second);
	int end   = max(bounds.ybegin,   vs[1].screenpos.second);

	// loop towards the top, decrementing
	for (int y = start; y >= end; y--) {
		Coord l = left.atY(y);
		Coord r = right.atY(y);

		//vec2 luv = mix(vs[0].uv, vs[1].uv, left.unitFromY(y));
		//vec2 ruv = mix(vs[0].uv, vs[2].uv, right.unitFromY(y));
		vertexOut luv = mix(vs[0], vs[1], left.unitFromY(y));
		vertexOut ruv = mix(vs[0], vs[2], right.unitFromY(y));

		drawHorizontalLine(ctx, uniforms, bounds, l.first, r.first, y, luv, ruv);
	}
};

template <Renderable T>
void drawFlatBottomTri(T& ctx,
                       const typename T::uniformType& uniforms,
                       const screenRect& bounds,
                       const typename T::geomOutTri& vs)
{
	// first is assumed to be top vert
	line left(vs[0].screenpos, vs[1].screenpos);
	line right(vs[0].screenpos, vs[2].screenpos);

	//int start = max(0, vs[0].screenpos.second);
	//int end   = min((int)ctx.buffers.color->height-1, vs[1].screenpos.second);
	int start = max(bounds.ybegin,   vs[0].screenpos.second);
	int end   = min(bounds.yend - 1, vs[1].screenpos.second);

	// loop towards the bottom, incrementing
	for (int y = start; y <= end; y++) {
		Coord l = left.atY(y);
		Coord r = right.atY(y);

		//vec2 luv = mix(vs[0].uv, vs[1].uv, left.unitFromY(y));
		//vec2 ruv = mix(vs[0].uv, vs[2].uv, right.unitFromY(y));
		vertexOut luv = mix(vs[0], vs[1], left.unitFromY(y));
		vertexOut ruv = mix(vs[0], vs[2], right.unitFromY(y));

		drawHorizontalLine(ctx, uniforms, bounds, l.first, r.first, y, luv, ruv);
	}
};

template <Renderable T>
void drawTriangle(T& ctx,
                  const typename T::uniformType& uniforms,
                  const screenRect& bounds,
                  const typename T::geomOutTri& t)
{
	typename T::geomOutTri vs = t;

	// 9 compares, unrollable, it's fiiiine
	// sort by Y
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2-i; k++) {
			if (vs[k].screenpos.second > vs[k+1].screenpos.second) {
				std::swap(vs[k], vs[k+1]);
			}
		}
	}

	if (vs[0].screenpos.second == vs[1].screenpos.second) {
		//Tri foo = {temp[2], temp[0], temp[1]};
		typename T::geomOutTri foo = {vs[2], vs[0], vs[1]};
		drawFlatTopTri(ctx, uniforms, bounds, foo);

	} else if (vs[1].screenpos.second == vs[2].screenpos.second) {
		drawFlatBottomTri(ctx, uniforms, bounds, vs);

	} else {
		line longline(vs[0].screenpos, vs[2].screenpos);

		float amt = longline.unitFromY(vs[1].screenpos.second);
		vertexOut c = mix(vs[0], vs[2], amt);
		c.screenpos = longline.atY(vs[1].screenpos.second);

		typename T::geomOutTri b = {vs[2], c, vs[1]};

		// can use vs for top tri, drawFlatBottomTri will stop at vs[1],
		// which is the second smallest (and so the intersection point)
		drawFlatBottomTri(ctx, uniforms, bounds, vs);
		drawFlatTopTri(ctx, uniforms, bounds, b);
	}
};

template <Renderable T>
void drawTriangleLines(T& ctx, T color, const typename T::geomOutTri& vs) {
	for (int k = 0; k < 3; k++) {
		int j = k;
		int m = (k+1)%3;

		drawLine(ctx, color, vs[j].screenpos.first, vs[j].screenpos.second,
		                     vs[m].screenpos.first, vs[m].screenpos.second);
	}
}

template <Renderable T>
void drawGeometry(T& ctx,
                  typename T::Geobuf& geometryTris,
                  typename T::uniformType& uniforms,
                  typename T::Bins& bins,
                  screenRect rect,
				  // hmmm.... this is a lot of parameters
                  int xpos, int ypos,
                  int stride, int binsize,
                  int flags)
{

	size_t idx = ypos*stride + xpos*binsize;
	int n = bins[idx];
	for (int i = 0; i < n; i++) {
		drawTriangle(ctx, uniforms, rect, geometryTris[bins[idx+i+1]]);
	}
}

template <Renderable T>
void processGeometry(T& ctx,
                     typename T::Geobuf& geometryTris,
                     typename T::uniformType& unistate,
                     int flags)
{
	static const int yinc = 64;
	static const int xinc = 64;

	if (flags & SortGeometry) {
		std::sort(geometryTris.begin(), geometryTris.end(),
			[] (typename T::geomOutTri& a, typename T::geomOutTri& b) {
				float aavg = (a[0].depth + a[1].depth + a[2].depth) / 3.f;
				float bavg = (b[0].depth + b[1].depth + b[2].depth) / 3.f;
				return aavg < bavg;
			});
	}

	int xdiv = ctx.buffers.color->width  / xinc + !!(ctx.buffers.color->width % xinc);
	int ydiv = ctx.buffers.color->height / yinc + !!(ctx.buffers.color->height % yinc);

	// big XXX
	auto& bins = ctx.allocBins();
	size_t binsize = geometryTris.size() + 1;
	size_t stride = xdiv*binsize;
	bins.reserve(ydiv * stride);
	bins.resize(bins.capacity());
	for (size_t n = 0; n < bins.size(); n += stride) bins[n] = 0;

	for (int i = 0; i < geometryTris.size(); i++) {
		auto& tri = geometryTris[i];

		int xmin = xdiv-1;
		int ymin = ydiv-1;
		int xmax = 0;
		int ymax = 0;

		// bin by bounding box, a rectangle laid over the whole triangle
		// could bin by doing a rough rasterization of the triangle,
		// but this is simpler to implement for now
		// so TODO: bin by rough rasterization
		for (int k = 0; k < 3; k++) {
			Coord s = tri[k].screenpos;
			s.first /= xinc, s.second /= yinc;

			xmin = min(xmin, s.first);
			xmax = max(xmax, s.first);
			ymin = min(ymin, s.second);
			ymax = max(ymax, s.second);

			xmin = max(xmin, 0);
			xmax = min(xmax, xdiv-1);
			ymin = max(ymin, 0);
			ymax = min(ymax, ydiv-1);
		}

		for (int x = xmin; x <= xmax; x++) {
			for (int y = ymin; y <= ymax; y++) {
				int& c = bins[y*stride + x*binsize];
				if (c < binsize) {
					c++;
					bins[y*stride + x*binsize + c] = i;
				}
			}
		}
	}

	for (int y = 0; y < ctx.buffers.color->height; y += yinc) {
		for (int x = 0; x < ctx.buffers.color->width; x += xinc) {
			int xpos = x/xinc;
			int ypos = y/yinc;

			size_t idx = ypos*stride + xpos*binsize;
			if (bins[idx] == 0) {
				continue;
			}

			screenRect rect = {
				x, y,
				min(x+xinc, int(ctx.buffers.color->width)),
				min(y+yinc, int(ctx.buffers.color->height)),
			};

#if 1
			ctx.jobs.addAsync([&bins, &geometryTris, &ctx, &unistate, flags,
							   rect, xpos, ypos, stride, binsize] ()
			{
				drawGeometry(ctx, geometryTris, unistate, bins, rect,
				             xpos, ypos, stride, binsize, flags);

				return true;
			});
#else
			for (size_t i = 0; i < geometryTris.size(); i++) {
				drawTriangle(ctx, rect, geometryTris[i]);
			}
#endif
		}
	}
}

template <Renderable T>
void drawBufferTriangles(T& ctx,
                         vertex_buffer& vertbuf,
                         shadingUniforms& uniforms,
                         int flags)
{
	if (!ctx.buffers.color || !ctx.buffers.depth) {
		return;
	}

	shadingUniforms& unistate = ctx.allocUniforms();
	unistate = uniforms;

	//std::vector<typename T::vertexAttr> vertout;
	std::array<typename T::vertexAttr, 3> vertout;
	auto& geometryTris = ctx.allocGeobuf();

	size_t n = 0;
	for (auto& em : vertbuf.elements) {
		vertout[n++] = T::shaders::vertexShader(unistate,
			(typename T::vertexAttr) {
				.position = vertbuf.vertices[em],
				.normal   = vertbuf.normals[em],
				.uv       = vertbuf.uvs[em]
			},
			ctx.buffers.color->width,
			ctx.buffers.color->height
		);

		if (n >= 3) {
			geometryTris.push_back((typename T::geomOutTri) {
				vertout[0], vertout[1], vertout[2]
			});

			n = 0;
		}
	}

	/*
	ubvec4 color = (ubvec4){0xff, 0xff, 0xff, 0xff};
	int id = 0;

	auto newcolor = [&]() {
		uint8_t r = 0x80 + 0x1f*(id & 3);
		uint8_t g = 0x80 + 0x1f*((id >> 2) & 3);
		uint8_t b = 0x80 + 0x1f*((id >> 4) & 3);

		color = (ubvec4){0xff, b, g, r};
		id++;
	};
	*/

	/*
	ctx.geometryBuf.push_back({});
	auto& geometryTris = ctx.geometryBuf.back();
	*/

	//std::vector<geomOutTri> geometryTris;
	/*
	for (size_t i = 0; i < vertout.size(); i += 3) {
		geometryTris.push_back((geomOutTri) {
			vertout[i], vertout[i+1], vertout[i+2]
		});
	}
	*/

	// TODO: split into functions
	ctx.jobs.addAsync([&ctx, &geometryTris, &unistate, flags] ()
	{
		processGeometry(ctx, geometryTris, unistate, flags);
		return true;
	});

	//ctx.jobs.sync();
	//usleep(10000);
}

}
