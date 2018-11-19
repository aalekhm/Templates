#pragma once

template <bool _test, typename _T1, typename _T2>
struct conditional
{
	typedef _T2 type;							// type is _T2 for _test is false
};

template <typename _T1, typename _T2>
struct conditional<true, _T1, _T2>				// type is _T1 for _test is true
{
	typedef _T1 type;
};