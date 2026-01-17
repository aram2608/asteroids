#include "../include/raylib.h"
#include "../include/game.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

Color BlackBackground = {
    .r = 0,
    .g = 0,
    .b = 0,
    .a = 255,
};

int main(void) {
  Game* game = NewGame(WINDOW_WIDTH, WINDOW_HEIGHT);
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "asteroids");
  SetTargetFPS(80);

  while (!WindowShouldClose()) {
    UpdateGame(game);

    BeginDrawing();
    ClearBackground(BlackBackground);
    DrawGame(game);

    EndDrawing();
  }
  DestroyGame(game);
  CloseWindow();
  return 0;
}