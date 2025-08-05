#pragma once

#include <cstdlib>

// TODO: using rand() is, I'm learning, not the best approach to random number
//       generation if we care about speed. In the context of this library,
//       which is supposed to be used for game development, speed is important.
//       So, I really should be making something much faster:
//
//          - https://martin.ankerl.com/2018/12/08/fast-random-bool/
//          - https://pracrand.sourceforge.net/
//          - https://github.com/MartyMacGyver/PractRand/tree/master
//
//       However, for now, I'm more interested in making a working game, so I am
//       going to leave it for later.

namespace C {
namespace Random {
    template <typename T>
    inline T in_range_inclusive(T min, T max) noexcept {
        return ((static_cast<T>(rand()) % (max - min + 1)) + min);
    }

    template <typename T>
    inline T decimal() noexcept {
        return static_cast<T>(rand()) / static_cast<T>(RAND_MAX);
    }

    inline bool boolean() noexcept {
        return rand() % 2;
    }
}
}