#pragma once

// primary template handles types that are non const-qualified:
template <class T>
struct remove_const
{
	using type = T;
};

// partial specialization recognizes const-qualified types:
template <class U>
struct remove_const<U const>
{
	using type = U;
};