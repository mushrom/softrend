#include <softrend/backend/sdl.hpp>
#include <softrend/render.hpp>
#include <softrend/jobQueue.hpp>
#include <chrono>
#include <vector>
#include <array>
#include <algorithm> // sort
#include <list>

using namespace softrend;

void func(const vec4& a, const vec4& b) {
	float meh = dot(a, b);
	printf("yooo: %g\n", meh);
}

void yolo(void) {
	mat4 p = perspective(M_PI/2.f, 16.f/9.f, 0.1f, 100.f);

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			printf("p[%d][%d] = %g\n", y, x, p[4*y + x]);
		}
	}
}

static const vec3 cube_vertices[] = {
	// front
	{-1.0, -1.0,  1.0},
	{ 1.0, -1.0,  1.0},
	{ 1.0,  1.0,  1.0},
	{-1.0,  1.0,  1.0},
	// top
	{-1.0,  1.0,  1.0},
	{ 1.0,  1.0,  1.0},
	{ 1.0,  1.0, -1.0},
	{-1.0,  1.0, -1.0},
	// back
	{ 1.0, -1.0, -1.0},
	{-1.0, -1.0, -1.0},
	{-1.0,  1.0, -1.0},
	{ 1.0,  1.0, -1.0},
	// bottom
	{-1.0, -1.0, -1.0},
	{ 1.0, -1.0, -1.0},
	{ 1.0, -1.0,  1.0},
	{-1.0, -1.0,  1.0},
	// left
	{-1.0, -1.0, -1.0},
	{-1.0, -1.0,  1.0},
	{-1.0,  1.0,  1.0},
	{-1.0,  1.0, -1.0},
	// right
	{ 1.0, -1.0,  1.0},
	{ 1.0, -1.0, -1.0},
	{ 1.0,  1.0, -1.0},
	{ 1.0,  1.0,  1.0},
};

static const vec3 cube_normals[] = {
	// front
	{0, 0, 1},
	{0, 0, 1},
	{0, 0, 1},
	{0, 0, 1},
	// top
	{0, 1, 0},
	{0, 1, 0},
	{0, 1, 0},
	{0, 1, 0},
	// back
	{0, 0, -1},
	{0, 0, -1},
	{0, 0, -1},
	{0, 0, -1},
	// bottom
	{0, -1, 0},
	{0, -1, 0},
	{0, -1, 0},
	{0, -1, 0},
	// left
	{-1, 0, 0},
	{-1, 0, 0},
	{-1, 0, 0},
	{-1, 0, 0},
	// right
	{1, 0, 0},
	{1, 0, 0},
	{1, 0, 0},
	{1, 0, 0},
};


static const uint32_t cube_elements[] = {
	// front
	0,  1,  2,
	2,  3,  0,
	// top
	4,  5,  6,
	6,  7,  4,
	// back
	8,  9, 10,
	10, 11,  8,
	// bottom
	12, 13, 14,
	14, 15, 12,
	// left
	16, 17, 18,
	18, 19, 16,
	// right
	20, 21, 22,
	22, 23, 20,
};

static const vec2 cube_texcoords[] = {
	{0.0, 0.0},
	{1.0, 0.0},
	{1.0, 1.0},
	{0.0, 1.0},

	{0.0, 0.0},
	{1.0, 0.0},
	{1.0, 1.0},
	{0.0, 1.0},

	{0.0, 0.0},
	{1.0, 0.0},
	{1.0, 1.0},
	{0.0, 1.0},

	{0.0, 0.0},
	{1.0, 0.0},
	{1.0, 1.0},
	{0.0, 1.0},

	{0.0, 0.0},
	{1.0, 0.0},
	{1.0, 1.0},
	{0.0, 1.0},

	{0.0, 0.0},
	{1.0, 0.0},
	{1.0, 1.0},
	{0.0, 1.0},
};

