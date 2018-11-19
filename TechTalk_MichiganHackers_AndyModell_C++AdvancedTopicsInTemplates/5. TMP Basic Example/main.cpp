
#include <iostream>
#include "fact.h"
#include "fib.h"

//constexpr
size_t _fib(size_t iNum)
{
	if (iNum <= 1)								// Base case
		return 1;
	else
		return _fib(iNum - 1) + _fib(iNum - 2);	// Recursive case
}

//constexpr
size_t _fact(size_t iNum)
{
	if (iNum == 0)						// Base case
		return 1;
	else
		return iNum * _fact(iNum - 1);	// Recursive case
}

void factExample()
{
	std::cout	<< fact<2>::value << ' '
				<< fact<3>::value << ' '
				<< fact<4>::value << ' '
				<< fact<5>::value << std::endl;
	static_assert(fact<5>::value == 120, "Factorial math problem.");		// Will be produced at compile time if there was a problem.
}

void fibExample()
{
	std::cout	<< fib<1>::value << ' '
				<< fib<2>::value << ' '
				<< fib<3>::value << ' '
				<< fib<4>::value << ' '
				<< fib<5>::value << std::endl;
	static_assert(fib<5>::value == 8, "Fibonacci math problem.");		// Will be produced at compile time if there was a problem.
}

int main()
{
	factExample();
	fibExample();

	std::cout	<< _fact(2) << ' '
				<< _fact(3) << ' '
				<< _fact(4) << ' '
				<< _fact(5) << std::endl;

	std::exit(EXIT_SUCCESS);
}