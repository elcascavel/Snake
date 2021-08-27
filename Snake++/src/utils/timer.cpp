#include "timer.h"
#include <SDL_timer.h>

Snake::Timer::Timer() {
	m_startTicks = 0;
	m_pausedTicks = 0;

	m_paused = false;
	m_started = false;
}

void Snake::Timer::start() {
	m_started = true;

	m_paused = false;

	m_startTicks = SDL_GetTicks();
	m_pausedTicks = 0;
}

void Snake::Timer::stop() {
	m_started = false;

	m_paused = false;

	m_startTicks = 0;
	m_pausedTicks = 0;
}

void Snake::Timer::pause() {
	if (m_started && !m_paused)
	{
		m_paused = true;
		m_pausedTicks = SDL_GetTicks() - m_startTicks;
		m_startTicks = 0;
	}
}

void Snake::Timer::unpause() {
	if (m_started && m_paused)
	{
		m_paused = false;
		m_startTicks = SDL_GetTicks() - m_pausedTicks;
		m_pausedTicks = 0;
	}
}

int Snake::Timer::getTicks()
{
	//The actual timer time
	Uint32 time = 0;

	//If the timer is running
	if (m_started)
	{
		//If the timer is paused
		if (m_paused)
		{
			//Return the number of ticks when the timer was paused
			time = m_pausedTicks;
		}
		else
		{
			//Return the current time minus the start time
			time = SDL_GetTicks() - m_startTicks;
		}
	}

	return time;
}

bool Snake::Timer::isStarted()
{
	//Timer is running and paused or unpaused
	return m_started;
}

bool Snake::Timer::isPaused()
{
	//Timer is running and paused
	return m_paused && m_started;
}