static const float colors[] = {
	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	1, 1, 1,

	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	1, 1, 1,

	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	1, 1, 1,

	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	1, 1, 1,

	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	1, 1, 1,

	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	1, 1, 1,
};

template <typename T, typename F>
struct fbPair {
	fbPair(framebuffer<T> *c, framebuffer<F> *d)
		: color(c), depth(d) {};

	framebuffer<T> *color = nullptr;
	framebuffer<F> *depth = nullptr;
};

struct vertex_buffer {
	std::vector<vec3> vertices;
	std::vector<vec3> normals;
	std::vector<vec2> uvs;
	std::vector<uint32_t> elements;
};

using Coord = std::pair<int, int>;
using Tri = std::array<Coord, 3>;

struct vertexOut {
	Coord screenpos;
	vec3 position;
	vec3 normal;
	vec2 uv;
	float depth;
};

struct geomOutTri {
	std::array<vertexOut, 3> vertices;
};

enum drawFlags {
	DepthTest      = (1 << 0),
	DepthMask      = (1 << 1),
	CullFrontFaces = (1 << 2),
	CullBackFaces  = (1 << 3),
	SortGeometry   = (1 << 4),
};

struct shadingUniforms {
	mat4 p;
	mat4 v;
	mat4 m;
	mat4 rotx;
	mat4 roty;
	vec3 cameraPos;
	float zoom;
	float xoff;
};

struct screenRect {
	int xbegin;
	int ybegin;
	int xend;
	int yend;
};

#include <softrend/brick.h>
static inline
uint32_t getTexel(vec2 uv) {
	int width = _179_small_ppm_img.width;
	int height = _179_small_ppm_img.height;

	int x = int(uv[0] * width) % width;
	int y = int(uv[1] * height) % height;

	x = (x < 0)? width  + x : x;
	y = (y < 0)? height + y : y;

	uint8_t *idx = _179_small_ppm_img.pixels
		+ 3*(y*width)
		+ 3*x;

	//return (ubvec4) {0xff, idx[2], idx[1], idx[0]};
	return idx[2] | (idx[1] << 8) | (idx[0] << 16);
}

template <typename T, typename U, typename F>
struct baseShader {
	static inline
	T vertexShader(const U& uniforms,
	               const T& in,
	               float width,
	               float height)
	{
		const vec3& vert = in.position;
		const vec3& norm = in.normal;
		const vec2& uv   = in.uv;

		vec4 temp = (vec4){vert[0], vert[1], vert[2], 1.f};
		temp = mult(uniforms.p,
					mult(uniforms.v,
					mult(uniforms.m,
					mult(uniforms.rotx,
					mult(uniforms.roty, temp)))));

		vec4 adj = ((temp/temp[3])*0.5f + 0.5f);

		//int x = adj[0]*ctx.buffers.color->width;
		//int y = adj[1]*ctx.buffers.color->height;
		int x = adj[0]*width;
		int y = adj[1]*height;

		//printf("screenpos: (%d, %d)\n", x, y);
		return (T) {
			.screenpos = Coord {x, y},
			.position  = (vec3) {temp[0], temp[1], temp[2]},
			.uv        = uv,
			.depth     = adj[2]
		};
	}

	static inline
	bool fragmentShader(const U& uniforms,
	                    const T& in,
	                    F& buffers,
	                    int fragX,
	                    int fragY)
	{
		uint32_t c = uint32_t(0xff*in.uv[0]) | (uint32_t(0xff*in.uv[1]) << 8);
		buffers.color->setPixel(fragX, fragY, c);
		return true;
	}
};

template <typename T, typename U, typename F>
struct textureShader : baseShader<T, U, F> {
	static inline
	bool fragmentShader(const U& uniforms,
	                    const T& in,
	                    F& buffers,
	                    int fragX,
	                    int fragY)
	{
		auto c = getTexel(in.uv);
		buffers.color->setPixel(fragX, fragY, c);
		return true;
	}
};

