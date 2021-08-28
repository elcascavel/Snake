#pragma once

namespace Snake {
	class Food {
	public:
		void init(int x, int y);
		void render(SDL_Renderer* renderer);
		void update(SDL_Rect player, int width, int height, int gridSize);
		bool checkCollision(SDL_Rect a, SDL_Rect b);
		
		int getOffsetSize();
	private:
		SDL_Rect foodRect;

		int m_offset = 16;
	};
}