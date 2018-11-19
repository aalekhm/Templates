#pragma once
#include "integral_constant.h"

template <typename U, typename V>
struct is_same : false_type {};

template <typename U>
struct is_same<U, U> : true_type {};