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
	void SetExit();
	Node startNode;
	Node exitNode;
	void FindPath();
	std::vector<int> path;
	Node GetNextValidNode(Node node);
	void PrintPath();
	void PlotMaze();
	void PrintNodes();
	Node GetPreviousNode(Node node);
	bool isPrevNode;
	void NextStep();
	Node currentNode;
	void StepBack();

	template <typename T>
	void EraseFromVector(std::vector<T>& in, T value);
	
};
