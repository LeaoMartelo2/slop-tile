#include "collider.hpp"
#include <algorithm>

Collider::Collider(float x, float y, float w, float h) : rect{x, y, w, h} {}

bool aabb_collision(const Rectangle &a, const Rectangle &b) {

    // make this shit readable

    return a.x < b.x + b.width &&
           a.x + a.width > b.x &&
           a.y < b.y + b.height &&
           a.y + a.height > b.y;
}

Vector2 calculate_mtv(const Rectangle &a, const Rectangle &b) {

    float overlap_x = std::min(a.x + a.width, b.x + b.width) - std::max(a.x, b.x);
    float overlap_y = std::min(a.y + a.height, b.y + b.height) - std::max(a.y, b.y);

    if (overlap_x > 0 && overlap_y > 0) {

        if (overlap_x < overlap_y) {
            // x axis

            if (a.x < b.x) {
                return {-overlap_x, 0};
            } else {
                return {overlap_x, 0};
            }

        } else {
            // y axis

            if (a.y < b.y) {
                return {0, -overlap_y};
            } else {
                return {0, overlap_y};
            }
        }
    }
    // not colliding with anything;
    return {0, 0};
}
