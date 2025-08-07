#pragma once

#include "corepp/random.hpp"
#include "raylib.h"
#include <cmath>

// This is right now built around using raylib for convenience. At some point,
// it may be a better idea to use a struct myself and then add some static_cast
// calls around other code that uses raylib...
//
// struct Point {
//     float x, y;

//     Point() : x(0), y(0) {}
//     Point(float x, float y) : x(x), y(y) {}

//     // ...
// };

namespace C {
namespace Point {
    inline bool in_rectangle(const Vector2& p, const Rectangle& r) noexcept {
        return  p.x >= r.x &&
                p.x <= r.x + r.width &&
                p.y >= r.y &&
                p.y <= r.y + r.height;
    }

    inline bool in_circle(
        const Vector2& p,
        const Vector2& circle_position,
        const float radius
    ) {
        return p.x >= circle_position.x - radius &&
               p.x <= circle_position.x + radius &&
               p.y >= circle_position.y - radius &&
               p.y <= circle_position.y + radius;
    }

    inline float magnitude(const Vector2& p) {
        return sqrt(p.x*p.x + p.y*p.y);
    }

    /// Randomly change the direction of a vector while maintaining the magnitude
    inline void random_direction_change(Vector2& p) {
        // @TODO: is it faster to normalize and scale or to cos and sin?
        const float velocity_magnitude = C::Point::magnitude(p);
        const float new_angle = Random::decimal<float>() * 2.f * PI;

        p.x = velocity_magnitude * cos(new_angle);
        p.y = velocity_magnitude * sin(new_angle);
    }
}
}