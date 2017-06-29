#include "Timer.h"

Timer::Timer() {
	//Initialize the things!
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
}

void Timer::start() {
	started = true;
	paused = false;
	startTicks = SDL_GetTicks();
}

void Timer::stop() {
	started = false;
	paused = false;
}
/* pause the timer */
void Timer::pause() {
	if ((true == started) && (false == paused)) {
		paused = true;
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

/* Unpause the timer. Reset the starting ticks*/
void Timer::unpause() {
	if (true == paused) {
		paused = false;
		startTicks = SDL_GetTicks() - pausedTicks;
		pausedTicks = 0;
	}
}
// return current ticks. returns 0 if timer is not running
int Timer::getTicks() {
	if (true == started) {
		if (true == paused) {
			return pausedTicks;
		}
		else {
			return SDL_GetTicks() - startTicks;
		}

	}

	return 0;
}

bool Timer::isStarted() {
	return started;
}

bool Timer::isPaused() {
	return paused;
}