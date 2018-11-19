
#include <iostream>
#include <cassert>
#include "tuple.h"

using namespace VariadicTemplates;

void testTupleAssignment()
{
	Tuple<int, char> tuple;
	get<0>(tuple) = 33;			// Assign to the tuple.
	get<1>(tuple) = 'a';

	auto v1 = get<0>(tuple);	// Assign from the tuple.
	auto v2 = get<1>(tuple);
	assert(v1 == 33);
	assert(v2 == 'a');
}

// Use the 'makeTuple' function
void testMakeTuple()
{
	auto t2 = makeTuple(66, 'A', std::string("foo"));

	assert(get<0>(t2) == 66);
	assert(get<1>(t2) == 'A');
	assert(get<2>(t2) == "foo");
}

int main()
{
	testTupleAssignment();
	testMakeTuple();

	std::exit(EXIT_SUCCESS);
}