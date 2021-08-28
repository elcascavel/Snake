#include <SDL.h>
#include "player.h"
#include "game.h"

void Snake::Player::init(int x, int y)
{
	m_head.x = x;
	m_head.y = y;
	m_head.w = m_snakeSpace;
	m_head.h = m_snakeSpace;
}

void Snake::Player::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 235, 49, 108, 255);
	SDL_RenderFillRect(renderer, &m_head);
}

void Snake::Player::setDirection(SDL_KeyCode direction)
{
	switch (direction)
	{
	case SDLK_UP:
		if (m_snakeDir != South)
		{
			m_snakeDir = North;
		}
		break;
	case SDLK_DOWN:
		if (m_snakeDir != North)
		{
			m_snakeDir = South;
		}
		break;
	case SDLK_LEFT:
		if (m_snakeDir != East)
		{
			m_snakeDir = West;
		}	
		break;
	case SDLK_RIGHT:
		if (m_snakeDir != West)
		{
			m_snakeDir = East;
		}
		break;
	default:
		break;
	}
}

void Snake::Player::takeStep(int position)
{

}

void Snake::Player::update(int width, int height, int gridSize)
{
	timeStep--;
	if (timeStep <= 0)
	{
		float speedX = (height / gridSize);
		float speedY = (width / gridSize);

		if (m_head.x < 0)
		{
			speedX = 0;
			speedY = 0;
		}
		else if (m_head.x > width - m_head.w)
		{
			m_head.x = width - m_head.w;
		}

		if (m_head.y < 0)
		{
			speedX = 0;
			speedY = 0;
		}
		else if (m_head.y > height - m_head.h)
		{
			m_head.y = height - m_head.h;
		}

		switch (m_snakeDir)
		{
		case North:
			m_head.y -= speedY;	
			break;
		case West:
			m_head.x -= speedX;
			break;
		case East:
			m_head.x += speedX;
			break;
		case South:
			m_head.y += speedY;
			break;
		default:
			break;
		}

		timeStep = 15;
	}
}
