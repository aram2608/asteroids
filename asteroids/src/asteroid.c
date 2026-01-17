#include "../include/asteroid.h"

void UpdateAsteroid(Asteroid* asteroid) {
  float dt = GetFrameTime();
  while (asteroid->next != NULL) {
    if (asteroid->pos.x >= GetScreenWidth()) {
      asteroid->pos.x = 0;
    } else if (asteroid->pos.x <= 0) {
      asteroid->pos.x = GetScreenWidth();
    }

    if (asteroid->pos.y >= GetScreenHeight()) {
      asteroid->pos.y = 0;
    } else if (asteroid->pos.y <= 0) {
      asteroid->pos.y = GetScreenHeight();
    }

    asteroid->pos.x += asteroid->vel.x * dt;
    asteroid->pos.y += asteroid->vel.y * dt;
    asteroid = asteroid->next;
  }
}

void DrawAsteroid(Asteroid* asteroid) {
  Rectangle rect;
  Vector2 origin = {0, 0};
  Color color = {255, 255, 255, 255};
  while (asteroid->next != NULL) {
    rect.height = 40;
    rect.width = 40;
    rect.x = asteroid->pos.x;
    rect.y = asteroid->pos.y;
    DrawRectanglePro(rect, origin, asteroid->rotation, color);
    asteroid = asteroid->next;
  }
}