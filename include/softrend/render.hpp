#pragma once
#include <stdint.h>
#include <array>

// generic types for all render implementations, vertex attributes, uniforms,
// render context etc. aren't included here because they're expected to be
// customized

namespace softrend {

enum drawFlags {
	DepthTest      = (1 << 0),
	DepthMask      = (1 << 1),
	CullFrontFaces = (1 << 2),
	CullBackFaces  = (1 << 3),
	SortGeometry   = (1 << 4),
};

struct screenRect {
	int xbegin;
	int ybegin;
	int xend;
	int yend;
};

using Coord = std::pair<int, int>;
using Tri = std::array<Coord, 3>;

// either uint8_t or float
template <typename T>
class framebuffer {
	public:
		framebuffer() {};

		framebuffer(T* _data, size_t _width, size_t _height, size_t _pitch)
			: data(_data), width(_width), height(_height), pitch(_pitch) { }

		framebuffer(size_t _width, size_t _height, size_t _pitch)
			: width(_width), height(_height), pitch(_pitch)
		{
			// TODO: free
			data = new T[pitch*height];
		}

		T *data;
		size_t width;
		size_t height;
		size_t pitch;

		inline void setPixel(size_t x, size_t y, T value) {
			// TODO: bounds checking
			data[y*pitch + x] = value;
		}

		inline T getPixel(size_t x, size_t y) const {
			return data[y*pitch + x];
		}

		inline void clear(T val = 0) {
			size_t n = height*pitch;

			for (size_t i = 0; i < n; i++) {
				data[i] = val;
			}
		}
};

template <typename T, typename F>
struct fbPair {
	fbPair(framebuffer<T> *c, framebuffer<F> *d)
		: color(c), depth(d) {};

	framebuffer<T> *color = nullptr;
	framebuffer<F> *depth = nullptr;
};

// namespace softrend
}
