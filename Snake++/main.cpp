//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "src/snake/game.h"

Snake::Game* game = 0;

int main(int arc, char* args[]) {
	game = new Snake::Game();

	game->init();

	while (game->isRunning()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}