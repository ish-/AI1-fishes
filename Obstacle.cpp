#include "Obstacle.h"
#include <algorithm>

Obstacle::Obstacle(float x, float y, float _size) {
    size = _size;
    pos = Vector2{ x, y };
    boundingRect = Rectangle{ pos.x - margin, pos.y - margin, size + margin * 2, size + margin * 2 };
}

void Obstacle::draw() {
    DrawRectangleLines(pos.x, pos.y, size, size, touched ? YELLOW : GRAY);
    Color fill = YELLOW;
    fill.a = touched;
    DrawRectangle(pos.x, pos.y, size, size, fill);

    touched = std::max(0., touched - 255. / 60.);
}