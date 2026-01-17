#include "../include/laser.h"

void UpdateLaser(Laser* laser) {
  float dt = GetFrameTime();
  while (laser->next != NULL) {
    if (laser->pos.x >= GetScreenWidth()) {
      laser->pos.x = 0;
    } else if (laser->pos.x <= 0) {
      laser->pos.x = GetScreenWidth();
    }

    if (laser->pos.y >= GetScreenHeight()) {
      laser->pos.y = 0;
    } else if (laser->pos.y <= 0) {
      laser->pos.y = GetScreenHeight();
    }

    laser->pos.x += laser->vel.x * dt;
    laser->pos.y += laser->vel.y * dt;
    laser = laser->next;
  }
}

void DrawLaser(Laser* laser) {
  Rectangle rect;
  Vector2 origin = {0, 0};
  Color color = {255, 0, 0, 255};
  while (laser->next != NULL) {
    rect.height = 10;
    rect.width = 10;
    rect.x = laser->pos.x;
    rect.y = laser->pos.y;
    DrawRectanglePro(rect, origin, laser->rotation, color);
    laser = laser->next;
  }
}