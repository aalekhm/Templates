#pragma once
#include "type_is.h"

//////////////////////////// remove_const
template <class T>
struct _remove_const : type_is<T> {};

template <class T>
struct _remove_const<T const> : type_is<T> {};

template <typename T>
using remove_const = typename _remove_const<T>::type;
//////////////////////////// remove_const ////////////////////////////