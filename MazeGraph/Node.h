#pragma once
#include "Vector2D.h"

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
	Node(size_t id, Vector2D position, PARTS part) : id(id), position(position), part(part) {};
	size_t id;
	PARTS part;
	Vector2D left_neighbour;
	Vector2D right_neighbour;
	Vector2D top_neighbour;
	Vector2D bot_neighbour;
	Vector2D position;
};

