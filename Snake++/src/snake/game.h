#pragma once
#include <iostream>
#include <string>
#include "player.h"
#include "food.h"
#include "../utils/timer.h"

namespace Snake {
	class Game
	{
	public:
		void init();
		void handleEvents();
		void update();
		void render();	
		void clean();

		bool isRunning() { return is_running; }

		static unsigned getWWidth() { return SCREEN_WIDTH; }
		static unsigned getWHeight() { return SCREEN_HEIGHT; }
		static unsigned getCellSize() { return CELL_SIZE; }
		static unsigned getCellWidth() { return CELL_WIDTH; }
		static unsigned getCellHeight() { return CELL_HEIGHT; }
		static unsigned getStartLength() { return START_LENGTH; }

		static unsigned getStartX() { return START_X; }
		static unsigned getStartY() { return START_Y; }
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;

		static unsigned const SCREEN_WIDTH = 800;
		static unsigned const SCREEN_HEIGHT = 600;

		static const unsigned CELL_SIZE = 20;
		static const unsigned CELL_WIDTH = SCREEN_WIDTH / CELL_SIZE;
		static const unsigned CELL_HEIGHT = SCREEN_HEIGHT / CELL_SIZE;

		static const unsigned START_X = CELL_WIDTH / 2;
		static const unsigned START_Y = CELL_HEIGHT / 2;
		static const unsigned START_LENGTH = 3;

		Player* player = nullptr;
		Food* food = nullptr;

		bool is_running;
	};

	
}

