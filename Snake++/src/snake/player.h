#pragma once

namespace Snake {
	class Player {
	public:
		void init(int x, int y);
		void render(SDL_Renderer* renderer);
		void setDirection(SDL_KeyCode direction);
		void update();
	private:
		SDL_Rect playerRect;
		enum snakeDirection { North, West, East, South };
		snakeDirection snakeDir = South;

		uint32_t speed = 2;
	};
}