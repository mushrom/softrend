#pragma once
#include <SDL.h>
#include <SDL_surface.h>
#include <softrend/render.hpp>
#include <softrend/math.hpp>
#include <exception>
#include <stdexcept>

namespace softrend {

class sdl2_backend {
	public:
		sdl2_backend(size_t width = 800, size_t height = 480) {
			window = SDL_CreateWindow("softrend",
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					width, height, 0);

			if (window == nullptr) {
				throw std::logic_error("couldn't create window");
			}

			//renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			//renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
			//renderer = SDL_CreateRenderer(window, -1, 0);
			//surface = SDL_CreateRGBSurfaceWithFormat(0, width, height,
			//		32, SDL_PIXELFORMAT_RGBA8888);

			surface = SDL_GetWindowSurface(window);
			// TODO: check surface format and pitch, need 32 bit rgb
			renderer = SDL_CreateSoftwareRenderer(surface);
			SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);
			SDL_RenderClear(renderer);

			fb.data = (uint32_t*)surface->pixels;
			fb.width = width;
			fb.height = height;
			fb.pitch = surface->pitch/4;
		}

		SDL_Window *window;
		SDL_Surface *surface;
		SDL_Renderer *renderer;

		framebuffer<uint32_t> fb;

		// TODO: vector type
		framebuffer<uint32_t> *getFramebuffer(void) {
			return &fb;
		}

		void swapFramebuffer(void) {
			//SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surface);
			//SDL_RenderCopy(renderer, tex, NULL, NULL);
			//SDL_RenderPresent(renderer);
			//SDL_DestroyTexture(tex);

			// rendering to the window surface is an order of magnitude faster :O
			// not too surprising I suppose
			SDL_UpdateWindowSurface(window);
		}
};

// namespace softrend
}
