#pragma once
#include <stdint.h>

namespace softrend {

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

		inline void clear(void) {
			size_t n = height*pitch;

			for (size_t i = 0; i < n; i++) {
				data[i] = T(0xff);
			}
		}
};

// namespace softrend
}
