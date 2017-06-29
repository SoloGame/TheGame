#pragma once
#include "Window.h"
#include "Texture.h"

#include <vector>

class State;

class GameEngine {
public:
	void Init(const char* title, int width=640, int height=480);
	void CleanUp();

	void ChangeState(State* state);
	void PushState(State* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_Running; };
	void Quit() { m_Running = false; }

	Window* window;
	

private:
	//stack of states
	std::vector<State*> m_States;
	bool m_Running;
};