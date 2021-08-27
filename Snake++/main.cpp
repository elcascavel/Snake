//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "src/snake/game.h"
#include "src/utils/timer.h"

Snake::Game* game = 0;

Snake::Timer fpsTimer;
Snake::Timer capTimer;

const int SCREEN_FPS = 60;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

int countedFrames = 0;

int main(int arc, char* args[]) {
	game = new Snake::Game();

	game->init();
	fpsTimer.start();

	while (game->isRunning()) {
		capTimer.start();
		float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}
		game->handleEvents();

		game->update();

		game->render();

		++countedFrames;

		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICK_PER_FRAME)
		{
			SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
		}
	}

	game->clean();

	return 0;
}