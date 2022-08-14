#pragma once
#include <stdlib.h>
#include <initializer_list>
#include <string>
#include <iostream>
#include <type_traits>

namespace softrend {

template <bool flag = false>
void static_error() {
	static_assert(flag, "asdf");
}

#define swizzle_assert1(flag) \
	static_assert(flag, "Invalid swizzle: vector requires at least 1 component");
#define swizzle_assert2(flag) \
	static_assert(flag, "Invalid swizzle: vector requires at least 2 components");
#define swizzle_assert3(flag) \
	static_assert(flag, "Invalid swizzle: vector requires at least 3 components");
#define swizzle_assert4(flag) \
	static_assert(flag, "Invalid swizzle: vector requires at least 4 components");

template <typename T, size_t N>
struct vec {
	static constexpr size_t Components = N;
	using ComponentType = T;

	T values[N];

	vec() {
		for (size_t i = 0; i < N; i++) {
			values[i] = 0;
		}
	}

	vec(T *args) {
		for (size_t i = 0; i < N; i++) {
			values[i] = args[i];
		}
	}

	template <typename... Ts>
	vec(Ts... args) {
		if constexpr (sizeof...(Ts) == 1) {
			initAll(args...);

		} else {
			setInitializer<0>(args...);
		}
	}

	T *ptr() { return values; }

	void initAll(T value) {
		for (size_t i = 0; i < N; i++) {
			values[i] = value;
		}
	}

	template <size_t E>
	static constexpr bool isCompatibleVec(vec<T, E>& vec) {
		return true;
	}

	template <typename K>
	static constexpr bool isCompatibleVec(K& val) {
		return false;
	}

	template <size_t n, typename K, typename... Ts>
	void setInitializer(K arg, Ts... remain) {
		if constexpr (std::is_convertible<K, T>::value) {
			if constexpr (n + 1 > N) {
				static_error();
			}

			values[n] = arg;
			//values[n] = n;

			if constexpr (sizeof...(Ts) > 0) {
				setInitializer<n + 1>(remain...);
			} else if constexpr (n + 1 < N ) {
				static_error();
			}
		}

		else if constexpr (isCompatibleVec(arg)) {
			if constexpr (n + K::Components > N) {
				static_error();
			}

			for (unsigned m = 0; m < K::Components; m++) {
				values[n + m] = arg.values[m];
			}

			if constexpr (sizeof...(Ts) > 0) {
				setInitializer<n + K::Components>(remain...);
			} else if constexpr (n + K::Components < N) {
				static_error();
			}

		} else {
			static_error();
		}
	}

	// const swizzle accessors
	template <bool avail = 1 <= N>
	const T& x() const { swizzle_assert1(avail); return values[0]; };

	template <bool avail = 2 <= N>
	const T& y() const { swizzle_assert2(avail); return values[1]; };

	template <bool avail = 3 <= N>
	const T& z() const { swizzle_assert3(avail); return values[2]; };

	template <bool avail = 4 <= N>
	const T& w() const { swizzle_assert4(avail); return values[3]; };

	template <bool avail = 1 <= N>
	const T& r() const { swizzle_assert1(avail); return values[0]; };

	template <bool avail = 2 <= N>
	const T& g() const { swizzle_assert2(avail); return values[1]; };

	template <bool avail = 3 <= N>
	const T& b() const { swizzle_assert3(avail); return values[2]; };

	template <bool avail = 4 <= N>
	const T& a() const { swizzle_assert4(avail); return values[3]; };

	// regular swizzle accessors
	template <bool avail = 1 <= N>
	T& x() { swizzle_assert1(avail); return values[0]; };

	template <bool avail = 2 <= N>
	T& y() { swizzle_assert2(avail); return values[1]; };

	template <bool avail = 3 <= N>
	T& z() { swizzle_assert3(avail); return values[2]; };

	template <bool avail = 4 <= N>
	T& w() { swizzle_assert4(avail); return values[3]; };

	template <bool avail = 1 <= N>
	T& r() { swizzle_assert1(avail); return values[0]; };

	template <bool avail = 2 <= N>
	T& g() { swizzle_assert2(avail); return values[1]; };

	template <bool avail = 3 <= N>
	T& b() { swizzle_assert3(avail); return values[2]; };

	template <bool avail = 4 <= N>
	T& a() { swizzle_assert4(avail); return values[3]; };

	vec operator+() const { return vec(values); }

	vec operator-() const {
		vec ret;

		for (size_t i = 0; i < N; i++) {
			ret.values[i] = -this->values[i];
		}

		return ret;
	}