/*
template <template <typename T, typename U, typename F> typename S>
concept Shader = requires(S<T, U, F> a) {
	S<T, U, F>::vertexShader;
	S<T, U, F>::fragmentShader;
};
*/

template<typename T>
concept Renderable = requires(T a) {
	// vertex attribute format requires a mix function
	// (also requires a T::vertexAttr())
	mix(typename T::vertexAttr(), typename T::vertexAttr(), 0.5f);

	// need a depth and color buffer
	a.buffers.color;
	a.buffers.depth;
};

// template speak for using a templated shader struct as defined above
// so, this would just be instantiated as `renderContext<urShaderHere>`
template <template <typename, typename, typename> typename S>
struct renderContext {
	renderContext(jobQueue& j, framebuffer<uint32_t> *c, framebuffer<float> *d)
		: jobs(j), buffers(c, d) {};

	using vertexAttr = vertexOut;
	using Framebuffers = fbPair<uint32_t, float>;
	//using vertexShader = perspectiveVertexShader<vertexAttr>;
	using shaders = S<vertexAttr, shadingUniforms, Framebuffers>;

	shadingUniforms uniforms;
	jobQueue& jobs;
	Framebuffers buffers;
	// XXX
	using Bins = std::vector<int>;
	using Geobuf = std::vector<geomOutTri>;

	// TODO: lockless
	std::mutex mtx;
	// std::list because references remain valid after inserting
	// elements, std::vector references will be invalidated after the
	// underlying storage is resized
	// since this is just used for keeping track of resources it's no problem,
	// the code works with the references directly
	std::list<Geobuf> geometryBuf;
	std::list<Bins> bins;
	std::list<shadingUniforms> uniformBuffers;

	Geobuf& allocGeobuf(void) {
		std::unique_lock<std::mutex> slock(mtx);

		geometryBuf.push_back({});
		return geometryBuf.back();
	}

	Bins& allocBins(void) {
		std::unique_lock<std::mutex> slock(mtx);

		bins.push_back({});
		return bins.back();
	}

	shadingUniforms& allocUniforms(void) {
		std::unique_lock<std::mutex> slock(mtx);

		uniformBuffers.push_back(shadingUniforms());
		return uniformBuffers.back();
	}

	/*
	Geobuf& allocGeobuf(void);
	Bins& allocBins(void);
	*/

	void sync(void) {
		jobs.sync();
		{
			std::unique_lock<std::mutex> slock(mtx);
			geometryBuf.clear();
			bins.clear();
			uniformBuffers.clear();
		}
	}
};

/*
renderContext::Geobuf& renderContext::allocGeobuf(void) {
	std::unique_lock<std::mutex> slock(mtx);

	geometryBuf.push_back({});
	geometryBuf.back().reserve(32);
	return geometryBuf.back();
}

renderContext::Bins& renderContext::allocBins(void) {
	std::unique_lock<std::mutex> slock(mtx);

	bins.push_back({});
	return bins.back();
}
*/

static inline
struct vertexOut mix(const vertexOut& a, const vertexOut& b, float amt) {
	return (vertexOut) {
		// no screen position interpolation
		//.screenpos = mix(a.screenpos, b.screenpos, amt),
		.position = mix(a.position, b.position, amt),
		.normal   = mix(a.normal, b.normal, amt),
		.uv       = mix(a.uv, b.uv, amt),
		.depth    = mix(a.depth, b.depth, amt)
	};
}

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

	static shadingUniforms uniforms; //XXX
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
void drawFlatTopTri(T& ctx, const screenRect& bounds, const geomOutTri& t) {
	auto& vs = t.vertices;

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

		drawHorizontalLine(ctx, bounds, l.first, r.first, y, luv, ruv);
	}
};

template <Renderable T>
void drawFlatBottomTri(T& ctx, const screenRect& bounds, const geomOutTri& t) {
	auto& vs = t.vertices;

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

		drawHorizontalLine(ctx, bounds, l.first, r.first, y, luv, ruv);
	}
};

