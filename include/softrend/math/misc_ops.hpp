#pragma once


namespace softrend {

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
