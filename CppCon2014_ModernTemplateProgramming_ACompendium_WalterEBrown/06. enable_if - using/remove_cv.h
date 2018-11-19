#pragma once

#include "remove_const.h"
#include "remove_volatile.h"

template <typename T>
struct _remove_cv
{
	using type = remove_const< remove_volatile<T> >;
};

template <typename T>
using remove_cv = typename _remove_cv<T>::type;