#pragma once
#include "Vector2D.h"
#include <vector>

class Node
{
public:
	enum PARTS
	{
		WALL = 0,
		PATH = 1,
		START = 2,
		EXIT = 3
	};
	Node(int id, Vector2D position, PARTS part, int origin) : id(id), position(position), part(part), origin(origin) {};
	Node() {};
	int id;
	PARTS part;
	std::vector<int> neighbourIDs;
	Vector2D position;
	bool beenVisited = false;
	int origin;

};

