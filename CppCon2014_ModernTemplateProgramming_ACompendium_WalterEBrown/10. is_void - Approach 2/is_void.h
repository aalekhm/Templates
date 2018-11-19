#pragma once
#include "is_same.h"
#include "remove_cv.h"

template <typename T>
using is_void = is_same< remove_cv_t<T>, void>;