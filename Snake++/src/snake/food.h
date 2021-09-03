#pragma once

namespace Snake {
	struct Food
	{
	public:
		unsigned x;
		unsigned y;
		SDL_Rect foodRect;
		const int getFoodXPosition() { return x; };
		const int getFoodYPosition() { return y; };
		void respawn();
		void render(SDL_Renderer* renderer);
	};
}

