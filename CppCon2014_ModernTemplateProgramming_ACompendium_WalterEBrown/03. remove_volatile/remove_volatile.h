#pragma once

//////////////////////////// type_is :: an identity metafunction
template <class T>
struct type_is
{
	using type = T;
};
//////////////////////////// type_is ////////////////////////////

//////////////////////////// remove_volatile
template <class T>
struct remove_volatile : type_is<T>
{ };

template <class T>
struct remove_volatile<T volatile> : type_is<T>
{};
//////////////////////////// remove_volatile ////////////////////////////
