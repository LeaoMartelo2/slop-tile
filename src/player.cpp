#include "player.hpp"
#include "../raylib/raymath.h"
#include "../raylib/rlgl.h"
#include "collider.hpp"

Player::Player(TileMap *tm, Vector2 start_pos, float s, Vector2 sz, Camera2D *cmr) : speed(s),
                                                                                     tilemap(tm),
                                                                                     camera(cmr) {
    pos = start_pos;
    set_collider(sz.x, sz.y);
}

void Player::update(float dt) {

    // if it has no collider just short circuit
    if (!collider) return;

    Vector2 velocity = {0, 0};

    if (IsKeyDown(KEY_D)) velocity.x += 1;
    if (IsKeyDown(KEY_A)) velocity.x -= 1;
    if (IsKeyDown(KEY_W)) velocity.y -= 1;
    if (IsKeyDown(KEY_S)) velocity.y += 1;

    if (velocity.x != 0 || velocity.y != 0) {
        velocity = Vector2Scale(Vector2Normalize(velocity), speed);
    }

    Vector2 new_pos = Vector2Add(pos, Vector2Scale(velocity, dt));
    Rectangle intended_collider = {new_pos.x, new_pos.y, collider->rect.width, collider->rect.height};

    auto walls = tilemap->get_nearby_walls(pos.x, pos.y, collider->rect.width, collider->rect.height);

    for (const auto &wall : walls) {

        DrawCircle(wall.x, wall.y, 8, BLUE);

        if (aabb_collision(intended_collider, wall)) {
            Vector2 mtv = calculate_mtv(intended_collider, wall);
            new_pos = Vector2Add(new_pos, mtv);
            intended_collider.x = new_pos.x;
            intended_collider.y = new_pos.y;
        }
    }

    pos = new_pos;
    collider->rect.x = pos.x;
    collider->rect.y = pos.y;

    camera->target = Vector2Lerp(camera->target, get_center(), 0.3f);
}

void Player::draw() const {

    if (!collider) return;

    //   DrawRectangleRec(collider->rect, RED);
    DrawRectangleLinesEx(collider->rect, 1, RED);
}
