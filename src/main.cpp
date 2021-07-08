#include <softrend/backend/sdl.hpp>
#include <chrono>
#include <vector>
#include <array>
#include <algorithm> // sort

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
	vec2 uv;
	float depth;
};

static inline
struct vertexOut mix(const vertexOut& a, const vertexOut& b, float amt) {
	return (vertexOut) {
		// no screen position interpolation
		//.screenpos = mix(a.screenpos, b.screenpos, amt),
		.uv        = mix(a.uv, b.uv, amt),
		.depth     = mix(a.depth, b.depth, amt)
	};
}

struct geomOutTri {
	/*
	Tri triangle;
	std::array<float, 3> depth;
	*/
	std::array<vertexOut, 3> vertices;
};

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

#include <softrend/brick.h>
ubvec4 getTexel(vec2 uv) {
	int width = _179_small_ppm_img.width;
	int height = _179_small_ppm_img.height;

	int x = int(uv[0] * width) % width;
	int y = int(uv[1] * height) % height;

	x = (x < 0)? width  + x : x;
	y = (y < 0)? height + y : y;

	uint8_t *idx = _179_small_ppm_img.pixels
		+ 3*(y*width)
		+ 3*x;

	return (ubvec4) {0xff, idx[2], idx[1], idx[0]};
}

struct shadingUniforms {
	mat4 p;
	mat4 v;
	mat4 rotx;
	mat4 roty;
	float zoom;
	float xoff;
};

template <typename T, typename F>
void drawLine(fbPair<T, F>& buffers, T color, int x1, int y1, int x2, int y2) {
	float dx = x2 - x1;
	float dy = y2 - y1;
	float unit = (abs(dx) > abs(dy))? abs(dx) : abs(dy);
	dx /= unit;
	dy /= unit;

	for (int i = 0; i <= unit && i < buffers.color->width; i++) {
		int x = x1 + i*dx;
		int y = y1 + i*dy;

		if (x < 0 || y < 0 || x >= buffers.color->width || y >= buffers.color->height)
			continue;

		buffers.color->setPixel(x, y, color);
	}
}

template <typename T, typename F>
void drawHorizontalLine(fbPair<T, F>& buffers, // TODO: texture parameter
                        int x1, int x2, int y,
                        vertexOut& avert, vertexOut& bvert)
{
	if (y < 0 || y >= buffers.color->height) return;

	int start = (x1 < x2)? x1 : x2;
	int end   = (x1 < x2)? x2 : x1;
	int diff  = max(1, end - start);

	//vec2 suv = (x1 < x2)? uva : uvb;
	//vec2 euv = (x1 < x2)? uvb : uva;
	vertexOut& startvert = (x1 < x2)? avert : bvert;
	vertexOut& endvert   = (x1 < x2)? bvert : avert;

	int bostart = clamp(start, 0, (int)buffers.color->width-1);
	int boend   = clamp(end,   0, (int)buffers.color->width-1);

	for (int x = bostart; x != boend; x++) {
		float amount = float(x - start)/diff;

		vec2 uv = mix(startvert.uv, endvert.uv, amount);
		float depth = mix(startvert.depth, endvert.depth, amount);

		if (depth < buffers.depth->getPixel(x, y)) {
			//uint8_t yolo = 0x10*depth;
			//ubvec4 meh = {0xff, yolo, yolo, yolo};
			//buffers.color->setPixel(x, y, meh);
			auto c = getTexel(uv);
			//buffers.color->setPixel(x, y, c);
			uint32_t px = (c[1] << 0) | (c[2] << 8) | (c[3] << 16);
			buffers.color->setPixel(x, y, px);
			buffers.depth->setPixel(x, y, depth);
		}
	}
};

