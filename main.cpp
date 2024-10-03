#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <vector>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>


#include "config.hpp"
#include "Obstacle.h"
#include "Boid.h"
#include "util.h"

using namespace std;

Texture2D fishTex;

Vector2 mouse{0,0};
float mouseZ = 0;

vector<Obstacle*> obstacles;
vector<Boid*> boids;

void createObstacles() {
    for (int i = 0; i < OBSTACLES_COUNT; i++) {
        obstacles.push_back(new Obstacle(randf() * float(W), randf() * float(H)));
    }
}

void createBoids() {
    for (int i = 0; i < BOIDS_COUNT; i++) {
        Vector2 pos{ randf() * float(W), randf() * float(H) };
        Vector2 vel{ 0, 0 };
        int group = i % GROUPS_COUNT;
        auto boid = new Boid(pos, vel, group, fishTex);
        float bias = float(i) / float(BOIDS_COUNT);
        boid->hp = lerp(.8, 1.2, bias);
        boids.push_back(boid);
    }
}

void restart () {
    boids.clear();
    obstacles.clear();

    createObstacles();
    createBoids();
}

class ChangeChecker {
public:
    bool state = false;

    bool check(bool nowState) {
        bool trigger = !state && nowState;
        state = nowState;
        return trigger;
    }
};

auto drawAliveAndClearDead = !DEBUG_PERF ? [](Boid* boid) {
    if (boid->isAlive)
        boid->draw();
    return !boid->isAlive;
} : [](Boid* boid) {
    boid->draw();
    return false;
};

int main() {
    ChangeChecker KEY_P_pressed;
    bool pause = false;
    
    InitWindow(W, H, "AI1-weird_fishes");
    SetTargetFPS(60);

    fishTex = LoadTexture("resources/WhiteFish.png");
    restart();
 
    while (!WindowShouldClose()) {
        if (KEY_P_pressed.check(IsKeyPressed(KEY_P)))
            pause = !pause;
        
        BeginDrawing();
        if (pause) {
            DrawText(TextFormat("PAUSED"), 20, H - 100, 100, WHITE);
            EndDrawing();
            continue;
        }
        
        ClearBackground(BACKGROUND_COLOR);

        mouse = GetMousePosition();
        mouseZ = (IsMouseButtonDown(0) ? 1 : IsMouseButtonDown(1) ? -1 : 0) * 1.;

        for (auto obstacle : obstacles) {
            obstacle->draw();
        }

        double beforeCalc = GetTime();
        for (auto boid: boids) {
            boid->update(boids, obstacles, mouse, mouseZ);
        }
        double afterCalc = GetTime();

        // clear killed and draw
        boids.erase(
            remove_if(boids.begin(), boids.end(),
                drawAliveAndClearDead),
            boids.end()
        );
        double afterDraw = GetTime();

        if (DEBUG_PERF)
            cout << "T: " << afterCalc - beforeCalc << " : " << afterDraw - afterCalc << "\n";

        // draw scores
        int groupWidth = W / 3;
        for (int i = 0; i < GROUPS_COUNT; i++) 
            DrawText(TextFormat("%i", Boid::scores[i]), groupWidth * (i + .5), 80, 60, COLORS[i]);
        // DrawText(TextFormat("%i", GetFPS()), 20, 20, 20, WHITE);
        
        // restart
        if (boids.size() < 8)
            restart();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}