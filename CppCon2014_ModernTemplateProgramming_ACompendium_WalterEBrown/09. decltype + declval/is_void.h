#pragma once

#include "integral_constant.h"

// Primary template for non-void types
template <typename T>
struct is_void : false_type {};

// Specializations recognize each of the 4 void types.
template <>
struct is_void<void> : true_type{};

template <>
struct is_void<void const> : true_type{};

template <>
struct is_void<void volatile> : true_type{};

template <>
struct is_void<void const volatile> : true_type{};