	vec operator+(const vec& other) const {
		vec ret;

		for (size_t i = 0; i < N; i++) {
			ret.values[i] = this->values[i] + other.values[i];
		}

		return ret;
	}

	vec operator-(const vec& other) const {
		vec ret;

		for (size_t i = 0; i < N; i++) {
			ret.values[i] = this->values[i] - other.values[i];
		}

		return ret;
	}

	vec operator*(const vec& other) const {
		vec ret;

		for (size_t i = 0; i < N; i++) {
			ret.values[i] = this->values[i] * other.values[i];
		}

		return ret;
	}

	vec operator/(const vec& other) const {
		vec ret;

		for (size_t i = 0; i < N; i++) {
			ret.values[i] = this->values[i] / other.values[i];
		}

		return ret;
	}

	vec& operator+=(const vec& other) {
		for (size_t i = 0; i < N; i++) {
			values[i] += other.values[i];
		}

		return *this;
	}

	vec& operator-=(const vec& other) {
		for (size_t i = 0; i < N; i++) {
			values[i] -= other.values[i];
		}

		return *this;
	}

	vec& operator*=(const vec& other) {
		for (size_t i = 0; i < N; i++) {
			values[i] *= other.values[i];
		}

		return *this;
	}

	vec& operator/=(const vec& other) {
		for (size_t i = 0; i < N; i++) {
			values[i] /= other.values[i];
		}

		return *this;
	}

	vec operator+(const T& value) {
		vec ret;

		for (size_t i = 0; i < N; i++) {
			ret.values[i] = this->values[i] + value;
		}

		return ret;
	}

	vec operator-(const T& value) {
		vec ret;

		for (size_t i = 0; i < N; i++) {
			ret.values[i] = this->values[i] - value;
		}

		return ret;
	}

	vec operator*(const T& value) {
		vec ret;

		for (size_t i = 0; i < N; i++) {
			ret.values[i] = this->values[i] * value;
		}

		return ret;
	}

	vec operator/(const T& value) {
		vec ret;

		for (size_t i = 0; i < N; i++) {
			ret.values[i] = this->values[i] / value;
		}

		return ret;
	}

	vec& operator+=(const T& value) {
		for (size_t i = 0; i < N; i++) {
			values[i] += value;
		}

		return *this;
	}

	vec& operator-=(const T& value) {
		for (size_t i = 0; i < N; i++) {
			values[i] -= value;
		}

		return *this;
	}

	vec& operator*=(const T& value) {
		for (size_t i = 0; i < N; i++) {
			values[i] *= value;
		}

		return *this;
	}

	vec& operator/=(const T& value) {
		for (size_t i = 0; i < N; i++) {
			values[i] /= value;
		}

		return *this;
	}

	T& operator[](size_t pos) {
		return values[pos];
	}

	const T& operator[](size_t pos) const {
		return values[pos];
	}

	constexpr operator std::string () const {
		std::string ret = "[";

		for (size_t i = 0; i < N; i++) {
			ret += std::to_string(values[i]);
			if (i + 1 < N)
				ret += ", ";
		}

		ret += "]";
		return ret;
	}

    #include <softrend/math/swizzles.hpp>
};

template <typename T, size_t N>
vec<T, N> operator+(const T& value, const vec<T, N>& v) {
	vec<T, N> ret;

	for (size_t i = 0; i < N; i++) {
		ret.values[i] = v.values[i] + value;
	}

	return ret;
}

template <typename T, size_t N>
vec<T, N> operator-(const T& value, const vec<T, N>& v) {
	vec<T, N> ret;

	for (size_t i = 0; i < N; i++) {
		ret.values[i] = v.values[i] - value;
	}

	return ret;
}

template <typename T, size_t N>
vec<T, N> operator*(const T& value, const vec<T, N>& v) {
	vec<T, N> ret;

	for (size_t i = 0; i < N; i++) {
		ret.values[i] = v.values[i] * value;
	}

	return ret;
}

template <typename T, size_t N>
vec<T, N> operator/(const T& value, const vec<T, N>& v) {
	vec<T, N> ret;

	for (size_t i = 0; i < N; i++) {
		ret.values[i] = v.values[i] / value;
	}

	return ret;
}

template <typename T, size_t N>
T dot(const vec<T, N>& a, const vec<T, N>& b) {
	T sum = 0;

	for (size_t i = 0; i < N; i++) {
		sum += a.values[i] * b.values[i];
	}

	return sum;
}

// namespace softrend
}
