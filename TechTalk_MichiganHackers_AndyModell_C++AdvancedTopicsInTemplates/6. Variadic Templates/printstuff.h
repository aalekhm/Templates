
#include <iostream>

// Variadic Templates:
//		- Allow for arbitary number of arguments also maintaining 'type' safety & do not require 'type' casting.
//		- Compiler will know what you have & we will not have to do it ourselves & compiler will throw you an error,
//				if something is wrong.

void printStuff()
{
	std::cout << std::endl;
}

template <typename Tfirst, typename... Trest>
void printStuff(Tfirst first, Trest... rest)
{//								^
//								|___________________________ Parameter Pack 'typename... args' (accepts Zero+ template arguments).
	std::cout << first << ' ';
	printStuff(rest...);
//					^
//					|_______________________________________ Expanding a Parameter Pack 'args...'
}
