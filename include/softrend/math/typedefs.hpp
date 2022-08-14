#pragma once
#include <stdlib.h>
#include <array>
#include <string>
#include <iostream>
#include <type_traits>

#include <softrend/math/vec.hpp>
#include <softrend/math/mat.hpp>

namespace softrend {

using vec2 = vec<float, 2>;
using vec3 = vec<float, 3>;
using vec4 = vec<float, 4>;

using mat2   = mat<float, 2, 2>;
using mat3   = mat<float, 3, 3>;
using mat4   = mat<float, 4, 4>;

// glsl uses column x row in their type names, which is bit strange tbh
using mat2x2 = mat<float, 2, 2>;
using mat2x3 = mat<float, 2, 3>;
using mat3x2 = mat<float, 3, 2>;
using mat3x3 = mat<float, 3, 3>;
using mat3x4 = mat<float, 3, 4>;
using mat4x3 = mat<float, 4, 3>;
using mat4x4 = mat<float, 4, 4>;

// namespace softrend
}
