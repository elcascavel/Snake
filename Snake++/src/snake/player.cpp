#include <SDL.h>
#include "player.h"
#include "game.h"

void Snake::Player::init(int x, int y)
{
	m_playerRect.x = x;
	m_playerRect.y = y;
	m_playerRect.w = 20;
	m_playerRect.h = 20;
}

void Snake::Player::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &m_playerRect);
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

void Snake::Player::update(int width, int height)
{

	if (m_playerRect.x < 0 || m_playerRect.x + m_playerRect.w > width)
	{
		m_speed = 0;
	}

	switch (m_snakeDir)
	{
	case North:
		m_playerRect.y -= m_speed;
		break;
	case West:
		m_playerRect.x -= m_speed;
		break;
	case East:
		m_playerRect.x += m_speed;
		break;
	case South:
		m_playerRect.y += m_speed;
		break;
	default:
		break;
	}

	if (m_playerRect.y < 0 || m_playerRect.y + m_playerRect.h > height)
	{
		m_speed = 0;
	}
}
