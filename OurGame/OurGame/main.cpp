#include "GameEngine.h"
#include "Intro.h"

int main(int argc, char* argv[]) {

	GameEngine game;

	game.Init("Testing!",800, 600);

	game.ChangeState(Intro::Instance());

	while (game.Running()) {
		game.HandleEvents();
		game.Update();
		game.Draw();
	}

	game.CleanUp();

	return 0;
}