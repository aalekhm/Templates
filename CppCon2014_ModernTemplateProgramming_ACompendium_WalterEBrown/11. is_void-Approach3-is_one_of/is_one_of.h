#pragma once
#include "integral_constant.h"

// Primary template: is T the same as any of the types P0toN
template <class T, class... P0toN>		// Check the naming convention 'P0toN'. We can deduce it mnemonically that its a parameter pack.
struct is_one_of;						// declare the interface only... 
										// Follow this if you are working with parameter packs.
										// Do everything else in specialiazations.

// base#1: specialiazation recognizes empty list of types:
template <class T>
struct is_one_of<T> : false_type {};

// base#2: specialization recognizes match at the head of the list of types:
template <class T, class... P1toN>
struct is_one_of<T, T, P1toN...> : true_type {};

// specialization recognizes mismatch at the head of the list & traverses through the list:
template <class T, class P0, class... P1toN>
struct is_one_of<T, P0, P1toN...> : is_one_of<T, P1toN...> {};


