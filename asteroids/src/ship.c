#include "../include/ship.h"

Ship* NewShip(int window_width, int window_height) {
  Ship* ship = (Ship*)malloc(sizeof(Ship));

  ship->vel.x = 0;
  ship->vel.y = 0;

  ship->rotation = 0;
  ship->height = 40;
  ship->width = 30;

  ship->pos.y = window_height / 2 - ship->width / 2;
  ship->pos.x = window_width / 2 - ship->height / 2;

  ship->origin.x = 0;
  ship->origin.y = 0;

  ship->color.r = 255;
  ship->color.g = 255;
  ship->color.b = 255;
  ship->color.a = 255;

  return ship;
}

Rectangle GetShipRectangle(Ship* ship) {
  Rectangle rect = {
      rect.x = ship->pos.x,
      rect.y = ship->pos.y,
      rect.width = ship->width,
      rect.height = ship->height,
  };

  return rect;
}

void UpdateShip(Ship* ship) {
  ship->vel.x = 0;
  ship->vel.y = 0;
  float dt = GetFrameTime();

  if (IsKeyDown(KEY_LEFT)) {
    ship->rotation -= 100 * dt;
  } else if (IsKeyDown(KEY_RIGHT)) {
    ship->rotation += 100 * dt;
  }

  if (IsKeyDown(KEY_UP)) {
    float rads = ship->rotation * (M_PI / 180);
    float delta_x = 100 * cosf(rads);
    float delta_y = 100 * sinf(rads);

    printf("Delta X : %f, Delta Y : %f\n", delta_x, delta_y);

    ship->vel.y += delta_y * dt;
    ship->vel.x += delta_x * dt;
  }
  ship->pos.y += ship->vel.y;
  ship->pos.x += ship->vel.x;
}

void DrawShip(Ship* ship) {
  DrawRectanglePro(GetShipRectangle(ship), ship->origin, ship->rotation,
                   ship->color);
  // DrawRectangle((int)ship->pos.x, (int)ship->pos.y, (int)ship->width,
  // (int)ship->height, ship->color);
}

void DestroyShip(Ship* ship) {
  free(ship);
  ship = NULL;
}