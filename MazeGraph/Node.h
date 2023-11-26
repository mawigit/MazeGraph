#pragma once
#include "MazeGraph.h"

class Node
{
public:
	enum DIRECTION
	{
		LEFT,
		RIGHT,
		TOP,
		BOT
	};

	Node(std::tuple<int, int> position, MazeGraph::PARTS part);
	MazeGraph::PARTS part;
	std::tuple<int, int> left_neighbour;
	std::tuple<int, int> right_neighbour;
	std::tuple<int, int> top_neighbour;
	std::tuple<int, int> bot_neighbour;
	std::tuple<int, int> GetNeighbour(DIRECTION direction);
	std::tuple<int, int> position;
};

