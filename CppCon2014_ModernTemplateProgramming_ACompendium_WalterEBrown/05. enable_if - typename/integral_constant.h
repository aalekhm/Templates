#pragma once

template <typename T, T _val>
struct integral_constant
{
	static const T value = _val;

	typedef T value_type;
	//typedef integral_constant<T, _val> type;

	operator T() const
	{
		return value;
	}
};

template <typename T, T _val>
struct bool_constant : integral_constant<T, _val> {};

typedef bool_constant<bool, true> true_type;
typedef bool_constant<bool, false> false_type;