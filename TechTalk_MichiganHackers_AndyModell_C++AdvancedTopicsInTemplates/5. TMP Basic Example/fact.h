
template <size_t n>
struct fact;						// Incomplete declaration

									// Compiler doesn't make function calls during compile time.
									// What it does instead is create structs with values inside them in memory.
									// Which it later looksup for computation.

// Partial Specialization::
// When we want to tell the compiler that for one particular value we would like to do something different.
// Here, when we see a '0', we want to do some thing different.
// Empty <> says to the compiler that there are no templated values that i know about & there is nothing that
//			is going to be variable in there.
// Eg: std::vector have a partial specialization for 'bool' that is far more memory efficient.
template <>							// Partial Specialization for '0'
struct fact<0>						// Base case
{
	const static auto value = 1;	// 'value' is a member of the struct.
									// Since we can't have a function returning something, so this is how we do it.
									// We ask the compiler to put this up in memory for look-up later.
									// Its a 'static' variable as it will be known at compile time.
									// 'const' since this is a mathematical thing and is not going to change.
									// As we are never going to say that factorial of zero is never going to be a 49.
};

template <size_t n>
struct fact							// Recursive definition
{
	const static auto value = n * fact<n - 1>::value;	// Check the "::value" which tells the compiler that we need to look at that,
														// access the number that is the value object & do a math on that.
};
