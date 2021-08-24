#include <SDL.h>
#include "player.h"

void Snake::Player::init(int x, int y)
{
	playerRect.x = x;
	playerRect.y = y;
	playerRect.w = 20;
	playerRect.h = 20;
}

void Snake::Player::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &playerRect);
}
