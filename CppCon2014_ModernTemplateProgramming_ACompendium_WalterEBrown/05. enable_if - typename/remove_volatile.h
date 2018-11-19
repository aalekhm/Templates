#pragma once
#include "type_is.h"

//////////////////////////// remove_volatile
template <class T>
struct remove_volatile : type_is<T> {};

template <class T>
struct remove_volatile<T volatile> : type_is<T> {};
//////////////////////////// remove_volatile ////////////////////////////
