#pragma once
#include "gameengine.h"
#include "State.h"
#include "Texture.h"
#include "Timer.h"

class Intro : public State {
public:
	void Init(GameEngine* game);
	void CleanUp();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static Intro* Instance() {
		return &m_Intro;
	}

protected:
	Intro():m_FPS(100),m_ticksPerFrame(1000 / m_FPS), m_countedFrames(0) { m_fpsTimer.start(); };
private:
	static Intro m_Intro;

	Texture m_Background;


	//timers
	Timer m_fpsTimer; // Timer for FPS
	Timer m_fpscapTimer; // Timer for FPS cap
	const int m_FPS;
	const int m_ticksPerFrame;
	int m_countedFrames;


};