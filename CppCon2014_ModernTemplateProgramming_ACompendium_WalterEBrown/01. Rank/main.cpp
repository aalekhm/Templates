#include <cstdlib>
#include "Rank.h"

int main()
{
	// rank
	{
		using array_t = int[10][20][30][40];
		rank<array_t>::value;
	}

	std::exit(EXIT_SUCCESS);
}