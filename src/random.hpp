#pragma once

#include <cstdlib>

template <typename T>
inline T random_in_range_inclusive(T min, T max) {
    return ((static_cast<T>(rand()) % (max - min + 1)) + min);
}