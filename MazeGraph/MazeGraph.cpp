#include "MazeGraph.h"



	MazeGraph::MazeGraph(int rows, int cols, int seed) : rows(rows), cols(cols), seed(seed)
	{
		srand(seed);
		for (size_t r = 0; r < rows; r++)
			for (size_t c = 0; c < cols; c++)
			{
				{
					Node n(std::tuple<int, int>(r, c), WALL);
					maze.push_back(n);
				}
			}
	}


	void MazeGraph::PrintMaze()
	{
		for (int r = 0; r < rows; ++r)
		{
			for (int c = 0; c < cols; ++c)
			{
				std::cout << std::get<0>(maze[r].position) << " ";
			}
			std::cout << "\n";
		}
	}

	void MazeGraph::SetStart()
	{
		maze[rand() % rows].part = START;

	}

	void MazeGraph::SetExit()
	{
		maze[rand() % cols].part = EXIT;
	}

	Node MazeGraph::GetNode()
	{

	}