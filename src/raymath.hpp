#pragma once

#include "raylib.h"

inline bool point_in_rectangle(const Vector2& p, const Rectangle& r) noexcept {
    return  p.x >= r.x &&
            p.x <= r.x + r.width &&
            p.y >= r.y &&
            p.y <= r.y + r.height;
}