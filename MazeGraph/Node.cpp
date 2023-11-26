#include "Node.h"


Node::Node(std::tuple<int, int> position, int part) : position(position), part(part)
{

}
std::tuple<int, int> Node::GetNeighbour(DIRECTION direction, MazeGraph maze)
{
	if (direction == LEFT && std::get<1>(position) > 0)
	{
		//return left node gleich/-1
		return std::tuple<int, int>(std::get<0>(position), std::get<1>(position) -1);
	}
	if (direction == RIGHT && std::get<1>(position) < maze.cols)
	{
		//return right node gleich/+1
		return std::tuple<int, int>(std::get<0>(position), std::get<1>(position) +1);
	}
	if (direction == TOP && std::get<0>(position) > 0)
	{
		//return top node -1/gleich
		return std::tuple<int, int>(std::get<0>(position) -1, std::get<1>(position));
	}
	if (direction == BOT && std::get<0>(position) < maze.rows)
	{
		//return bot node +1/gleich
		return std::tuple<int, int>(std::get<0>(position) +1, std::get<1>(position));
	}
}

