#pragma once

namespace Snake {
	class Player {
	public:
		void init(int x, int y);
		void render(SDL_Renderer* renderer);
		void update();
	private:
		SDL_Rect playerRect;
	};
}