
#include <iostream>
#include "printstuff.h"

void printSomeThing0()
{
	auto myNumber = 92;
	printf("I have %d problems.", myNumber);		// When printf sees %d it looks for something as an int, long, etc.
													// Here we have used myNumber, which is an auto, so compiler willl look at the RHS & infer that its an 'int'.
													// But it will fit it in.
	std::cout << std::endl;
}

void printSomeThing1()
{
	auto myNumber = 92;
	auto whatIHave = "lemons";
	printf("I have %d %s.", myNumber, whatIHave);	// When printf sees %s it looks for an address of a cstring(char*).
													// So of we accidently instead of putting "lemons" were to put 18. Boom.
													// At runtime, printf willl look for data at the address pointing 18 & it will be probably not lemons.
													// So this can cause a security issue, a vulnerability, crash.
													// Also, one would have typecast myNumber or whatIHave depending on the type of argument needed as per requirement.
	std::cout << std::endl;
}

int main()
{
	printSomeThing0();
	printSomeThing1();

	printStuff(4, 9.6, "foo", 92);
	std::exit(EXIT_SUCCESS);
}