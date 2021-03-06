#pragma once
#include "snakeSegment.h"
#include "food.h"
#include <deque>

namespace Snake {
	class Player
	{
	public:
		Player();
		~Player();
		unsigned x;
		unsigned y;

		void restart();
		void update();
		void setDirection(SDL_KeyCode key);
		int getHeadXPosition() { return x; };
		int getHeadYPosition() { return y; };
		bool isDead() { return dead; };
		const bool wallCollision();
		const bool selfCollision();

		void render(SDL_Renderer* renderer);

		enum snakeDirection {
			NORTH = 0,
			SOUTH,
			WEST,
			EAST,
			DIRECTION_COUNT
		};

		std::deque<SnakeSegment> segments;
	private:
		
		void addSegment(unsigned x, unsigned y);
		SDL_Rect playerRect;

		Food* food = nullptr;

		int timeStep = 5;
		unsigned int direction;
		bool dead;
	};
}

