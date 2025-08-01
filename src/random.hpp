#pragma once

#include <cstdlib>

namespace C {
    template <typename T>
    inline T random_in_range_inclusive(T min, T max) noexcept {
        return ((static_cast<T>(rand()) % (max - min + 1)) + min);
    }
}