#include "MazeGraph.h"
#include "Node.h"

int main()
{
	MazeGraph mg(10, 10, 99);
	mg.SetGetStart();
	mg.SetGetExit();
	mg.SetNeighbours();
	mg.FindPath();
}