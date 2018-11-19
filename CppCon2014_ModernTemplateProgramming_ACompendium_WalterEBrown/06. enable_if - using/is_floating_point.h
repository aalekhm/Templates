#pragma once

#include "integral_constant.h"
#include "remove_cv.h"

template <typename T>
struct _is_floating_point : false_type {};

template <>
struct _is_floating_point<float> : true_type {};

template <>
struct _is_floating_point<double> : true_type {};

template <>
struct _is_floating_point<long double> : true_type {};

// 1.
template <typename T>
using is_floating_point = _is_floating_point< remove_cv<T> >;