template <Renderable T>
void drawTriangle(T& ctx, const screenRect& bounds, const geomOutTri& t) {
	geomOutTri temp = t;
	auto& vs = temp.vertices;

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
		geomOutTri foo = {vs[2], vs[0], vs[1]};
		drawFlatTopTri(ctx, bounds, foo);

	} else if (vs[1].screenpos.second == vs[2].screenpos.second) {
		drawFlatBottomTri(ctx, bounds, temp);

	} else {
		line longline(vs[0].screenpos, vs[2].screenpos);

		float amt = longline.unitFromY(vs[1].screenpos.second);
		vertexOut c = mix(vs[0], vs[2], amt);
		c.screenpos = longline.atY(vs[1].screenpos.second);

		/*
		vertexOut c = {
			.screenpos = longline.atY(vs[1].screenpos.second),
			.position  = mix(ms[0])
			.uv        = mix(vs[0].uv, vs[2].uv, amt),
			.depth     = mix(vs[0].depth, vs[2].depth, amt),
		};
		*/

		geomOutTri b = {vs[2], c, vs[1]};

		// can use temp for top tri, drawFlatBottomTri will stop at vs[1],
		// which is the second smallest (and so the intersection point)
		drawFlatBottomTri(ctx, bounds, temp);
		drawFlatTopTri(ctx, bounds, b);
	}
};

template <Renderable T>
void drawTriangleLines(T& ctx, T color, const geomOutTri& t) {
	auto& vs = t.vertices;

	for (int k = 0; k < 3; k++) {
		int j = k;
		int m = (k+1)%3;

		drawLine(ctx, color, vs[j].screenpos.first, vs[j].screenpos.second,
		                     vs[m].screenpos.first, vs[m].screenpos.second);
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
		/*
		vec3& vert = vertbuf.vertices[em];
		vec3& norm = vertbuf.normals[em];
		vec2& uv   = vertbuf.uvs[em];

		vec4 temp = (vec4){vert[0], vert[1], vert[2], 1.f};
		temp = mult(unistate.p,
		            mult(unistate.v,
		            mult(unistate.m,
		            mult(unistate.rotx,
		            mult(unistate.roty, temp)))));

		vec4 adj = ((temp/temp[3])*0.5f + 0.5f);

		int x = adj[0]*ctx.buffers.color->width;
		int y = adj[1]*ctx.buffers.color->height;

		//printf("screenpos: (%d, %d)\n", x, y);
		vertout[n++] = (typename T::vertexAttr) {
			.screenpos = Coord {x, y},
			.position  = (vec3) {temp[0], temp[1], temp[2]},
			.uv        = uv,
			.depth     = adj[2]
		};
		*/

		vertout[n++] = T::shaders::vertexShader(unistate, (typename T::vertexAttr) {
			.position = vertbuf.vertices[em],
			.normal   = vertbuf.normals[em],
			.uv       = vertbuf.uvs[em]
		},
		ctx.buffers.color->width,
		ctx.buffers.color->height		);

		if (n >= 3) {
			geometryTris.push_back((geomOutTri) {
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
		static const int yinc = 64;
		static const int xinc = 64;

		if (flags & SortGeometry) {
			std::sort(geometryTris.begin(), geometryTris.end(),
				[] (geomOutTri& a, geomOutTri& b) {
					auto& av = a.vertices;
					auto& bv = b.vertices;
					float aavg = (av[0].depth + av[1].depth + av[2].depth) / 3.f;
					float bavg = (bv[0].depth + bv[1].depth + bv[2].depth) / 3.f;
					return aavg < bavg;
				});
		}

		int xdiv = ctx.buffers.color->width  / xinc + !!(ctx.buffers.color->width % xinc);
		int ydiv = ctx.buffers.color->height / yinc + !!(ctx.buffers.color->height % yinc);

		// covers 2048*2048
		// TODO: buffer in render context
		//std::vector<int> bins[64][64];
		//auto bins = new std::vector<int>[64][64];
		//ctx.bins.push_back({});
		//auto& bins = ctx.bins.back();
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
				Coord s = tri.vertices[k].screenpos;
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

#if 0
				// TODO: function
				ctx.jobs.addAsync([&bins, &geometryTris, &ctx, flags,
								   rect, xpos, ypos, stride, binsize] ()
				{
					size_t idx = ypos*stride + xpos*binsize;
					int n = bins[idx];
					for (int i = 0; i < n; i++) {
						drawTriangle(ctx, rect, geometryTris[bins[idx+i+1]]);
					}

					return true;
				});
#else
				for (size_t i = 0; i < geometryTris.size(); i++) {
					drawTriangle(ctx, rect, geometryTris[i]);
				}
#endif
			}
		}

		return true;
	});

	//ctx.jobs.sync();
	//usleep(10000);
}

