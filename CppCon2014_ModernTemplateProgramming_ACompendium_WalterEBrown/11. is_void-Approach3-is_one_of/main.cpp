#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include "is_void.h"
#include "is_same.h"

void volatile foo(int)
{
	std::cout << "foo" << std::endl;
}

int const volatile foo1(void)
{
	std::cout << "foo1" << std::endl;
	return 1;
}

int main()
{
	std::cout << is_void< decltype( foo( std::declval<int>() ) ) >::value << std::endl;
	std::cout << is_void< decltype( foo1() ) >::value << std::endl;

	std::cout << is_same<	decltype( foo( std::declval<int>() ) ),
							decltype( foo1() ) 
						>::value 
	<< std::endl;

	//type_info fooInfo = typeid(foo);
	std::cout << typeid(foo).name() << std::endl;

	std::exit(EXIT_SUCCESS);
}