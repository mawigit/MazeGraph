#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include "Vector2D.h"
#include "Node.h"

class MazeGraph

{
public:
	enum DIRECTION
	{
		LEFT,
		RIGHT,
		TOP,
		BOT
	};
	MazeGraph(int rows, int cols, int seed);
	int seed;
	int rows;
	int cols;
	std::vector<Node> maze;
	void PrintGraph();
	void SetNeighbours();
	void SetGetStart();
	void SetGetExit();
	size_t startNodeID;
	size_t exitNodeID;
};
