#include "Texture.h"

Texture::Texture()
{
	m_Texture = nullptr;
	m_Width = 0;
	m_Height = 0;
}

Texture::~Texture()
{
	free();
}

void Texture::free()
{
	if (m_Texture != nullptr) {
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
		m_Width = 0;
		m_Height = 0;
	}
}

bool Texture::LoadFromFile(std::string path, SDL_Renderer* renderer)
{	
	SDL_Texture* optimizedTexture = nullptr;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == nullptr) {
		printf("Unable to load image %s! SDL_Error %s\n", path.c_str(), IMG_GetError());
	} else {
		//set colour_key
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		// attempt to convert surface to texture

		optimizedTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		
		if (optimizedTexture == nullptr) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		} else {
			//get image dimensions
			m_Width = loadedSurface->w;
			m_Height = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
		m_Texture = optimizedTexture;
	}

	

	return m_Texture != nullptr;
}

void Texture::render(SDL_Point Position, SDL_Renderer * renderer, SDL_Rect * clip, SDL_Point * center, double angle, SDL_RendererFlip flipType)
{
	//set rendering space
	SDL_Rect renderQuad = { Position.x, Position.y, m_Width, m_Height };

	if (clip != nullptr) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx(renderer, m_Texture, clip, &renderQuad, angle, center, flipType);
}
