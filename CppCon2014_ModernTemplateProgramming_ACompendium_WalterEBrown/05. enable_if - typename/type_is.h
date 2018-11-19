#pragma once

//////////////////////////// type_is :: an identity metafunction
template <class T>
struct type_is
{
	using type = T;
	// OR
	//typedef T type;
};
//////////////////////////// type_is ////////////////////////////