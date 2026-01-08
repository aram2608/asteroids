#ifndef SHIP_H_
#define SHIP_H_

#include "raylib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    Vector2 vel;
    Vector2 pos;
    Vector2 origin;
    Color color;
    float height;
    float width;
    float rotation;
} Ship;

Ship* NewShip(int window_width, int window_height);

Rectangle GetShipRectangle(Ship* ship);

void UpdateShip(Ship* ship);

void DrawShip(Ship* ship);

void DestroyShip(Ship* ship);

#endif