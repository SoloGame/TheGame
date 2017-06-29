#pragma once
// PAUSE/POPUP MENU

#include "gameengine.h"
#include "State.h"
#include "Texture.h"

class Menu : public State {
public:
	void Init(GameEngine* game);
	void CleanUp();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static Menu* Instance() {
		return &m_Menu;
	}

protected:
	Menu() {};
private:
	static Menu m_Menu;

	Texture m_Background;

};