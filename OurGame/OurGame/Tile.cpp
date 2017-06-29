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

void Tile::renderTile(GameEngine *game, SDL_Rect *camera, Texture *TileTexture, SDL_Rect TileClips[])
{
	//If the tile is on screen
	if (checkCollision(camera, &m_Collider))
	{
		TileTexture->render({ m_PosX - camera->x, m_PosY - camera->y }, game->window->getRenderer(), &TileClips[m_TileType]);
		//game->gTileTexture.render({ m_PosX - camera->x, m_PosY - camera->y }, game->window->getRenderer(), &gTileClips[mType]);
		//render({ m_PosX, m_PosY }, game->window->getRenderer(), camera);
	}

}

