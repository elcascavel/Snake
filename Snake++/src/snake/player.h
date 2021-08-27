#pragma once

namespace Snake {
	class Player {
	public:
		void init(int x, int y);
		void render(SDL_Renderer* renderer);
		void setDirection(SDL_KeyCode direction);
		void update(int width, int height, int gridSize);

		SDL_Rect m_playerRect[5] = {};

	private:

		enum snakeDirection { North, West, East, South };
		snakeDirection m_snakeDir = South;

		int timeStep = 20;
	};
}