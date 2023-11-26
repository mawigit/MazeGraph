#include "MazeGraph.h"
#include "Node.h"

int main()
{
	MazeGraph mg(5, 5, 1);
	mg.SetGetStart();
	mg.SetGetExit();
	mg.SetNeighbours();

	for (Node n : mg.maze)
	{
		std::cout << "ID: " << n.id << " ROW: " << n.position.x << " PART: " << n.part << std::endl;
	}
}