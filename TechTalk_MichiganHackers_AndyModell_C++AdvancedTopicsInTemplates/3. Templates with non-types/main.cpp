
#include <iostream>
#include <string>

template <size_t NUMBER_OF_COPIES>
void copyPrint(const std::string& str)
{
	for (auto i = 0; i < NUMBER_OF_COPIES; i++)
	{
		std::cout << str << std::endl;
	}
}

template <size_t NUMBER_OF_COPIES, char CHAR>
void copyPrintAppend(const std::string& str)
{
	for (auto i = 0; i < NUMBER_OF_COPIES; i++)
	{
		std::cout << str << " " << CHAR << std::endl;
	}
}

int main()
{
	copyPrint<3>("Hello Templates!");
	copyPrintAppend<3, 'A'>("Hello Templates!");

	std::exit(EXIT_SUCCESS);
}