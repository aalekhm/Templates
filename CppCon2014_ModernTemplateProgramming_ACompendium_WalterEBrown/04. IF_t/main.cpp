#include <cstdlib>
#include <iostream>
#include "IF_t.h"

int main()
{
	// IF_t
	{
		const int i = -10;
		IF_t < (i < 0), int, float>::type j;	// j declared to have one of the 2 integer types.
		// Or
		//IF_t<(i < 0), int, unsigned> j;

		//std::function<void()> F1 = []() { std::cout << "F1" << std::endl; };
		//auto G1 = []() { std::cout << "F1" << std::endl; };
		//IF_t < (i < 0), F1, G1>::type();

		class A { public: void print() { std::cout << "class A" << std::endl; } };
		class B { public: void print() { std::cout << "class B" << std::endl; } };
		class C : public IF_t < (i < 0), A, B>::type{};

		C cc;
		cc.print();

		// Turns out this IF_t is in C++11, named conditional !
	}

	std::exit(EXIT_SUCCESS);;
}