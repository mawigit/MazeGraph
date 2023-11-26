#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <tuple>

class MazeGraph

{
public:
	enum PARTS
	{
		WALL = 0,
		PATH = 1,
		START = 2,
		EXIT = 3
	};

	MazeGraph(int rows, int cols, int seed);
	int seed;
	int rows;
	int cols;
	std::vector<std::vector<int>> maze;
	void PrintMaze();
	void SetStart();
	void SetExit();
};