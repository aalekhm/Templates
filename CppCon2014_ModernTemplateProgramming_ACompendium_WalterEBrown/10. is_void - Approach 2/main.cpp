#include <cstdlib>
#include <iostream>
#include "is_void.h"

void const volatile foo(int)
{
	std::cout << "foo" << std::endl;
}

void const volatile foo1(void)
{
	std::cout << "foo1" << std::endl;
}

int main()
{
	std::cout << is_void< decltype( foo( std::declval<int>() ) ) >::value << std::endl;
	std::cout << is_void< decltype( foo1() ) >::value << std::endl;

	std::exit(EXIT_SUCCESS);
}