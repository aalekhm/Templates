#include <cstdlib>
#include "remove_const.h"

int main()
{
	// remove_const
	{
		using const_int = const int;
		remove_const<const_int>::type j;
		j = 11;
	}

	std::exit(EXIT_SUCCESS);
}