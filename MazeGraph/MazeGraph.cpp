#include "MazeGraph.h"



	MazeGraph::MazeGraph(int rows, int cols, int seed) : rows(rows), cols(cols), seed(seed)
	{
		srand(seed);
		for (int r = 0; r < rows; r++)
			for (int c = 0; c < cols; c++)
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
		//	if (node.position.x > 0)
		//	{
		//		//return top node -1/gleich
		//		node.neighbourIDs.push_back(node.id - cols);
		//	}
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

	void MazeGraph::SetGetStart()
	{
		Node& node = maze[rand() % rows];
		node.part = Node::PARTS::START;
		startNodeID = node.id;
		node.beenVisited = true;
		std::cout << "Start Node ID: " << startNodeID << std::endl;;

	}

	void MazeGraph::SetGetExit()
	{

		Node node = maze[maze.size() - rand() % rows];
		node.part = Node::PARTS::EXIT;
		exitNodeID = node.id;
		std::cout << "Exit Node ID: " << exitNodeID <<std::endl;

	}

	void MazeGraph::FindPath()
	{
		Node* curNode = &maze[startNodeID];
		path.push_back(curNode->id);
		while (curNode->id != exitNodeID)
		{
			std::cout << curNode->id << std::endl;
			int neighbourNodeID = GetPossibleNeighbourID(*curNode);
			curNode = &maze[neighbourNodeID];
			maze[neighbourNodeID].beenVisited = true;
			maze[neighbourNodeID].part = Node::PARTS::PATH;
			path.push_back(neighbourNodeID);
		}
	}

	int MazeGraph::GetPossibleNeighbourID(Node node)
	{
		//if target in neighbours, have to take it
		//for(int i : node.neighbours) {if(i == target) {curNode = target;} if(maze[i].beenVisited except previous) {ok}
		//cannot choose a node with neighbours that have been visited
		//if top node chosen - next one may only point away from start, how the fuck do i implement that?!
		for (int id : node.neighbourIDs)
		{
			if (id == exitNodeID)
			{
				return id;
			}
		}
		std::vector<int> neighbours = node.neighbourIDs;
		for(int i = 0; i < node.neighbourIDs.size(); i++)
		{			
			Node candidate = maze[node.neighbourIDs[rand() % node.neighbourIDs.size()]];
			EraseFromVector(neighbours, candidate.id);
			//Is target in candidates neighbours, if yes has to take it
			std::vector<bool> visitedCount;
			for (int id : candidate.neighbourIDs)
			{
				if (maze[id].beenVisited)
				{
					visitedCount.push_back(true);
				}
			}
			if (visitedCount.size() > 1 || candidate.beenVisited)
			{
				continue;
			}
			else
			{
				return candidate.id;
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


