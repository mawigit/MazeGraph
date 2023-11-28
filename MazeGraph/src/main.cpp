#include "MazeGraph.h"
#include "Node.h"

int main()
{
	MazeGraph mg(10, 10, 10);
	mg.SetStart();
	mg.SetNeighbours();	
	mg.FindPath();
	mg.PrintPath();

}