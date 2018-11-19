#pragma once
#include "type_is.h"

//////////////////////////// remove_volatile
template <class T>
struct _remove_volatile : type_is<T> {};

template <class T>
struct _remove_volatile<T volatile> : type_is<T> {};

template <typename T>
using remove_volatile = typename _remove_volatile<T>::type;
//////////////////////////// remove_volatile ////////////////////////////
