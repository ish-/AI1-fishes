#pragma once
#include <string>
#include "raylib.h"

using namespace std;

static const int W = 1920;
static const int H = 1080;
static const Color BACKGROUND_COLOR = BLACK;
static const bool DEBUG_PERF = false;

static const int BOIDS_COUNT = 600;
static const int GROUPS_COUNT = 3;
static const int OBSTACLES_COUNT = 10;

static const float MAX_SPEED = 5.;
static const float HIT_HP = .41;

static const float SEPARATE_DIST = 15.;
static const float ALIGN_DIST = 170.;
static const float FOLLOW_DIST = 200.;

static const float SEPARATE_MULT = 1.;
static const float OBSTACLE_AVOID_MULT = 10.;
static const float ALIGN_MULT = .3;
static const float FOLLOW_MULT = .8;
static const float SEEK_MULT = 5.;
static const float ALL_INFL_MULT = .2;

static const float OBSTACLE_AVOID_DIST = 30.;

static const Color COLORS[] = { WHITE, PINK, GREEN, BLUE };
static const Color OBSTACLE_COLOR = YELLOW;


