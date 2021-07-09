#pragma once
#include <stdint.h>
#include <math.h>

namespace softrend {

typedef float v2sf __attribute__((vector_size (8)));
typedef float v4sf __attribute__((vector_size (16)));
typedef v4sf v3sf;
typedef float v8sf __attribute__((vector_size (32)));
typedef float v16sf __attribute__((vector_size (64)));
// TODO: doubles

typedef uint32_t v2su __attribute__((vector_size (8)));
typedef uint32_t v4su __attribute__((vector_size (16)));
typedef v4su v3su;
typedef uint32_t v8su __attribute__((vector_size (32)));

typedef int32_t v2si __attribute__((vector_size (8)));
typedef int32_t v4si __attribute__((vector_size (16)));
typedef v4si v3si;
typedef int32_t v8si __attribute__((vector_size (32)));

typedef uint8_t v4ub __attribute__((vector_size (4)));
typedef uint8_t v8ub __attribute__((vector_size (8)));
typedef uint8_t v16ub __attribute__((vector_size (16)));
typedef v16ub v12ub;
typedef uint8_t v32ub __attribute__((vector_size (32)));

// mapping to neat glsl-ish types
typedef v2sf vec2;
typedef v3sf vec3;
typedef v4sf vec4;
typedef vec4 quat; // glm-like quaternion

typedef v16sf mat4;
typedef mat4  mat3;
typedef v4sf  mat2;

typedef v2su uvec2;
typedef v3su uvec3;
typedef v4su uvec4;

typedef v4ub ubvec4;
typedef v8ub ubvec8;
typedef v16ub ubvec16;
typedef v32ub ubvec32;

typedef v2si ivec2;
typedef v3si ivec3;
typedef v4si ivec4;

static inline vec4 mult(const mat4& mat, const vec4& v) {
	vec4 ret = {0.f, 0.f, 0.f, 0.f};

	for (int i = 0; i < 4; i++) {
		// column major offsets
		vec4 temp = (vec4) { mat[i], mat[4+i], mat[8+i], mat[12+i] };
		
		vec4 foo = temp*v;
		ret[i] = foo[0] + foo[1] + foo[2] + foo[3];
		//ret[ += foo;
		//ret[i] = temp*v;
	}

	return ret;
}

static inline mat4 mult(const vec4& v, const mat4& mat) {
	// TODO
	return mat;
}

static inline mat4 mult(const mat4& a, const mat4& b) {
	mat4 ret;

	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			vec4 arow = (vec4) { a[i], a[4+i], a[8+i], a[12+i] };
			vec4 bcol = (vec4) { b[4*k], a[4*k+1], a[4*k+2], a[4*k+3] };

			vec4 asdf = arow*bcol;
			//ret[i*4 + k] = asdf[0] + asdf[1] + asdf[2] + asdf[3];
			ret[k*4 + i] = asdf[0] + asdf[1] + asdf[2] + asdf[3];
		}
	}

	return ret;
}

static inline float dot(const vec4& a, const vec4& b) {
	//return a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
	vec4 temp = a*b;
	return temp[0]+temp[1]+temp[2]+temp[3];
}

static inline mat4 identity_mat4(void) {
	return (mat4){
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1,
	};
}

static inline mat4 perspective(float fovy, float aspect, float near, float far) {
	float fdepth     = far - near;
	float inv_fdepth = 1 / fdepth;

	float uw = 1.f / (aspect * tan(fovy/2));
	float uh = 1.f / tan(fovy/2);

	/*
	return (mat4){
		uw, 0, 0, 0,
		0,  uh, 0, 0,
		0, 0, far/fdepth, 1,
		0, 0, (-far*near)/fdepth, 0,
	};
	*/

	/*
	return (mat4){
		uw, 0, 0, 0,
		0,  uh, 0, 0,
		0, 0, far/(near - far), 1,
		0, 0, -(far*near)/(far - near), 0,
	};
	*/

	return (mat4){
		uw, 0, 0, 0,
		0,  uh, 0, 0,
		0, 0, far/(near - far), -(far*near)/(far - near),
		0, 0, 1, 0,
	};

	/*
	// column-major
	return (mat4) {
		uw, 0, 0, 0,
		0,  uh, 0, 0,
		0, 0, far/fdepth, -(far*near)/fdepth,
		0, 0, 1, 0,
	};
	*/

}

static inline mat4 translate(const vec3& T) {
	// column-major
	return (mat4) {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		T[0], T[1], T[2], 1,
	};

	/*
	return (mat4) {
		0, 0, 0, T[0],
		0, 0, 0, T[1],
		0, 0, 0, T[2],
		0, 0, 0, 1,
	};
	*/
}

static inline mat4 rotateX(float amount) {
	return (mat4) {
		/*
		1, 0, 0, 0,
		0, cos(amount), -sin(amount), 0,
		0, sin(amount), cos(amount), 0,
		0, 0, 0, 1,
		*/

		1, 0, 0, 0,
		0,  cos(amount), sin(amount), 0,
		0, -sin(amount), cos(amount), 0,
		0, 0, 0, 1,
	};
}

static inline mat4 rotateY(float amount) {
	return (mat4){
		cos(amount), 0, -sin(amount), 0,
		0, 1, 0, 0,
		sin(amount), 0,  cos(amount), 0,
		0, 0, 0, 1,
	};
}

static inline mat4 rotateZ(float amount) {
	return (mat4){
		cos(amount),  sin(amount), 0, 0,
		-sin(amount), cos(amount), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1,
	};
}

static inline mat4 lookAt(const vec3& focus, const vec3& position) {
	// TODO:
	return identity_mat4();
}

template <typename T>
static inline T min(T a, T b) {
	return (a < b)? a : b;
}

template <typename T>
static inline T max(T a, T b) {
	return (a >= b)? a : b;
}

template <typename T>
static inline T clamp(T val, T minval, T maxval) {
	return max(minval, min(maxval, val));
}

template <typename T>
static inline T mix(T a, T b, float amount) {
	float c = clamp(amount, 0.f, 1.f);
	return (1.f - c)*a + c*b;
}

// namespace softrend
}
