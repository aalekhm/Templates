#pragma once

#include "remove_const.h"
#include "remove_volatile.h"

template <typename T>
struct remove_cv
{
	using type = remove_const< remove_volatile<T> >;
};

template <typename T>
using remove_cv_t = typename remove_cv<T>::type;