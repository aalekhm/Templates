#pragma once

//////////////////////////// type_is :: an identity metafunction
template <class T>
struct type_is
{
	using type = T;
};
//////////////////////////// type_is ////////////////////////////

//////////////////////////// IF_t
// Convenience call "_t" are all 'type' returning meta function call alias.

template <bool, class T, class>			// needn't name unused params.
struct IF_t : type_is<T>				// default primary template assumes bool value is true. Although the programmer decides it.
{ };

template <class T, class F>
struct IF_t<false, T, F> : type_is<F>	// partial specialization recognizes the false value.
{};
//////////////////////////// IF_t ////////////////////////////