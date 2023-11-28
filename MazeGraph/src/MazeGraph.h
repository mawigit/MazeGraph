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
	void SetStart();
	int startNode;
	int exitNode;
	void FindPath();
	std::vector<int> path;
	int GetNextValidNode(Node& node);
	void PrintPath();
	void PlotMaze();
	void PrintNodes();
	bool IsEdge(Node node);
	bool IsTop(Node node);

	template <typename T>
	void EraseFromVector(std::vector<T>& in, T value);
	
};
