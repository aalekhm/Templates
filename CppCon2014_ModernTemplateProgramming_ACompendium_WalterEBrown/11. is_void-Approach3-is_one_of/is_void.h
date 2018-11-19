#pragma once
#include "is_one_of.h"

template <class T>
using is_void = is_one_of< T,
						   void,
						   void const,
						   void volatile,
						   void const volatile>;