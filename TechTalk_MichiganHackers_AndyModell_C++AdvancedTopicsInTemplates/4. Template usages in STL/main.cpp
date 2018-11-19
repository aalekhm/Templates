
#include <iostream>
#include <vector>
#include <map>
#include <array>

void containers()
{
	auto foo = std::vector<int>{1, 2, 3, 4};								// Template with one type
	auto bar = std::map<int, char>{{ 1, 'a' }, { 2, 'b' }, { 3, 'c' }};		// Template with multiple types
	auto baz = std::array<int, 3>{{1, 2, 3}};								// Template with a type and a number
}

int main()
{
	containers();

	std::exit(EXIT_SUCCESS);
}