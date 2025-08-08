#include "gameobj.hpp"

GameObject::~GameObject() { delete collider; }

Vector2 GameObject::get_position() const { return pos; }

Vector2 GameObject::get_center() const {

    // if collider isnt null
    if (!collider) return pos;

    return (Vector2){pos.x + collider->rect.width / 2, pos.y + collider->rect.height / 2};
}

Collider *GameObject::get_collider() const { return collider; }

void GameObject::set_collider(float width, float height) {
    delete collider;
    collider = new Collider(pos.x, pos.y, width, height);
}
