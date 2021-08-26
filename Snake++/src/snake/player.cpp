#include <SDL.h>
#include "player.h"
#include "game.h"

void Snake::Player::init(int x, int y)
{
	m_playerRect[0].x = x;
	m_playerRect[0].y = y;
	m_playerRect[0].w = 15;
	m_playerRect[0].h = 15;
}

void Snake::Player::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 235, 49, 108, 255);
	SDL_RenderFillRect(renderer, &m_playerRect[0]);
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
	if (m_lastUpdate == 0)
	{
		m_lastUpdate = SDL_GetTicks();
	}

	int currentTime = SDL_GetTicks();
	m_timeDelta = (currentTime - m_lastUpdate) / 1000.0;

	m_lastUpdate = currentTime;

	double speedDelta = m_speed * m_timeDelta;

	if (m_playerRect[0].x < 0 || m_playerRect[0].x + m_playerRect[0].w > width)
	{
		m_speed = 0;
	}

	switch (m_snakeDir)
	{
	case North:
		m_playerRect[0].y -= speedDelta;
		break;
	case West:
		m_playerRect[0].x -= speedDelta;
		break;
	case East:
		m_playerRect[0].x += speedDelta;
		break;
	case South:
		m_playerRect[0].y += speedDelta;
		break;
	default:
		break;
	}

	if (m_playerRect[0].y < 0 || m_playerRect[0].y + m_playerRect[0].h > height)
	{
		m_speed = 0;
	}
}
