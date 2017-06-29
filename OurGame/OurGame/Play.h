#pragma once
#include "State.h"

class Play : public State {
public:
	void Init(GameEngine* game);
	void CleanUp();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static Play* Instance() {
		return &m_Play;
	}
protected:
	Play() { }
private:
	static Play m_Play;
};