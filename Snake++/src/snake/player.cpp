#include <SDL.h>
#include "player.h"
#include "food.h"
#include "game.h"

Snake::Player::Player()
{
	restart();
	food = new Food();
}

Snake::Player::~Player()
{
	segments.clear();
}

void Snake::Player::restart()
{
	segments.clear();

	for (unsigned i = 0; i < Game::getStartLength(); i++)
	{
		addSegment(Game::getStartX() - i, Game::getStartY());
	}
	dead = false;
	direction = snakeDirection::EAST;
}

void Snake::Player::addSegment(unsigned x, unsigned y)
{
	SnakeSegment segment(x, y); 
	segments.push_back(segment);
}

void Snake::Player::update()
{
	if (dead)
	{
		return;
	}

	int moveX[] = { 0, 0, -1, 1 };
	int moveY[] = { -1, 1, 0, 0 };

	x = segments[0].x + moveX[direction];
	y = segments[0].y + moveY[direction];

	timeStep--;
	if (timeStep <= 0)
	{
		SnakeSegment nextSegment(x, y);
		segments.push_front(nextSegment);
		segments.pop_back();
		timeStep = 8;
	}
}

void Snake::Player::setDirection(SDL_KeyCode key)
{
	switch (key)
	{
	case SDLK_UP:
		if (direction != snakeDirection::SOUTH)
		{
			direction = snakeDirection::NORTH;
		}
		break;
	case SDLK_DOWN:
		if (direction != snakeDirection::NORTH)
		{
			direction = snakeDirection::SOUTH;
		}
		break;
	case SDLK_LEFT:
		if (direction != snakeDirection::EAST)
		{
			direction = snakeDirection::WEST;
		}
		break;
	case SDLK_RIGHT:
		if (direction != snakeDirection::WEST)
		{
			direction = snakeDirection::EAST;
		}
		break;
	default:
		break;
	}
}

//bool Snake::Player::foodCollision()
//{
//	return segments[0].x == food->x && segments[0].y == food->y;
//}

void Snake::Player::render(SDL_Renderer* renderer)
{
	if (dead)
	{
		return;
	}

	playerRect.w = Game::getCellSize();
	playerRect.h = Game::getCellSize();

	playerRect.x = segments[0].x * Game::getCellSize();
	playerRect.y = segments[0].y * Game::getCellSize();

	SDL_SetRenderDrawColor(renderer, 247, 59, 135, 255);
	SDL_RenderFillRect(renderer, &playerRect);

	for (unsigned i = 1; i < segments.size(); i++)
	{
		playerRect.x = segments[i].x * Game::getCellSize();
		playerRect.y = segments[i].y * Game::getCellSize();

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &playerRect);
	}
}
