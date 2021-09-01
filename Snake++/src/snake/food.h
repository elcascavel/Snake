#pragma once

namespace Snake {
	class Food
	{
	public:
		unsigned x;
		unsigned y;
		SDL_Rect foodRect;
		int getFoodXPosition() { return x; };
		int getFoodYPosition() { return y; };
		void respawn();
		void render(SDL_Renderer* renderer);
	private:
		
	};
}

