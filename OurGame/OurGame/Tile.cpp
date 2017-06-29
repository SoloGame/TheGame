#include "Tile.h"

Tile::Tile(int x, int y, int tileType)
{
	//get the offsets
	m_PosX = x;
	m_PosY = y;
	//get the collision box
	m_Collider.x = x;
	m_Collider.y = y;
	m_Collider.w = 16;
	m_Collider.h = 16;

	//get the tile type
	m_TileType = tileType;

}

void Tile::render(GameEngine * Game, SDL_Rect & camera)
{

}

