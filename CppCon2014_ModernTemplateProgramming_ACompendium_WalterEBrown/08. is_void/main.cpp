#include <cstdlib>
#include <iostream>
#include <utility>
#include "is_void.h"

void const volatile foo(int)
{
	std::cout << "foo" << std::endl;
}

int main()
{
	std::cout << is_void<int>::value << std::endl;
	std::cout << is_void<void>::value << std::endl;

	std::exit(EXIT_SUCCESS);
}