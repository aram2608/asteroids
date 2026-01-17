#include "../include/game.h"

Game* NewGame(int window_width, int window_heigh) {
  Game* game = (Game*)malloc(sizeof(Game));
  if (game == NULL) {
    printf("ERROR: Failed to start game");
    exit(1);
  }
  game->ship = NewShip(window_width, window_heigh);

  game->lasers = (Laser*)malloc(sizeof(Laser));
  game->lasers->next = NULL;

  game->asteroids = (Asteroid*)malloc(sizeof(Asteroid));
  game->asteroids->next = NULL;
  game->asteroid_count = 0;
  return game;
}

void UpdateGame(Game* game) {
  SpawnAsteroid(game);
  UpdateShip(game->ship);
  if (IsKeyPressed(KEY_SPACE)) {
    FireLaser(game);
  }
  UpdateLaser(game->lasers);
  UpdateAsteroid(game->asteroids);
}

void DrawGame(Game* game) {
  DrawShip(game->ship);
  DrawLaser(game->lasers);
  DrawAsteroid(game->asteroids);
}

void SpawnAsteroid(Game* game) {
  if (game->asteroid_count >= ASTEROID_CAP) {
    return;
  }

  Asteroid* new = (Asteroid*)malloc(sizeof(Asteroid));
  if (new == NULL) {
    printf("FAILED TO CREATE ASTEROID\n");
    return;
  }

  int ran_y = GetRandomValue(0, 1);
  int ran_x = GetRandomValue(0, 1);
  new->pos.y = (ran_y == 1) ? GetScreenHeight() : 0;
  new->pos.x = (ran_x == 1) ? GetScreenWidth() : 0;

  int rot = GetRandomValue(0, 360);
  float rads = rot * (M_PI / 180);
  float delta_x = 200.0f * sinf(rads);
  float delta_y = 200.0f * -cosf(rads);

  new->vel.x = delta_x;
  new->vel.y = delta_y;

  new->rotation = game->ship->rotation;

  new->next = game->asteroids;
  game->asteroids = new;
  game->asteroid_count++;
}

void FireLaser(Game* game) {
  Laser* new = (Laser*)malloc(sizeof(Laser));
  if (new == NULL) {
    printf("FAILED TO FIRE LASER\n");
    return;
  }

  float rads = game->ship->rotation * (M_PI / 180);
  float delta_x = 300.0f * sinf(rads);
  float delta_y = 300.0f * -cosf(rads);
  new->vel.x = delta_x;
  new->vel.y = delta_y;

  new->pos = game->ship->pos;
  new->rotation = game->ship->rotation;

  new->next = game->lasers;
  game->lasers = new;
}

void DestroyGame(Game* game) {
  free(game->ship);
  free(game);
}