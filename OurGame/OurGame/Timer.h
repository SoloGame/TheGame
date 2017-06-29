#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>

class Timer
{
public:
	Timer();

	// Various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	// get the timers time
	int getTicks();

	//status of timer
	bool isStarted();
	bool isPaused();

private:
	// the clock time when the timer started
	Uint32 startTicks;
	// the ticks stored when the timer was paused
	Uint32 pausedTicks;
	//timer status (paused started)
	bool paused;
	bool started;

};
#endif // !TIMER_H
