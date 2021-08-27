#pragma once
#include <iostream>
#include "player.h"
#include "food.h"
#include "board.h"

namespace Snake {
	class Game {

	public:
		Game() {}
		~Game() {}

		void init();
		void render();
		void update();
		void handleEvents();
		void clean();

		bool isRunning() { return is_running; }

	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;

		Player* player = nullptr;
		Food* food = nullptr;
		Board* board = nullptr;

		int screen_w = 640;
		int screen_h = 640;

		bool is_running = false;
	};
}