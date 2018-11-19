#pragma once

template <typename T>
struct rank
{
	static size_t const value = 0;
};

template <typename U, size_t N>
struct rank<U[N]>
{
	static size_t const value = 1u + rank<U>::value;
};