#include "MazeGraph.h"
#include "Node.h"

int main()
{
	MazeGraph mg(5, 5, 10);
	mg.SetStart();
	mg.SetExit();
	mg.SetNeighbours();
	mg.FindPath();
	mg.PrintPath();
}