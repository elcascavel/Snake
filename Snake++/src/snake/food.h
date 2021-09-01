#pragma once

namespace Snake {
	class Food
	{
	public:
		unsigned x;
		unsigned y;
		SDL_Rect foodRect;
		void respawn();
		void render(SDL_Renderer* renderer);
	private:
		
	};
}