int main(void) {
	__builtin_cpu_init();

	if (!__builtin_cpu_supports("avx")) {
		puts("wut");
		return 1;
	}

	SDL_Init(SDL_INIT_VIDEO);
	sdl2_backend back(1280, 720);
	jobQueue jobs(std::thread::hardware_concurrency());
	//sdl2_backend back(960, 540);
	/*

	jobs.addAsync([] () {
		puts("Got here!");
		return true;
	});
	*/

	//sdl2_backend back(640, 360);
	auto fb = back.getFramebuffer();
	framebuffer<float> depthfb(fb->width, fb->height, fb->pitch);
	//fbPair buffers = {fb, &depthfb};
	renderContext<textureShader> ctx(jobs, fb, &depthfb);

	vertex_buffer vertbuf;
	for (auto& em : cube_vertices) { vertbuf.vertices.push_back(em); }
	for (auto& em : cube_normals) { vertbuf.normals.push_back(em); }
	for (auto& em : cube_elements) { vertbuf.elements.push_back(em); }
	for (auto& em : cube_texcoords) { vertbuf.uvs.push_back(em); }

#if 0
	srand(time(NULL));
	size_t n = (rand() % 1024) + 128;
	auto rf = []() { return float(rand() / float(RAND_MAX)); };
	vec4 heh[n];

	for (int i = 0; i < n; i++) {
		heh[i] = (vec4){rf(), rf(), rf(), rf()};
	}

	for (int i = 1; i < n; i++) {
		/*
		float meh = dot(heh[i-1], heh[i]);
		printf("yooo: %g\n", meh);
		*/
		func(heh[i-1], heh[i]);
	}

	yolo();
#endif

	

	printf("\n");
	float times[8];
	unsigned timeidx;

	/*
	mat4 p = perspective(M_PI/2.f, 16.f/9.f, 0.1f, 100.f);
	mat4 rotx = identity_mat4();
	mat4 roty = identity_mat4();
	float zoom = -64;
	float xoff = 0.f;
	*/

	shadingUniforms uniforms;

	uniforms.p = perspective(M_PI/2.f, 16.f/9.f, 0.1f, 100.f);
	uniforms.rotx = identity_mat4();
	uniforms.roty = identity_mat4();
	uniforms.zoom = 64;
	uniforms.xoff = 0.f;
	uniforms.cameraPos = (vec3) {0, 0, 0};

	mat4 cameraRot = identity_mat4();

	for (size_t i = 0;; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT)
				return 0;

			if (ev.type == SDL_KEYDOWN) {
				switch (ev.key.keysym.sym) {
					case SDLK_w: uniforms.cameraPos[2] += 1.0; break;
					case SDLK_a: uniforms.cameraPos[0] += 1.0;  break;
					case SDLK_s: uniforms.cameraPos[2] -= 1.0; break;
					case SDLK_d: uniforms.cameraPos[0] -= 1.0; break;
					case SDLK_q: uniforms.cameraPos[1] += 1.0; break;
					case SDLK_e: uniforms.cameraPos[1] -= 1.0; break;
					default: break;
				}
			}
		}

		int mx, my;
		uint32_t mouse = SDL_GetMouseState(&mx, &my);

		if (mouse & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			//rotx = rotateY(M_PI * float(mx) / fb->width);
			uniforms.rotx = rotateY(2*M_PI * float(mx) / fb->width);
			uniforms.roty = rotateX(2*M_PI * float(my) / fb->height);
		}

		if (mouse & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
			uniforms.zoom = 32 + 64*(float(my)/fb->height - 0.5);
			uniforms.xoff = 32*(float(mx)/fb->width - 0.5);
		}

		if (mouse & SDL_BUTTON(SDL_BUTTON_MIDDLE)) {
			//uniforms.v = mult()
			mat4 rx = rotateY(-2*M_PI * float(mx) / fb->width);
			mat4 ry = rotateX(-2*M_PI * float(my) / fb->height);

			//cameraRot = rx;
			cameraRot = mult(rx, ry);
		}

		fb->clear();
		depthfb.clear(HUGE_VALF);

		int flags
			= DepthTest
			| DepthMask
			| CullBackFaces
			| SortGeometry;

		//uniforms.v = mult(identity_mat4(), translate(-uniforms.cameraPos));
		//uniforms.v = mult(translate(-uniforms.cameraPos), identity_mat4());
		//uniforms.v = mult(translate(-uniforms.cameraPos), cameraRot);
		//uniforms.v = mult(cameraRot, translate(-uniforms.cameraPos));
		//uniforms.v = mult(translate(-uniforms.cameraPos), identity_mat4());
		uniforms.v = mult(translate(-uniforms.cameraPos), cameraRot);
		//uniforms.v = translate(-uniforms.cameraPos);

		uniforms.m = translate((vec3) {uniforms.xoff, 0, uniforms.zoom});
		drawBufferTriangles(ctx, vertbuf, uniforms, flags);

		time_t foo = time(NULL);
