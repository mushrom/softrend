#pragma once
#include <softrend/math/math.hpp>
#include <softrend/brick.h>

namespace softrend {

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
		temp = uniforms.p
		     * uniforms.v
		     * uniforms.m
		     * uniforms.rotx 
		     * uniforms.roty 
		     * temp;

		vec4 adj = ((temp/temp[3])*0.5f + 0.5f);

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

/*
// TODO: Need to figure out how to do this
template <template <typename T, typename U, typename F> typename S>
concept Shader = requires(S<T, U, F> a) {
	S<T, U, F>::vertexShader;
	S<T, U, F>::fragmentShader;
};
*/

// namespace softrend
}
