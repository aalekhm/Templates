#include <cstdlib>
#include "remove_volatile.h"

int main()
{
	// remove_volatile
	{
		using volatile_int = volatile int;
		remove_volatile<volatile_int>::type vol;
	}

	std::exit(EXIT_SUCCESS);
}