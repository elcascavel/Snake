#pragma once

namespace Snake {
	class Player {
	public:
		void init(int x, int y);
		void render(SDL_Renderer* renderer);
		void setDirection(SDL_KeyCode direction);
		void update(int width, int height);

		SDL_Rect m_playerRect;
	private:

		enum snakeDirection { North, West, East, South };
		snakeDirection m_snakeDir = South;

		uint32_t m_speed = 2;
	};
}