#pragma once

#include "raylib.h"

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
}
}