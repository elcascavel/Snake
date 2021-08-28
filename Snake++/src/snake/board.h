#pragma once

namespace Snake {
	class Board
	{
	public:
		int getGridSize();
	private:
		static const int m_gridSize = 30;
		int m_board[m_gridSize][m_gridSize];
	};
}