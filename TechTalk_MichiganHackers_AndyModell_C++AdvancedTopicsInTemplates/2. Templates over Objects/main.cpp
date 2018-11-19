
#include <iostream>
#include <string>

template <typename Tfirst, typename Tsecond>
struct SimplePair
{
	Tfirst first;
	Tsecond second;

	SimplePair(Tfirst f, Tsecond s)
	: first(f)
	, second(s)
	{}
};


int main()
{
	auto foo = SimplePair<int, double>(1, 2.0);
	//					   |     |
	//					   |-----|---------------------> compile time parameters(should be known at compile time).

	auto bar = SimplePair<std::string, int>{"Lemons", 40};
	//					   |            |
	//					   |------------|---------------------> compile time parameters(should be known at compile time).

	std::cout << "foo has " << foo.first << ", " << foo.second << std::endl;
	std::cout << "bar has \"" << bar.first << "\", " << bar.second << std::endl;

	std::exit(EXIT_SUCCESS);
}