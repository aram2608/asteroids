#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "raylib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct Asteroid Asteroid;

struct Asteroid {
  Vector2 vel;
  Vector2 pos;
  float speed;
  float rotation;
  Asteroid* next;
};

void UpdateAsteroid(Asteroid* asteroid);
void DrawAsteroid(Asteroid* asteroid);

#endif