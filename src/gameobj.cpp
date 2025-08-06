#include "gameobj.hpp"

Player::Player(Tilemap *tm, Vector2 start_pos, float s, float sz) : tilemap(tm),
                                                                    pos(start_pos),
                                                                    speed(s),
                                                                    size(sz) {
    // turn down for what
}

void Player::update(float delta_time) {

    Vector2 velocity = {0, 0};

    if (IsKeyDown(KEY_D))
        velocity.x += 1;
    if (IsKeyDown(KEY_A))
        velocity.x -= 1;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1;
    if (IsKeyDown(KEY_S))
        velocity.y += 1;

    if (velocity.x != 0 || velocity.y != 0) {
        float len = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

        if (len > 0) {
            velocity.x /= len;
            velocity.y /= len;
        }
        velocity.x *= speed;
        velocity.y *= speed;
    }

    float new_x = pos.x + velocity.x * delta_time;

    if (!tilemap->is_colliding({new_x, pos.y}, size)) {
        pos.x = new_x;
    }

    float new_y = pos.y + velocity.y * delta_time;

    if (!tilemap->is_colliding({pos.x, new_y}, size)) {
        pos.y = new_y;
    }
}

void Player::draw() {
    DrawRectangleV(pos, {size, size}, RED);
}

Vector2 Player::get_position() const {
    return pos;
}
