#pragma once
#include "type_is.h"

//////////////////////////// remove_const
template <class T>
struct remove_const : type_is<T> {};

template <class T>
struct remove_const<T const> : type_is<T> {};
//////////////////////////// remove_const ////////////////////////////