#pragma once

namespace Snake {
	class Player {
	public:
		void init(int x, int y);
		void render(SDL_Renderer* renderer);
		void setDirection(SDL_KeyCode direction);
		void takeStep(int position);
		void update(int width, int height, int gridSize);

		SDL_Rect m_head;

	private:

		enum snakeDirection { North, West, East, South };
		snakeDirection m_snakeDir = South;

		float m_snakeSpace = 21.33f;

		int timeStep = 15;
	};
}