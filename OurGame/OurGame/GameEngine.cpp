#include "GameEngine.h"
#include "State.h"

void GameEngine::Init(const char *title, int width, int height)
{
	window = new Window;
	window->init(title, width, height);
	m_Running = true;
	//m_FullScreen = false;
}

void GameEngine::CleanUp()
{
	delete window;
	//cleanup all states
	while (!m_States.empty()) {
		m_States.back()->CleanUp();
		m_States.pop_back();
	}

	SDL_Quit();

}

void GameEngine::ChangeState(State * state)
{
	// clean up the current state
	if (!m_States.empty()) {
		m_States.back()->CleanUp();
		m_States.pop_back();
	}
	
	// store and init the new state
	m_States.push_back(state);
	m_States.back()->Init(this);
}

void GameEngine::PushState(State * state)
{
	// pause current state
	if (!m_States.empty()) {
		m_States.back()->Pause();
	}

	//store and init new state
	m_States.push_back(state);
	m_States.back()->Init(this);

}

void GameEngine::PopState()
{
	//clean up the current state
	if (!m_States.empty()) {
		m_States.back()->CleanUp();
		m_States.pop_back();
	}

	//resume previous state
	if (!m_States.empty()) {
		m_States.back()->Resume();
	}
}

void GameEngine::HandleEvents()
{
	m_States.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	m_States.back()->Update(this);
}

void GameEngine::Draw()
{
	m_States.back()->Draw(this);
}
