#ifndef SHIP_H_
#define SHIP_H_

#include "raylib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

/// @struct Ship
/// @brief The main ship object
typedef struct {
  Vector2 vel;    /** Velocity of the ship */
  Vector2 pos;    /** Ship's position */
  Vector2 origin; /** The ship's center coordinate */
  Color color;    /** Ships color */
  float height;   /** The ships height in px */
  float width;    /** The ship's width in px */
  float rotation; /** The rotation in degrees */
  float speed;    /** The ship's speed */
} Ship;

/**
 * @brief Method to create a new ship
 * @param window_width The width of the game window
 * @param window_height The height of the game window
 */
Ship* NewShip(int window_width, int window_height);

/**
 * @brief Method to return the ship's rectangle for drawing
 * @param ship A pointer to the ship
 */
Rectangle GetShipRectangle(Ship* ship);

/**
 * @brief Method to update the ship's position
 * @param ship A pointer to the ship
 */
void UpdateShip(Ship* ship);

/**
 * @brief Method to draw the ship to the screen
 * @param ship A pointer to the ship
 */
void DrawShip(Ship* ship);

/**
 * @brief Method to free up the ship's memory
 * @param ship A pointer to the ship
 */
void DestroyShip(Ship* ship);

#endif