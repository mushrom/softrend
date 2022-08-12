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
			std::cout << "C: setting " << i << ": " << value << std::endl;
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

			std::cout << "A: setting " << n << ": " << arg << std::endl;
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
				std::cout << "B: setting " << n+m << ": " << arg.values[m] << std::endl;
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

	template <bool avail = 1 <= N>
	constexpr T& x() {
		static_assert(avail, "invalid swizzle (requires 1+ components)");
		return values[0];
	};

	template <bool avail = 2 <= N>
	constexpr T& y() {
		static_assert(avail, "invalid swizzle (requires 2+ components)");
		return values[1];
	};

	template <bool avail = 3 <= N>
	constexpr T& z() {
		static_assert(avail, "invalid swizzle (requires 3+ components)");
		return values[2];
	};

	template <bool avail = 4 <= N>
	constexpr T& w() {
		static_assert(avail, "invalid swizzle (requires 4+ components)");
		return values[3];
	};

	template <bool avail = 1 <= N>
	constexpr T& r() {
		static_assert(avail, "invalid swizzle (requires 1+ components)");
		return values[0];
	};

	template <bool avail = 2 <= N>
	constexpr T& g() {
		static_assert(avail, "invalid swizzle (requires 2+ components)");
		return values[1];
	};

	template <bool avail = 3 <= N>
	constexpr T& b() {
		static_assert(avail, "invalid swizzle (requires 3+ components)");
		return values[2];
	};

	template <bool avail = 4 <= N>
	constexpr T& a() {
		static_assert(avail, "invalid swizzle (requires 4+ components)");
		return values[3];
	};

	T operator+() const { return *this; }
	T operator-() const {}

	constexpr operator std::string () {
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

// namespace softrend
}