#if 1
		uint64_t j = 0;
		for (int kz = 0; kz < 64; kz += 16) {
			for (int kx = -8; kx < 8; kx += 4) {
				for (int ky = -8; ky < 8; ky += 4) {
					//if (foo&(1ULL << j)) {
						uniforms.m = translate((vec3) {
								uniforms.xoff+kx,
								float(ky),
								uniforms.zoom + kz
								});
						drawBufferTriangles(ctx, vertbuf, uniforms, flags);
					//}

					j++;
				}
			}
		}
#endif

		/*
		for (size_t y = i&0xff; y < fb->height; y++) {
			for (size_t x = i&0xff; x < fb->width; x++) {
				uint8_t m = ((x^y) - i) & 0xff;
				//fb->setPixel(x, y, (m<<24) | (m<<20) | (m<<16) | 0xff);
				fb->setPixel(x, y, (ubvec4){0xff, m, m, m});
			}
		}
		*/

		ctx.sync();
		auto end = std::chrono::high_resolution_clock::now();
		back.swapFramebuffer();
		std::chrono::duration<float> secs = end - start;

		times[timeidx++ % 8] = secs.count();

		float frametimes = 0;
		for (unsigned i = 0; i < 8; i++) {
			frametimes += times[(timeidx + i) % 8];
		}
		frametimes /= 8.f;

		/*
		static int lol[1000];
		for (int n = 0; n < 1000; n++) {
			jobs.addAsync([=] () {
				lol[n] = n;
				//printf("yoooo we %d\n", n);
				return true;
			});
		}
		jobs.sync();
		*/

		static unsigned counter = 1;
		if (counter++ % 11 == 0) {
			printf("\rFPS: %g         ", 1.f/frametimes);
			fflush(stdout);
		}

		int time = 1000 * (1/60.f - secs.count());
		if (time > 0) {
			SDL_Delay(time);
		}
		//SDL_Delay(16);
		//SDL_Delay(32);
	}

	return 0;
}

