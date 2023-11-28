#include "MazeGraph.h"



	MazeGraph::MazeGraph(int rows, int cols, int seed) : rows(rows), cols(cols), seed(seed)
	{
		srand(seed);
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				maze.push_back(Node(maze.size(), Vector2D(r, c), Node::PARTS::WALL, 0));
			}
		}
		SetStart();
		SetExit();
		currentNode = startNode;
		SetNeighbours();
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
			if (node.position.x > 0)
			{
				//return top node -1/gleich
				node.neighbourIDs.push_back(node.id - cols);
			}
			if (node.position.y < cols -1)
			{
			//return right node gleich/+1
				node.neighbourIDs.push_back(node.id + 1);
			}

			if (node.position.x < rows -1)
			{
			//return bot node +1/gleich
				node.neighbourIDs.push_back(node.id + cols);
			}
			if (node.position.y > 0)
			{
				//return left node gleich/-1
				node.neighbourIDs.push_back(node.id - 1);
			}
		}
	}

	void MazeGraph::SetStart()
	{
		Node& node = maze[rand() % rows];
		node.part = Node::PARTS::START;
		startNode = node;
		node.beenVisited = true;
		std::cout << "START Node ID: " << startNode.id << std::endl;;
	}

	void MazeGraph::SetExit()
	{
		Node& node = maze[maze.size() - rand() % rows];
		node.part = Node::PARTS::EXIT;
		exitNode = node;
		node.beenVisited = true;
		std::cout << "EXIT Node ID: " << exitNode.id << std::endl;;
	}
	void MazeGraph::FindPath()
	{
		while (currentNode.id != exitNode.id)
		{
			NextStep();
		}
	}
/*
		Node curNode = &maze[startNode];
		path.push_back(curNode.id);
		while (curNode.id != exitNode)
		{
			isPrevNode = false;
			std::cout << curNode.id << std::endl;
			int neighbourNodeID = GetNextValidNode(*curNode);
			maze[neighbourNodeID].origin = curNode.id;
			curNode = &maze[neighbourNodeID];
			maze[neighbourNodeID].beenVisited = true;
			maze[neighbourNodeID].part = Node::PARTS::PATH;
			path.push_back(neighbourNodeID);
		}
		exitNode = curNode.id;
	}

*/
	Node MazeGraph::GetNextValidNode(Node node)
	{
		//cannot choose a node with neighbours that have been visited
		//if top node chosen - next one may only point away from start, how the fuck do i implement that?!
		//if current node > startnode, next must be > and vice versa
		//id current node is edge, next node must be > than start

		std::vector<int> neighbours = node.neighbourIDs;
		std::random_device rng;
		std::mt19937 urng(rng());
		std::shuffle(neighbours.begin(), neighbours.end(), urng);
		//iterate over neighbours of node
		for(int i = 0; i <= neighbours.size()-1; i++)
		{
			//declare candidate (potential node to be evaluated)
			Node candidate = maze[neighbours[i]];
			if (candidate.id == exitNode.id)
			{
				return candidate;
			}
 			if (candidate.beenVisited)
			{
				continue;
			}
			std::vector<bool> visitedCount;
			//interate over neighbours of neighbour
			for (int id : candidate.neighbourIDs)
			{
				Node subCandidate = maze[id];
				if (subCandidate.beenVisited)
				{
					visitedCount.push_back(true);
				}
			}
			if (visitedCount.size() > 1)
			{
				if (i == neighbours.size() -1)
				{					
					StepBack();
				}
				continue;
			}
			else
			{
				return candidate;
			}
		}
	}

	bool NodeBeenVisited(Node node)
	{
		return node.beenVisited;
	}

	void MazeGraph::PrintPath()
	{
		for (int i = 0; i < path.size(); i++)
		{
			std::cout << "Step: " << i << " Node: " << path[i] << std::endl;
		}
	}

	template <typename T>
	void MazeGraph::EraseFromVector(std::vector<T>& in, T value)
	{
		in.erase(std::remove(in.begin(), in.end(), value), in.end());
	};

	void MazeGraph::PlotMaze()
	{
		int prevRow = 0;
		for (Node node : maze)
		{
			if (node.position.x == prevRow)
			{
				if (node.part == Node::PARTS::START || node.part == Node::PARTS::PATH || node.part == Node::PARTS::EXIT)
				{
					std::cout << "1";
				}
				else
				{
					std::cout << "0";
				}
			}
			else
			{
				if (node.part == Node::PARTS::START || node.part == Node::PARTS::PATH || node.part == Node::PARTS::EXIT)
				{
					std::cout << "\n1";
				}
				else
				{
					std::cout << "\n0";
				}
			}
			prevRow = node.position.x;
		}

	}

	void MazeGraph::PrintNodes()
	{
		for (Node& n : maze)
			for(int i : n.neighbourIDs)
		{
				std::cout << n.id << ": " << i << std::endl;
		}
	}

	Node MazeGraph::GetPreviousNode(Node node)
	{
		return maze[node.origin];
		// get index of current node in path substract 1
		/*
			auto targetIndex = std::find(path.begin(), path.end(), node.id);

			if (targetIndex != path.end())
			{
				int index = targetIndex - path.begin();
				//std::cout << index << std::endl;
				int foo = path[index-1];
				return foo;
			}
			else
			{
				// If the element is not 
				// present in the vector 
				std::cout << "INDEX NOT IN VECTOR" << std::endl;
		}
		*/
	}

	// Implement backtrack logic to know whic node caused the problematic path and choose another
	// maintain a list of backtrack nodes
	// if no more eligible neighbours try previous node, repeat

	//nextStep, if no eligible neighbour, stepBack, try again . until end is reached

	void MazeGraph::NextStep()
	{
		//Push node to path
		path.push_back(currentNode.id);
		//Calculate an eligible neighbour
		Node newNode = GetNextValidNode(currentNode);
		std::cout << newNode.id << std::endl;
		maze[newNode.id].origin = currentNode.id;
		currentNode = maze[newNode.id];
		maze[newNode.id].beenVisited = true;
		maze[newNode.id].part = Node::PARTS::PATH;
	}

	void MazeGraph::StepBack()
	{
		Node prevNode = maze[currentNode.origin];
		currentNode = prevNode;
		std::cout << currentNode.id << std::endl;

	}
