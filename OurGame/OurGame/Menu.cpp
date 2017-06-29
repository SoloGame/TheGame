#include "Menu.h"
#include "TilingDemo.h"

Menu Menu::m_Menu;

void Menu::Init(GameEngine * game)
{
	m_Background.loadFromFile("imgs/menubg.png", game->window->getRenderer());
}

void Menu::CleanUp()
{
	m_Background.free();
}

void Menu::Pause()
{
}

void Menu::Resume()
{
}

void Menu::HandleEvents(GameEngine * game)
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
				game->ChangeState(TilingDemo::Instance());
				break;
			case SDLK_ESCAPE:
				game->Quit();
				break;
			}
			break;
		}
	}
}

void Menu::Update(GameEngine * game)
{
}

void Menu::Draw(GameEngine * game)
{
	//only render if the window is not minimized
	if (!game->window->isMinimized()) {
		m_Background.render({ 0,0 }, game->window->getRenderer());
		SDL_RenderPresent(game->window->getRenderer());
	}
}
