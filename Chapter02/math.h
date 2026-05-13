#pragma once

namespace Math
{
const float Pi = 3.1415926535f;

inline float ToRadians(float degrees) { return degrees * Pi / 180.0f; }
inline float ToDegrees(float radians) { return radians * 180.0f / Pi; }
} // namespace Math

struct Vector2
{
	float x;
	float y;
};