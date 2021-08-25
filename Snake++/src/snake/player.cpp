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

void Snake::Player::setDirection(SDL_KeyCode direction)
{
	switch (direction)
	{
	case SDLK_UP:
		if (snakeDir != South)
		{
			snakeDir = North;
		}
		break;
	case SDLK_DOWN:
		if (snakeDir != North)
		{
			snakeDir = South;
		}
		break;
	case SDLK_LEFT:
		if (snakeDir != East)
		{
			snakeDir = West;
		}	
		break;
	case SDLK_RIGHT:
		if (snakeDir != West)
		{
			snakeDir = East;
		}
		break;
	default:
		break;
	}
}

void Snake::Player::update()
{
	switch (snakeDir)
	{
	case North:
		playerRect.y -= speed;
		break;
	case West:
		playerRect.x -= speed;
		break;
	case East:
		playerRect.x += speed;
		break;
	case South:
		playerRect.y += speed;
		break;
	default:
		break;
	}
}
