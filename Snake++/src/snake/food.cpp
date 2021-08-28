#include <SDL.h>
#include "food.h"
#include "game.h"

void Snake::Food::init(int x, int y)
{
	foodRect.x = x;
	foodRect.y = y;
	foodRect.w = 21.33f;
	foodRect.h = 21.33f;
}

void Snake::Food::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 00, 255);
	SDL_RenderFillRect(renderer, &foodRect);
}

bool Snake::Food::checkCollision(SDL_Rect a, SDL_Rect b)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

int Snake::Food::getOffsetSize()
{
	return m_offset;;
}

void Snake::Food::update(SDL_Rect player, int width, int height, int gridSize)
{
	if (checkCollision(player, foodRect))
	{	
		srand(time(0));

		int cellX = rand() % gridSize;
		int cellY = rand() % gridSize;

		foodRect.x = (width / gridSize) * cellX - m_offset;
		foodRect.y = (height / gridSize) * cellY- m_offset;

		std::cout << foodRect.x << std::endl;
		std::cout << foodRect.y << std::endl;
	}
}
