#include "TilingDemo.h"
//Menu Menu::m_Menu;
TilingDemo TilingDemo::m_TilingDemo;

void TilingDemo::Init(GameEngine * game)
{
	//load media
	loadMedia(game);
	
	m_Camera = { 0, 0, game->window->getWidth(), game->window->getHeight() };
}

void TilingDemo::CleanUp()
{
	//Deallocate tiles
	for (int i = 0; i < TOTAL_TILES; ++i)
	{
		if (m_TileSet[i] == nullptr)
		{
			delete m_TileSet[i];
			m_TileSet[i] = nullptr;
		}
	}

	m_TileTexture.free();

}

void TilingDemo::Pause()
{
}

void TilingDemo::Resume()
{
}

void TilingDemo::HandleEvents(GameEngine * game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			game->Quit();
			break;
		case SDL_WINDOWEVENT:
			game->window->handleEvent(event);
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_SPACE:
			//	game->ChangeState(TilingDemo::Instance());
				break;
			case SDLK_ESCAPE:
				game->Quit();
				break;
			}
			break;
		}
	}
}

void TilingDemo::Update(GameEngine * game)
{

}

void TilingDemo::Draw(GameEngine * game)
{
	//only render if the window is not minimized
	if (!game->window->isMinimized()) {
		
		//Clear screen
		SDL_SetRenderDrawColor(game->window->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(game->window->getRenderer());

		//Render level
		for (int i = 0; i < TOTAL_TILES; ++i)
		{
			m_TileSet[i]->renderTile(game, &m_Camera, &m_TileTexture, m_TileClips);
		}

		SDL_RenderPresent(game->window->getRenderer());
	}
}

bool TilingDemo::loadMedia(GameEngine* game)
{
	//Loading success flag
	bool success = true;

	//Load tile texture
	if (!m_TileTexture.loadFromFile("imgs/tiles.png", game->window->getRenderer()))
	{
		printf("Failed to load tile set texture!\n");
		success = false;
	}

	//Load tile map
	if (!setTiles())
	{
		printf("Failed to load tile set!\n");
		success = false;
	}

	return success;
}

bool TilingDemo::setTiles()
{
	//Success flag
	bool tilesLoaded = true;

	//The tile offsets
	int x = 0, y = 0;

	//Open the map
	std::ifstream map("lazy.map");

	//If the map couldn't be loaded
	if (&map == nullptr)
	{
		printf("Unable to load map file!\n");
		tilesLoaded = false;
	}
	else
	{
		//Initialize the tiles
		for (int i = 0; i < TOTAL_TILES; ++i)
		{
			//Determines what kind of tile will be made
			int tileType = -1;

			//Read tile from map file
			map >> tileType;

			//If the was a problem in reading the map
			if (map.fail())
			{
				//Stop loading map
				printf("Error loading map: Unexpected end of file!\n");
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if ((tileType >= 0) && (tileType < TOTAL_TILE_SPRITES))
			{
				m_TileSet[i] = new Tile(x, y, tileType);
			}
			//If we don't recognize the tile type
			else
			{
				//Stop loading map
				printf("Error loading map: Invalid tile type at %d!\n", i);
				tilesLoaded = false;
				break;
			}

			//Move to next tile spot
			x += TILE_WIDTH;

			//If we've gone too far
			if (x >= LEVEL_WIDTH)
			{
				//Move back
				x = 0;

				//Move to the next row
				y += TILE_HEIGHT;
			}
		}

		//Clip the sprite sheet
		if (tilesLoaded)
		{
			m_TileClips[TILE_RED].x = 0;
			m_TileClips[TILE_RED].y = 0;
			m_TileClips[TILE_RED].w = TILE_WIDTH;
			m_TileClips[TILE_RED].h = TILE_HEIGHT;

			m_TileClips[TILE_GREEN].x = 0;
			m_TileClips[TILE_GREEN].y = 80;
			m_TileClips[TILE_GREEN].w = TILE_WIDTH;
			m_TileClips[TILE_GREEN].h = TILE_HEIGHT;

			m_TileClips[TILE_BLUE].x = 0;
			m_TileClips[TILE_BLUE].y = 160;
			m_TileClips[TILE_BLUE].w = TILE_WIDTH;
			m_TileClips[TILE_BLUE].h = TILE_HEIGHT;

			m_TileClips[TILE_TOPLEFT].x = 80;
			m_TileClips[TILE_TOPLEFT].y = 0;
			m_TileClips[TILE_TOPLEFT].w = TILE_WIDTH;
			m_TileClips[TILE_TOPLEFT].h = TILE_HEIGHT;

			m_TileClips[TILE_LEFT].x = 80;
			m_TileClips[TILE_LEFT].y = 80;
			m_TileClips[TILE_LEFT].w = TILE_WIDTH;
			m_TileClips[TILE_LEFT].h = TILE_HEIGHT;

			m_TileClips[TILE_BOTTOMLEFT].x = 80;
			m_TileClips[TILE_BOTTOMLEFT].y = 160;
			m_TileClips[TILE_BOTTOMLEFT].w = TILE_WIDTH;
			m_TileClips[TILE_BOTTOMLEFT].h = TILE_HEIGHT;

			m_TileClips[TILE_TOP].x = 160;
			m_TileClips[TILE_TOP].y = 0;
			m_TileClips[TILE_TOP].w = TILE_WIDTH;
			m_TileClips[TILE_TOP].h = TILE_HEIGHT;

			m_TileClips[TILE_CENTER].x = 160;
			m_TileClips[TILE_CENTER].y = 80;
			m_TileClips[TILE_CENTER].w = TILE_WIDTH;
			m_TileClips[TILE_CENTER].h = TILE_HEIGHT;

			m_TileClips[TILE_BOTTOM].x = 160;
			m_TileClips[TILE_BOTTOM].y = 160;
			m_TileClips[TILE_BOTTOM].w = TILE_WIDTH;
			m_TileClips[TILE_BOTTOM].h = TILE_HEIGHT;

			m_TileClips[TILE_TOPRIGHT].x = 240;
			m_TileClips[TILE_TOPRIGHT].y = 0;
			m_TileClips[TILE_TOPRIGHT].w = TILE_WIDTH;
			m_TileClips[TILE_TOPRIGHT].h = TILE_HEIGHT;

			m_TileClips[TILE_RIGHT].x = 240;
			m_TileClips[TILE_RIGHT].y = 80;
			m_TileClips[TILE_RIGHT].w = TILE_WIDTH;
			m_TileClips[TILE_RIGHT].h = TILE_HEIGHT;

			m_TileClips[TILE_BOTTOMRIGHT].x = 240;
			m_TileClips[TILE_BOTTOMRIGHT].y = 160;
			m_TileClips[TILE_BOTTOMRIGHT].w = TILE_WIDTH;
			m_TileClips[TILE_BOTTOMRIGHT].h = TILE_HEIGHT;
		}
	}

	//Close the file
	map.close();

	//If the map was loaded fine
	return tilesLoaded;
	
}
