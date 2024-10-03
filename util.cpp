#include "util.h"

#include <random>
#include <iostream>

#include "raylib.h"
#include "raymath.h"

Vector2 operator+(const Vector2& a, const Vector2& b) {
    return Vector2Add(a, b);
}
Vector2 operator+=(Vector2& a, const Vector2& b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}
Vector2 operator-(const Vector2& a, const Vector2& b) {
    return Vector2Subtract(a, b);
}
Vector2 operator*=(Vector2& a, const float i) {
    a.x *= i;
    a.y *= i;
    return a;
    //return Vector2Multiply(a, Vector2{ i,i });
}
Vector2 operator*(const Vector2& a, const float i) {
    return Vector2Multiply(a, Vector2{ i,i });
}
Vector2 operator/(const Vector2& a, const float i) {
    return Vector2Divide(a, Vector2{ i,i });
}

// float MYlerp (float a, float b, float t) { return a + t * (b - a); }

float randf() { return (float)rand() / (RAND_MAX); }
float randf(float min, float max) { return randf() * (max - min) + min; }

void logVec2(const char* str, Vector2 v2) {
    std::cout << str << " - " << v2.x << ":" << v2.y << "\n";
}
