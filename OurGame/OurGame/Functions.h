#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <SDL.h>
#include "Tile.h"
class Tile;
//Box collision detector
bool checkCollision(SDL_Rect* a, SDL_Rect* b);

//Checks collision box against set of tiles
bool touchesWall(SDL_Rect* box, Tile* tiles[]);

#endif // !FUNCTIONS_H

