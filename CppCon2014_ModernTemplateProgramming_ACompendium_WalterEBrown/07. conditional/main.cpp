#include <cstdlib>
#include <iostream>
#include "conditional.h"

int main()
{
	// conditional
	{
		const int i = -10;
		conditional < (i < 0), int, float>::type j;	// j declared to have one of the 2 integer types.
		// Or
		//conditional<(i < 0), int, unsigned> j;

		class A { public: void print() { std::cout << "class A" << std::endl; } };
		class B { public: void print() { std::cout << "class B" << std::endl; } };
		class C : public conditional < (i < 0), A, B>::type{};

		C cc;
		cc.print();
	}

	std::exit(EXIT_SUCCESS);
}