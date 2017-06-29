#ifndef TILINGDEMO_H
#define TILINGDEMO_H
#include "State.h"
#include "Tile.h"
#include <fstream>
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;

class TilingDemo : public State {
public:
	void Init(GameEngine* game);
	void CleanUp();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static TilingDemo* Instance() {
		return &m_TilingDemo;
	}

	bool loadMedia(GameEngine* game);
	bool setTiles();

protected:
	TilingDemo() { }
private:
	static TilingDemo m_TilingDemo;

	SDL_Rect m_Camera;
	Texture m_TileTexture;
	Tile* m_TileSet[TOTAL_TILES];
	SDL_Rect m_TileClips[TOTAL_TILE_SPRITES];
};

#endif // !TILINGDEMO_H
