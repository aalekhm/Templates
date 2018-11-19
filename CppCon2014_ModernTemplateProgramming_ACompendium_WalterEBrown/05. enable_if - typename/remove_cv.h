#pragma once

#include "remove_const.h"
#include "remove_volatile.h"

template <typename T>
struct remove_cv
{
	typedef typename remove_const< typename remove_volatile<T>::type >::type type;
};