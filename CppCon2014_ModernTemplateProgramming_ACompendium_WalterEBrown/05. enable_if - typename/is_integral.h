#pragma once

#include "integral_constant.h"
#include "remove_cv.h"

template <typename T>
struct _is_Integral : false_type {};

template <>
struct _is_Integral<bool> : true_type {};

template <>
struct _is_Integral<char> : true_type {};

template <>
struct _is_Integral<unsigned char> : true_type {};

template <>
struct _is_Integral<signed char> : true_type {};

template <>
struct _is_Integral<unsigned short> : true_type {};

template <>
struct _is_Integral<signed short> : true_type {};

template <>
struct _is_Integral<unsigned int> : true_type {};

template <>
struct _is_Integral<signed int> : true_type {};

template <>
struct _is_Integral<unsigned long> : true_type {};

template <>
struct _is_Integral<signed long> : true_type {};

#define __LONG __int64
template <>
struct _is_Integral<__LONG> : true_type {};

#define __ULONG unsigned __int64
template <>
struct _is_Integral<__ULONG> : true_type {};

// 1.
template <typename T>
struct is_integral : _is_Integral< typename remove_cv<T>::type > {};

