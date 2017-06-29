#ifndef TILE_H
#define TILE_H
#include <SDL.h>
//Tile constants
#include "GameEngine.h"
#include "Texture.h"
#include "Functions.h"

//Tile constants
const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;
const int TOTAL_TILES = 192;
const int TOTAL_TILE_SPRITES = 12;

//The different tile sprites
const int TILE_RED = 0;
const int TILE_GREEN = 1;
const int TILE_BLUE = 2;
const int TILE_CENTER = 3;
const int TILE_TOP = 4;
const int TILE_TOPRIGHT = 5;
const int TILE_RIGHT = 6;
const int TILE_BOTTOMRIGHT = 7;
const int TILE_BOTTOM = 8;
const int TILE_BOTTOMLEFT = 9;
const int TILE_LEFT = 10;
const int TILE_TOPLEFT = 11;

class Tile {
public:
	Tile(int x, int y, int tileType);
	~Tile() {}

	//show the box
	void renderTile(GameEngine* Game, SDL_Rect* camera, Texture* texture, SDL_Rect* tileClips );
	
	//Get the tile type
	int getType() { return m_TileType; }

	//Get the collision box
	SDL_Rect* getCollisionBox() { return &m_Collider; }

	//return position


private:	
	//attributes of the tile
	int m_PosX, m_PosY;
	//Tile Collision Box
	SDL_Rect m_Collider;

	//type of tile
	int m_TileType;
};

#endif // !TILE_H
