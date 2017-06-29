#pragma once
#include <SDL.h>


class Window {
public:
	Window();

	//creates window
	bool init(const char * title, int width, int height);
	//creates renderer from internal window
	SDL_Renderer* getRenderer();
	//Handle Window Events
	void handleEvent(SDL_Event &e);
	//deallocate internals
	void free();
	//window dimensions
	int getWidth() { return m_Width; }
	int getHeight() { return m_Height; }

	//Window focii
	bool hasMouseFocus();
	bool hasKeyboardFocus();
	bool isMinimized() { return m_Minimized; }

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	int m_Width;
	int m_Height;

	//Window Focus
	bool m_MouseFocus;
	bool m_KeyboardFocus;
	bool m_FullScreen;
	bool m_Minimized;

};