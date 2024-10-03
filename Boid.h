#pragma once

#include <vector>
#include "raylib.h"
#include "Obstacle.h"

using namespace std;
class Boid;

struct BoidClosest {
    float dist;
    Boid* boid;
};

class Boid {
public:
    Vector2 vel{ 0,0 };
    Vector2 pos{ 0,0 };
    Vector2 acc{ 0,0 };
    float size = 4.;
    float hp = 1.;
    int group = 0;
    static vector<int> scores;
    bool isAlive = true;
    Color color = WHITE;
    BoidClosest closestBoid;

    Texture2D tex;
    Rectangle texRect;

    Boid(Vector2 _pos, Vector2 _vel, int _group, Texture2D _tex);
    
    void updateClosest(Boid* boid, float& dist, Vector2& dir);

    Vector2 followClosest() const;

    void kill(Boid* victim);

    Vector2 separate(Boid* boid, float& dist, Vector2& dir) const;

    Vector2 align(Boid* boid, float& dist, Vector2& dir) const;

    Vector2 seek(Vector2& p, float& dir) const;

    void checkBoudariesAndReflect();

    void __update();

    Vector2 avoid(Obstacle* obstacle) const;

    void update(
        vector<Boid*> boids,
        vector<Obstacle*> obstacles,
        Vector2& mouse,
        float& mouseZ
    );

    void draw() const;
};