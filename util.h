#pragma once

#include "raylib.h"
#include "raymath.h"

inline Vector2 operator+(const Vector2& a, const Vector2& b);
inline Vector2 operator+=(Vector2& a, const Vector2& b);
inline Vector2 operator-(const Vector2& a, const Vector2& b);
inline Vector2 operator*=(Vector2& a, const float i);
inline Vector2 operator*(const Vector2& a, const float i);
inline Vector2 operator/(const Vector2& a, const float i);

inline void logVec2(const char* str, Vector2 v2);

// inline float MYlerp(float a, float b, float t);
inline float lerp (float a, float b, float t) { return a + t * (b - a); }

inline float randf();
inline float randf(float min, float max);

// template<typename T>
