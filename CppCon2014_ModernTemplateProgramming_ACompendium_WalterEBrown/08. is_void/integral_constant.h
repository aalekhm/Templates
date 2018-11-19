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

template <bool b>
using bool_constant = integral_constant<bool, b>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;