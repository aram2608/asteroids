#include "../include/raylib.h"
#include "../include/ship.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

Color BlackBackground = {
    .r = 0,
    .g = 0,
    .b = 0,
    .a = 255,
};

int main() {
  Ship* ship = NewShip(WINDOW_WIDTH, WINDOW_HEIGHT);

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "asteroids");
  SetTargetFPS(80);

  while (!WindowShouldClose()) {
    UpdateShip(ship);

    BeginDrawing();
    ClearBackground(BlackBackground);
    DrawShip(ship);

    EndDrawing();
  }
  DestroyShip(ship);
  CloseWindow();
  return 0;
}