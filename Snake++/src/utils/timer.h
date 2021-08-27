#pragma once

namespace Snake {
	class Timer
	{
	public:
		Timer();

		void start();
		void stop();
		void pause();
		void unpause();

		int getTicks();

		bool isStarted();
		bool isPaused();

	private:
		int m_startTicks;

		int m_pausedTicks;

		bool m_paused;
		bool m_started;
	};
}

