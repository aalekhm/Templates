#include <cstdlib>
#include <iostream>
#include <utility>
#include "is_void.h"

void const volatile foo(int)
{
}

int main()
{
	std::cout << is_void<int>::value << std::endl;
	std::cout << is_void<void>::value << std::endl;

	//						  ________________________________ Inspection of a function call, foo.
	//						  ||
	//						  \/
	std::cout << is_void< decltype( foo( std::declval<int>() ) ) >::value << std::endl;
	//						  ^		 ^          ^
	//						  |	     |		    |
	//						  |		 |		    |_____________ An unevaluated call to 'std::declval<int>()' gives an rvalue result of type 'T'.
	//						  |		 |						   'std::declval<T&>()' gives lvalue.
	//						  |		 |
	//						  |		 |________________________ NOT an actual function call.
	//						  |
	//						  |_______________________________ decltype(something) gives you the declared type, which in case of a function call,
	//																is the return type.
	//														   An unevaluated function call 'foo'.
	//														   Gives foo's return type, if it was called with a 'int' rvalue.
	//														   Does an "inspection" of the function call foo().
	//														   It doesn't actually make a function call, but just have a look at the call,
	//														   because by inspecting we can ask what would the return type be !

	std::exit(EXIT_SUCCESS);
}