template <typename T, typename F>
void drawFlatTopTri(fbPair<T, F>& buffers, const geomOutTri& t) {
	auto& vs = t.vertices;

	// first is assumed to be bottom vert
	line left(vs[0].screenpos, vs[1].screenpos);
	line right(vs[0].screenpos, vs[2].screenpos);

	int start = min((int)buffers.color->height-1, vs[0].screenpos.second);
	int end   = max(0, vs[1].screenpos.second);

	// loop towards the top, decrementing
	for (int y = start; y >= end; y--) {
		Coord l = left.atY(y);
		Coord r = right.atY(y);

		//vec2 luv = mix(vs[0].uv, vs[1].uv, left.unitFromY(y));
		//vec2 ruv = mix(vs[0].uv, vs[2].uv, right.unitFromY(y));
		vertexOut luv = mix(vs[0], vs[1], left.unitFromY(y));
		vertexOut ruv = mix(vs[0], vs[2], right.unitFromY(y));

		drawHorizontalLine(buffers, l.first, r.first, y, luv, ruv);
	}
};

template <typename T, typename F>
void drawFlatBottomTri(fbPair<T, F>& buffers, const geomOutTri& t) {
	auto& vs = t.vertices;

	// first is assumed to be top vert
	line left(vs[0].screenpos, vs[1].screenpos);
	line right(vs[0].screenpos, vs[2].screenpos);

	int start = max(0, vs[0].screenpos.second);
	int end   = min((int)buffers.color->height-1, vs[1].screenpos.second);

	// loop towards the bottom, incrementing
	for (int y = start; y <= end; y++) {
		Coord l = left.atY(y);
		Coord r = right.atY(y);

		//vec2 luv = mix(vs[0].uv, vs[1].uv, left.unitFromY(y));
		//vec2 ruv = mix(vs[0].uv, vs[2].uv, right.unitFromY(y));
		vertexOut luv = mix(vs[0], vs[1], left.unitFromY(y));
		vertexOut ruv = mix(vs[0], vs[2], right.unitFromY(y));

		drawHorizontalLine(buffers, l.first, r.first, y, luv, ruv);
	}
};

template <typename T, typename F>
void drawTriangle(fbPair<T, F>& buffers, const geomOutTri& t) {
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
		drawFlatTopTri(buffers, foo);

	} else if (vs[1].screenpos.second == vs[2].screenpos.second) {
		drawFlatBottomTri(buffers, temp);

	} else {
		line longline(vs[0].screenpos, vs[2].screenpos);

		float amt = longline.unitFromY(vs[1].screenpos.second);
		vertexOut c = {
			.screenpos = longline.atY(vs[1].screenpos.second),
			.uv        = mix(vs[0].uv, vs[2].uv, amt),
			.depth     = mix(vs[0].depth, vs[2].depth, amt),
		};

		geomOutTri b = {vs[2], c, vs[1]};

		// can use temp for top tri, drawFlatBottomTri will stop at vs[1],
		// which is the second smallest (and so the intersection point)
		drawFlatBottomTri(buffers, temp);
		drawFlatTopTri(buffers, b);
	}
};

template <typename T, typename F>
void drawTriangleLines(fbPair<T, F>& buffers, T color, const geomOutTri& t) {
	auto& vs = t.vertices;

	for (int k = 0; k < 3; k++) {
		int j = k;
		int m = (k+1)%3;

		drawLine(buffers, color, vs[j].screenpos.first, vs[j].screenpos.second,
		                         vs[m].screenpos.first, vs[m].screenpos.second);
	}
}

