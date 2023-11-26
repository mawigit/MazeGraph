#include "MazeGraph.h"



	MazeGraph::MazeGraph(int rows, int cols, int seed) : rows(rows), cols(cols), seed(seed)
	{		
		srand(seed);
		maze = std::vector<std::vector<int>> (rows, std::vector<int>(cols, WALL));
	}

	void MazeGraph::PrintMaze()
	{
		for (int r = 0; r < rows; ++r)
		{
			for (int c = 0; c < cols; ++c)
			{
				std::cout << maze[r][c] << " ";
			}
			std::cout << "\n";
		}
	}

	void MazeGraph::SetStart()
	{
		maze[rand() % rows][0] = START;

	}

	void MazeGraph::SetExit()
	{
		maze[rand() % rows][cols-1] = EXIT;
	}