#pragma once

#include <softrend/math/typedefs.hpp>
#include <cmath>

namespace softrend {

mat4 perspective(float fovy, float aspect, float near, float far) {
	float angle = fovy;
	float scale = tan(angle * 0.5) * near;
	//float scale = tan(angle * 0.5 * M_PI / 180) * near;
	float r = aspect * scale;
	float l = -r;

	float t = scale;
	float b = -t;
	float n = near;
	float f = far;

	return mat4(
		2*n / (r - l), 0.f, 0.f, 0.f,
		0.f, (2*n)/(t-b), 0.f, 0.f,
		(r + l) / (r - l), (t + b) / (t - b), -(f + n) / (f - n), -1.f,
		0.f, 0.f, -2*f*n / (f - n), 0.f
	);

#if 0
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

	return mat4(
		uw, 0.f, 0.f, 0.f,
		0.f,  uh, 0.f, 0.f,
		0.f, 0.f, far/(near - far), -(far*near)/(far - near),
		0.f, 0.f, 1.f, 0.f
	);

	/*
	// column-major
	return (mat4) {
		uw, 0, 0, 0,
		0,  uh, 0, 0,
		0, 0, far/fdepth, -(far*near)/fdepth,
		0, 0, 1, 0,
	};
	*/
#endif
}

mat4 rotateX(float amount) {
	return mat4(
		/*
		1, 0, 0, 0,
		0, cos(amount), -sin(amount), 0,
		0, sin(amount), cos(amount), 0,
		0, 0, 0, 1,
		*/

		1.f, 0.f, 0.f, 0.f,
		0.f,  cosf(amount), sinf(amount), 0.f,
		0.f, -sinf(amount), cosf(amount), 0.f,
		0.f, 0.f, 0.f, 1.f
	);
}

mat4 rotateY(float amount) {
	return mat4(
		cosf(amount), 0.f, -sinf(amount), 0.f,
		0.f, 1.f, 0.f, 0.f,
		sinf(amount), 0.f,  cosf(amount), 0.f,
		0.f, 0.f, 0.f, 1.f
	);
}

mat4 rotateZ(float amount) {
	return mat4(
		cosf(amount), sinf(amount), 0.f, 0.f,
		-sinf(amount), cosf(amount), 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f
	);
}

mat4 translate(const vec3& T) {
	// column-major
	return mat4(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		T[0], T[1], T[2], 1.f
	);
}


mat4 lookAt(const vec3& focus, const vec3& position) {
	// TODO:
	return mat4();
}

// namespace softrend
}
