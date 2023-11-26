#include "MazeGraph.h"



	MazeGraph::MazeGraph(int rows, int cols, int seed) : rows(rows), cols(cols), seed(seed)
	{
		srand(seed);
		for (size_t r = 0; r < rows; r++)
			for (size_t c = 0; c < cols; c++)
			{
				{
					maze.push_back(Node(maze.size(), Vector2D(r, c), Node::PARTS::WALL));
				}
			}
	}


	void MazeGraph::PrintGraph()
	{
		int prev_x = INT_MAX;
		for (Node& n : maze)
		{
			if (prev_x == n.position.x)
			{
				std::cout << " " << n.position.x << "|" << n.position.y;
			}
			else
			{
				std::cout << "\n" << n.position.x << "|" << n.position.y;
			}
			prev_x = n.position.x;
		}
	}


	void MazeGraph::SetNeighbours()
	{
		for (Node& node : maze)
		{

		if (node.position.y > 0)
		{
			//return left node gleich/-1
			node.left_neighbour = Vector2D(node.position.x, node.position.y - 1);
		}
		else
		{
			node.left_neighbour = Vector2D(INT_MAX, INT_MAX);
		}

		if (node.position.y < cols)
		{
		//return right node gleich/+1
			node.right_neighbour = Vector2D(node.position.x, node.position.y + 1);
		}
		else
		{
			node.right_neighbour = Vector2D(INT_MAX, INT_MAX);
		}
		if (node.position.x > 0)
		{
		//return top node -1/gleich
			node.top_neighbour = Vector2D(node.position.x - 1, node.position.y);
		}
		else
		{
			node.right_neighbour = Vector2D(INT_MAX, INT_MAX);
		}
		if (node.position.x < rows)
		{
		//return bot node +1/gleich
			node.bot_neighbour = Vector2D(node.position.x + 1, node.position.y);
		}
		else
		{
			node.right_neighbour = Vector2D(INT_MAX, INT_MAX);
		}
	}
}

	void MazeGraph::SetGetStart()
	{
		Node& node = maze[rand() % rows];
		node.part = Node::PARTS::START;
		startNodeID = node.id;
		std::cout << "Start Node ID: " << startNodeID << std::endl;;

	}

	void MazeGraph::SetGetExit()
	{

		Node& node = maze[maze.size() - rand() % rows];
		node.part = Node::PARTS::EXIT;
		exitNodeID = node.id;
		std::cout << "Exit Node ID: " << exitNodeID <<std::endl;

	}