template <typename T, typename F>
void drawBufferTriangles(vertex_buffer& vertbuf,
                         fbPair<T, F>& buffers,
                         shadingUniforms& uniforms)
{
	if (!buffers.color || !buffers.depth) {
		return;
	}

	std::vector<vertexOut> vertout;
	//auto fb = back.getFramebuffer();

	//printf("zoom: %g\n", uniforms.zoom);

	for (auto& em : vertbuf.elements) {
		vec3& vert = vertbuf.vertices[em];
		vec3& norm = vertbuf.normals[em];
		vec2& uv   = vertbuf.uvs[em];

		vec4 temp = (vec4){vert[0], vert[1], vert[2], 1.f};
		temp = mult(uniforms.p,
		            mult(uniforms.v,
		            mult(uniforms.rotx,
		            mult(uniforms.roty, temp))));

		vec4 adj = ((temp/temp[3])*0.5f + 0.5f);

		int x = adj[0]*buffers.color->width;
		int y = adj[1]*buffers.color->height;

		//printf("screenpos: (%d, %d)\n", x, y);
		vertout.push_back((vertexOut) {
			.screenpos = Coord {x, y},
			.uv        = uv,
			.depth     = adj[2]
		});
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

	std::vector<geomOutTri> geometryTris;
	for (size_t i = 0; i < vertout.size(); i += 3) {
		geometryTris.push_back((geomOutTri) {
			vertout[i], vertout[i+1], vertout[i+2]
		});
	}

	std::sort(geometryTris.begin(), geometryTris.end(),
		[] (geomOutTri& a, geomOutTri& b) {
			auto& av = a.vertices;
			auto& bv = b.vertices;
			float aavg = (av[0].depth + av[1].depth + av[2].depth) / 3.f;
			float bavg = (bv[0].depth + bv[1].depth + bv[2].depth) / 3.f;
			return aavg < bavg;
		});

	for (size_t i = 0; i < geometryTris.size(); i++) {
		//printf("coord: (%d, %d)\n", geometryTris[i].vertices[0].screenpos.first, geometryTris[i].vertices[0].screenpos.second);
		//printf("depth: %g\n", geometryTris[i].vertices[0].depth);
		auto& geom = geometryTris[i];
		drawTriangle(buffers, geom);
	}
}

int main(void) {
	__builtin_cpu_init();

	if (!__builtin_cpu_supports("avx")) {
		puts("wut");
		return 1;
	}

	SDL_Init(SDL_INIT_VIDEO);
	sdl2_backend back(1280, 720);
	//sdl2_backend back(960, 540);
	auto fb = back.getFramebuffer();
	framebuffer<float> depthfb(fb->width, fb->height, fb->pitch);
	fbPair buffers = {fb, &depthfb};

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

	for (size_t i = 0;; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT)
				return 0;
		}

		int mx, my;
		uint32_t mouse = SDL_GetMouseState(&mx, &my);

		if (mouse & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			//rotx = rotateY(M_PI * float(mx) / fb->width);
			uniforms.rotx = rotateY(2*M_PI * float(mx) / fb->width);
			uniforms.roty = rotateX(2*M_PI * float(my) / fb->height);
		}

		if (mouse & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
			uniforms.zoom = 32 + 48*(float(my)/fb->height - 0.5);
			uniforms.xoff = 32*(float(mx)/fb->width - 0.5);
		}

		fb->clear();
		depthfb.clear(HUGE_VALF);

		uniforms.v = translate((vec3) {uniforms.xoff, 0, uniforms.zoom});
		drawBufferTriangles(vertbuf, buffers, uniforms);

		uniforms.v = translate((vec3) {uniforms.xoff+3, -2, uniforms.zoom});
		drawBufferTriangles(vertbuf, buffers, uniforms);

		/*
		for (size_t y = i&0xff; y < fb->height; y++) {
			for (size_t x = i&0xff; x < fb->width; x++) {
				uint8_t m = ((x^y) - i) & 0xff;
				//fb->setPixel(x, y, (m<<24) | (m<<20) | (m<<16) | 0xff);
				fb->setPixel(x, y, (ubvec4){0xff, m, m, m});
			}
		}
		*/

		auto end = std::chrono::high_resolution_clock::now();
		back.swapFramebuffer();
		std::chrono::duration<float> secs = end - start;

		times[timeidx++ % 8] = secs.count();

		float frametimes = 0;
		for (unsigned i = 0; i < 8; i++) {
			frametimes += times[(timeidx + i) % 8];
		}
		frametimes /= 8.f;

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

