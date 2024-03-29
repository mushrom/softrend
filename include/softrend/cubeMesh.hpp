#pragma once
// TODO: should probably split vector typedefs from math functions
#include <softrend/math/math.hpp>

namespace softrend {

static const vec3 cube_vertices[] = {
	// front
	{-1.0, -1.0,  1.0},
	{ 1.0, -1.0,  1.0},
	{ 1.0,  1.0,  1.0},
	{-1.0,  1.0,  1.0},
	// top
	{-1.0,  1.0,  1.0},
	{ 1.0,  1.0,  1.0},
	{ 1.0,  1.0, -1.0},
	{-1.0,  1.0, -1.0},
	// back
	{ 1.0, -1.0, -1.0},
	{-1.0, -1.0, -1.0},
	{-1.0,  1.0, -1.0},
	{ 1.0,  1.0, -1.0},
	// bottom
	{-1.0, -1.0, -1.0},
	{ 1.0, -1.0, -1.0},
	{ 1.0, -1.0,  1.0},
	{-1.0, -1.0,  1.0},
	// left
	{-1.0, -1.0, -1.0},
	{-1.0, -1.0,  1.0},
	{-1.0,  1.0,  1.0},
	{-1.0,  1.0, -1.0},
	// right
	{ 1.0, -1.0,  1.0},
	{ 1.0, -1.0, -1.0},
	{ 1.0,  1.0, -1.0},
	{ 1.0,  1.0,  1.0},
};

static const vec3 cube_normals[] = {
	// front
	{0, 0, 1},
	{0, 0, 1},
	{0, 0, 1},
	{0, 0, 1},
	// top
	{0, 1, 0},
	{0, 1, 0},
	{0, 1, 0},
	{0, 1, 0},
	// back
	{0, 0, -1},
	{0, 0, -1},
	{0, 0, -1},
	{0, 0, -1},
	// bottom
	{0, -1, 0},
	{0, -1, 0},
	{0, -1, 0},
	{0, -1, 0},
	// left
	{-1, 0, 0},
	{-1, 0, 0},
	{-1, 0, 0},
	{-1, 0, 0},
	// right
	{1, 0, 0},
	{1, 0, 0},
	{1, 0, 0},
	{1, 0, 0},
};


static const uint32_t cube_elements[] = {
	// front
	0,  1,  2,
	2,  3,  0,
	// top
	4,  5,  6,
	6,  7,  4,
	// back
	8,  9, 10,
	10, 11,  8,
	// bottom
	12, 13, 14,
	14, 15, 12,
	// left
	16, 17, 18,
	18, 19, 16,
	// right
	20, 21, 22,
	22, 23, 20,
};

static const vec2 cube_texcoords[] = {
	{0.0, 0.0},
	{1.0, 0.0},
	{1.0, 1.0},
	{0.0, 1.0},

	{0.0, 0.0},
	{1.0, 0.0},
	{1.0, 1.0},
	{0.0, 1.0},

	{0.0, 0.0},
	{1.0, 0.0},
	{1.0, 1.0},
	{0.0, 1.0},

	{0.0, 0.0},
	{1.0, 0.0},
	{1.0, 1.0},
	{0.0, 1.0},

	{0.0, 0.0},
	{1.0, 0.0},
	{1.0, 1.0},
	{0.0, 1.0},

	{0.0, 0.0},
	{1.0, 0.0},
	{1.0, 1.0},
	{0.0, 1.0},
};

static const float colors[] = {
	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	1, 1, 1,

	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	1, 1, 1,

	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	1, 1, 1,

	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	1, 1, 1,

	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	1, 1, 1,

	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	1, 1, 1,
};


// namespace softrend
}
