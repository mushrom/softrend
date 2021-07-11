#pragma once
#include <softrend/math.hpp>
#include <vector>

namespace softrend {

struct vertex_buffer {
	std::vector<vec3> vertices;
	std::vector<vec3> normals;
	std::vector<vec2> uvs;
	std::vector<uint32_t> elements;
};

struct vertexOut {
	Coord screenpos;
	vec3 position;
	vec3 normal;
	vec2 uv;
	float depth;
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


// namespace softrend
}
