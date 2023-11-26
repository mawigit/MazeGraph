#include "MazeGraph.h"

int main()
{
	auto tup = std::make_tuple(5, 6);

	std::cout << std::get<0>(tup);
	std::cout << std::get<1>(tup);
}