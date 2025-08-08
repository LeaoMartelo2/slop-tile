#ifndef COLIDER_H
#define COLIDER_H 

#include "../raylib/raylib.h"

struct Collider {
    Rectangle rect;
    Collider(float x, float y, float w, float h);;
};

bool aabb_collision(const Rectangle& a, const Rectangle& b);

Vector2 calculate_mtv(const Rectangle& a, const Rectangle& b);



#endif // COLIDER_H
