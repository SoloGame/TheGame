#pragma once 
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Texture {
public:
	Texture();
	~Texture();

	// deallocates texture
	void free();

	bool LoadFromFile(std::string path, SDL_Renderer* renderer);
	//bool LoadFromRenderedText();
		
	//set colour modulation
	void setColour(Uint8 red, Uint8 green, Uint8 blue) { SDL_SetTextureColorMod(m_Texture, red, green, blue); }
	// set Alpha modulation
	void setAlpha(Uint8 alpha) { SDL_SetTextureAlphaMod(m_Texture, alpha); }

	//set blending mode
	void setBlendMode(SDL_BlendMode blending) { SDL_SetTextureBlendMode(m_Texture, blending); }	
	int getWidth() { return m_Width; }
	void setWidth(int width) { m_Width = width; }
	int getHeight() { return m_Height; }
	void setHeight(int height) { m_Height = height; }

	void render(SDL_Point Position, SDL_Renderer* renderer, SDL_Rect* clip = nullptr, SDL_Point* center = nullptr, double angle = 0, SDL_RendererFlip flipType = SDL_FLIP_NONE);


private:
	SDL_Texture* m_Texture;
	int m_Width, m_Height;

};