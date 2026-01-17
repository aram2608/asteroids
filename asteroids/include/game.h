#ifndef GAME_H_
#define GAME_H_

#include "raylib.h"
#include "ship.h"
#include "laser.h"
#include "asteroid.h"

#define ASTEROID_CAP 20

typedef struct {
  size_t asteroid_count;
  Asteroid* asteroids;
  Laser* lasers;
  Ship* ship;
} Game;

Game* NewGame(int window_width, int window_heigh);
void UpdateGame(Game* game);
void DrawGame(Game* game);
void SpawnAsteroid(Game* game);
void FireLaser(Game* game);
void DestroyGame(Game* game);

#endif