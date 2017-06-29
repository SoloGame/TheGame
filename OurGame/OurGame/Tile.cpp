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

void Tile::renderTile(GameEngine * game, SDL_Rect * camera, Texture * texture, SDL_Rect * tileClips)
{
	//If the tile is on screen
	if (checkCollision(camera, &m_Collider))
	{
		//Show the tile
		texture->render({ m_PosX - camera->x, m_PosY - camera->y }, game->window->getRenderer(), &tileClips[m_TileType]);
	}
}

