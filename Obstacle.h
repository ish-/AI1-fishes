#pragma once
#include "raylib.h"

class Obstacle {
public:
    Vector2 pos{ 0,0 };
    float size = 100.;
    float margin = 10.;
    Rectangle boundingRect;
    float touched = 0.;

    Obstacle(float x, float y, float _size = 100.);

    void draw();
};