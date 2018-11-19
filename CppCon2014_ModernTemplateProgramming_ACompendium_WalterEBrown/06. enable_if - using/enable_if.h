#pragma once
#include "type_is.h"

//////////////////////////// enable_if
template <bool, class T = void>			// default is useful, not essential
struct enable_if : type_is<T> {};		// default primary template assumes bool value is true. Although the programmer decides it.

template <class T>
struct enable_if<false, T> {};			// partial specialization recognizes the false value, computing nothing.
										// no member named 'type' !
//////////////////////////// enable_if ////////////////////////////