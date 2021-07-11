#include <softrend/backend/sdl.hpp>
#include <softrend/render.hpp>
#include <softrend/jobQueue.hpp>
#include <softrend/cubeMesh.hpp>
#include <softrend/attributes.hpp>
#include <softrend/shader.hpp>

#include <softrend/renderContext.hpp>
#include <softrend/renderImpl.hpp>

#include <chrono>
#include <vector>
#include <array>
#include <algorithm> // sort
#include <list>

using namespace softrend;

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

int main(void) {
	__builtin_cpu_init();

#if 0
	// TODO: platform checks, hotpaths for different feature support...?
	if (!__builtin_cpu_supports("avx")) {
		puts("wut");
		return 1;
	}
#endif

	SDL_Init(SDL_INIT_VIDEO);
	sdl2_backend back(1280, 720);
	jobQueue jobs(std::thread::hardware_concurrency());

	auto fb = back.getFramebuffer();
	framebuffer<float> depthfb(fb->width, fb->height, fb->pitch);
	renderContext<vertexOut, shadingUniforms, textureShader> ctx(jobs, fb, &depthfb);

	vertex_buffer vertbuf;
	for (auto& em : cube_vertices) { vertbuf.vertices.push_back(em); }
	for (auto& em : cube_normals) { vertbuf.normals.push_back(em); }
	for (auto& em : cube_elements) { vertbuf.elements.push_back(em); }
	for (auto& em : cube_texcoords) { vertbuf.uvs.push_back(em); }

	printf("\n");
	float times[8];
	unsigned timeidx;

	shadingUniforms uniforms;
	uniforms.p = perspective(M_PI/2.f, 16.f/9.f, 0.1f, 100.f);
	uniforms.rotx = identity_mat4();
	uniforms.roty = identity_mat4();
	uniforms.zoom = 64;
	uniforms.xoff = 0.f;
	uniforms.cameraPos = (vec3) {0, 0, 0};

	mat4 cameraRot = identity_mat4();
	int flags
		= DepthTest
		| DepthMask
		| CullBackFaces
		| SortGeometry;

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

		uniforms.v = mult(translate(-uniforms.cameraPos), cameraRot);
		//uniforms.v = translate(-uniforms.cameraPos);

		uniforms.m = translate((vec3) {uniforms.xoff, 0, uniforms.zoom});
		drawBufferTriangles(ctx, vertbuf, uniforms, flags);

#if 1
		time_t foo = time(NULL);
		uint64_t j = 0;
		for (int kz = 0; kz < 64; kz += 16) {
			for (int kx = -8; kx < 8; kx += 4) {
				for (int ky = -8; ky < 8; ky += 4) {
					//if (foo&(1ULL << j)) { // uncomment for binary clock lol
						uniforms.m = translate((vec3) {
							uniforms.xoff + kx,
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

