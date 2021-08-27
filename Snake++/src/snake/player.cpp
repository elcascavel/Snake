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

void Snake::Player::update(int width, int height, int gridSize)
{

	float speedX = (height / gridSize) / timeStep;
	float speedY = (width / gridSize) / timeStep;

	if (m_playerRect[0].x < 0)
	{
		speedX = 0;
		speedY = 0;
	}
	else if (m_playerRect[0].x > width - m_playerRect[0].w)
	{
		m_playerRect[0].x = width - m_playerRect[0].w;
	}

	if (m_playerRect[0].y < 0)
	{
		speedY = 0;
		speedY = 0;
	}
	else if (m_playerRect[0].y > height - m_playerRect[0].h)
	{
		m_playerRect[0].y = height - m_playerRect[0].h;
	}	

	switch (m_snakeDir)
	{
	case North:
		m_playerRect[0].y -= speedY;
		break;
	case West:
		m_playerRect[0].x -= speedX;
		break;
	case East:
		m_playerRect[0].x += speedX;
		break;
	case South:
		m_playerRect[0].y += speedY;
		break;
	default:
		break;
	}
}
