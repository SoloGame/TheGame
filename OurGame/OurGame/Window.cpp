#include "Window.h"

Window::Window()
{
	//Initialize non-existant window
	m_Window = nullptr;
	m_MouseFocus = false;
	m_KeyboardFocus = false;
	m_FullScreen = false;
	m_Minimized = false;
	m_Width = 0;
	m_Height = 0;
}

bool Window::init(const char *title, int width, int height)
{
	//Create window
	m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (m_Window != nullptr)
	{
		m_MouseFocus = true;
		m_KeyboardFocus = true;
		m_Width = width;
		m_Height = height;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	return m_Window != nullptr;
}

SDL_Renderer * Window::getRenderer()
{	
	return m_Renderer;
}

void Window::handleEvent(SDL_Event &e)
{
	//Window event occured
	if (e.type == SDL_WINDOWEVENT)
	{
		switch (e.window.event)
		{
			//Get new dimensions and repaint on window size change
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			m_Width = e.window.data1;
			m_Height = e.window.data2;
			SDL_RenderPresent(m_Renderer);
			break;

			//Repaint on exposure
		case SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent(m_Renderer);
			break;

			//Mouse entered window
		case SDL_WINDOWEVENT_ENTER:
			m_MouseFocus = true;
			//updateCaption = true;
			break;

			//Mouse left window
		case SDL_WINDOWEVENT_LEAVE:
			m_MouseFocus = false;
			//updateCaption = true;
			break;

			//Window has keyboard focus
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			m_KeyboardFocus = true;
			//updateCaption = true;
			break;

			//Window lost keyboard focus
		case SDL_WINDOWEVENT_FOCUS_LOST:
			m_KeyboardFocus = false;
			//updateCaption = true;
			break;

			//Window minimized
		case SDL_WINDOWEVENT_MINIMIZED:
			m_Minimized = true;
			//printf("Window Minimized\n");
			break;

			//Window maxized
		case SDL_WINDOWEVENT_MAXIMIZED:
			m_Minimized = false;
			break;

			//Window restored
		case SDL_WINDOWEVENT_RESTORED:
			m_Minimized = false;
			break;
		}
	}


}
