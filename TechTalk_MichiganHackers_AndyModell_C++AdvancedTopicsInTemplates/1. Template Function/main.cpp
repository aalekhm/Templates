#include <cassert>
#include <iostream>

template <typename T>
T _abs(T myNum)
{
	// puts(__PRETTY_FUNCTION__);	// 'gcc'
	puts(__FUNCSIG__);				// 'MSVC'

	if (myNum < 0)
	{
		return -myNum;
	}

	return myNum;
}

void doMath()
{
	std::cout << "1. Simple Template Usage:" << std::endl;

	const int myInt = 3;
	const int myOtherInt = -3;
	assert(_abs(myInt) == _abs(myOtherInt));

	const double myDouble = 3.0;
	const double myOtherDouble = -3.0;
	assert(_abs(myDouble) == _abs(myOtherDouble));
}

int main()
{
	doMath();

	std::exit(EXIT_SUCCESS);
}