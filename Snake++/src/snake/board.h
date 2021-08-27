#pragma once

namespace Snake {
	class Board
	{
	public:
		int getGridSize();
	private:
		static const int m_gridSize = 10;
		int m_boardSize[m_gridSize][m_gridSize];
	};
}