#include <SDL.h>
#include "food.h"
#include "game.h"

void Snake::Food::respawn()
{
	srand(time(NULL));
	x = 1 + rand() % (Game::getCellWidth() - 2);
	y = 1 + rand() % (Game::getCellHeight() - 2);

	foodRect.x = x * Game::getCellSize();
	foodRect.y = y * Game::getCellSize();

	foodRect.w = Game::getCellSize();
	foodRect.h = Game::getCellSize();
}

void Snake::Food::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 88, 214, 86, 255);
	SDL_RenderFillRect(renderer, &foodRect);
}