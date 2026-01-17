#ifndef LASER_H_
#define LASER_H_

#include "raylib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct Laser Laser;

struct Laser {
  Vector2 vel;
  Vector2 pos;
  float speed;
  float rotation;
  Laser* next;
};

void UpdateLaser(Laser* laser);
void DrawLaser(Laser* laser);

#endif