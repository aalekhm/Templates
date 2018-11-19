#include <cstdlib>
#include <iostream>
#include <type_traits>
#include "enable_if.h"
#include "is_integral.h"
#include "is_floating_point.h"

// Convention to metafunctions
// Convention #1:
//		Whatever you point out as your 'result', you alias it by the name of 'type'

template <class T>
typename enable_if<is_integral<T>::value, int>::type
f1(T val)
{
	std::cout << "f(int)" << std::endl;
	return val;
};

template <class T>
typename enable_if<is_floating_point<T>::value, long double>::type
f1(T val)
{
	std::cout << "f(float)" << std::endl;
	return val;
};

int main()
{
	// SFINAE: 'S'ubstitution 'F'ailure 'I's 'N'ot 'A'n 'E'rror
	{
		enable_if<true, int>::type i;

		// SFINAE: 'S'ubstitution 'F'ailure 'I's 'N'ot 'A'n 'E'rror
		//		- Applied during template instantiation.
		//		- During instantiation:
		//			1. Compiler figures out what template arguments are going to be used to instantiate in 1 or all 3 following ways.
		//				- If client code explicitly supplies the template arguments, we take it verbatim.
		//				  This is what you wanted, this is what i'm going to use !
		//				- Deduce from function arguments at the point of call.
		//				- Else taken from the declaration's default template arguments.
		//			2. Replace each template parameter, throughout the template, by its corrosponding template argument.
		//			   We are doing a 'S'ubstitution here.
		//				1 of following 2 possibilities:
		//					1. If these steps produce a well formed code, the instantiation succeeds.
		//					2. But, if the reasulting code is ill formed, it us considered not viable (due to 'S'ubstitution 'F'ailure)
		//					   and that instantiation that never was, is silently discarded.

		// SFINAE - in use

		f1(10);
		f1(100.0f);
		//f1("sss");		// calling f1 with string argument produces an ill-formed program, since both the candidates will be SFINAE'd away.
							//	and compiler will give an error saying it doesn't know of any function f1 that matches with the specified argument 
							// list.

		double j = integral_constant<int, 9>();
		std::cout << j << std::endl;
	}

	std::exit(EXIT_SUCCESS);
}