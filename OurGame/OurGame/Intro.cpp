#include "Intro.h"
#include "Menu.h"

Intro Intro::m_Intro;

void Intro::Init(GameEngine* game)
{	

	m_Background.LoadFromFile("imgs/intro.png", game->window->getRenderer());
}

void Intro::CleanUp()
{
	m_Background.free();
}

void Intro::Pause()
{
}

void Intro::Resume()
{
}

void Intro::HandleEvents(GameEngine * game)
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
					game->ChangeState(Menu::Instance());
					break;
				case SDLK_ESCAPE:
					game->Quit();
					break;
			}
			break;
		}
	}
}

void Intro::Update(GameEngine * game)
{
}

void Intro::Draw(GameEngine * game)
{
	//only render if the window is not minimized
	if (!game->window->isMinimized()) {
		
		m_fpscapTimer.start();
		//Calculate and correct fps
		float avgFPS = m_countedFrames / (m_fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}
		
		//Clear screen
		SDL_SetRenderDrawColor(game->window->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(game->window->getRenderer());
		
		//render background
		m_Background.render({ 0, 0 }, game->window->getRenderer());
		
		SDL_RenderPresent(game->window->getRenderer());

	}

}
