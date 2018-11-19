
// Incomplete definition
template <size_t n>
struct fib;

// Base Cases
template <>
struct fib<0>
{
	const static auto value = 1;
};

template <>
struct fib<1>
{
	const static auto value = 1;
};

// Recursive Case
template <size_t n>
struct fib
{
	const static auto value = fib<n - 1>::value + fib<n - 2>::value;
};

// fib<5>::value = fib<4>::value + fib<3>::value;
// fib<4>::value = fib<3>::value + fib<2>::value;
// fib<3>::value = fib<2>::value + fib<1>::value;
// fib<2>::value = fib<1>::value + fib<0>::value;
// fib<1>::value = 1;
// fib<0>::value = 1;

// fib<1>::value = 1
// fib<0>::value = 1
// fib<2>::value = 2
// fib<3>::value = 3
// fib<4>::value = 5
// fib<5>::value = 8