#pragma once
#include <stdlib.h>
#include <array>
#include <string>
#include <iostream>
#include <type_traits>

#include <softrend/math/vec.hpp>

namespace softrend {

template <typename T, size_t ROW, size_t COL>
struct mat {
	static constexpr size_t Rows    = ROW;
	static constexpr size_t Columns = COL;
	using ComponentType = T;
	using VecType = vec<T, ROW>;

	// column-major
	//VecType values[COL];
	std::array<VecType, COL> values;

	mat() {
		// initialize to an identity matrix, assuming a square matrix
		// TODO: figure out if this is the best thing to do
		for (size_t c = 0; c < COL; c++) {
			for (size_t r = 0; r < ROW; r++) {
				values[c][r] = c == r;
			}
		}
	}

	template <typename... Args>
	mat(Args... args) {
		initialize(std::array {args...});
	}

	template <typename K>
	void initialize(const std::array<K, 1>& args) {
		static_assert(std::is_convertible<K, T>::value,
				      "Initializer value cannot be converted to matrix value");

		const K& value = args[0];

		// initialize to a scaling matrix
		for (size_t c = 0; c < COL; c++) {
			for (size_t r = 0; r < ROW; r++) {
				values[c][r] = (c == r)? value : T();
			}
		}
	}

	template <typename K>
	void initialize(const std::array<K, ROW*COL>& args) {
		static_assert(std::is_convertible<K, T>::value,
				      "Initializer value cannot be converted to matrix value");

		const K& value = args[0];

		// initialize to a scaling matrix
		for (size_t c = 0; c < COL; c++) {
			for (size_t r = 0; r < ROW; r++) {
				values[c][r] = args[c*COL + r];
			}
		}
	}

	void initialize(const std::array<VecType, COL>& args) {
		for (size_t i = 0; i < COL; i++) {
			values[i] = args[i];
		}
	}

	mat operator+() const { return *this; } 
	mat operator-() const {
		mat ret;

		for (size_t c = 0; c < COL; c++) {
			ret.values[c] = -this->values[c];
		}

		return ret;
	}

	mat operator+(const mat& other) {
		mat ret;

		for (size_t c = 0; c < COL; c++) {
			ret.values[c] = this->values[c] + other.values[c];
		}

		return ret;
	}

	mat operator/(const mat& other) {
		mat ret;

		for (size_t c = 0; c < COL; c++) {
			ret.values[c] = this->values[c] + other.values[c];
		}

		return ret;
	}

	template <size_t R>
	VecType operator*(const vec<T, R>& v) {
		static_assert(R == COL, "Incompatible matrices");

		VecType ret;

		for (size_t r = 0; r < R; r++) {
			ret += values[r] * v[r];
		}

		return ret;
	}

	template <size_t OROW, size_t OCOL>
	mat<T, ROW, OCOL> operator*(const mat<T, OROW, OCOL>& other) {
		static_assert(OROW == COL, "Incompatible matrices");
		mat<T, ROW, OCOL> ret;

		for (size_t i = 0; i < OCOL; i++) {
			ret.values[i] = *this * other.values[i];
		}

		return ret;
	}

	const VecType& operator[](size_t pos) const {
		return values[pos];
	}

	constexpr operator std::string () {
		std::string ret = "[";

		for (size_t i = 0; i < COL; i++) {
			ret += std::string(values[i]);
			if (i + 1 < COL)
				ret += ", ";
		}

		ret += "]";
		return ret;
	}

};

// namespace softrend
}
