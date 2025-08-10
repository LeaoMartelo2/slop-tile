#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "../raylib/raylib.h"
#include "collider.hpp"

class GameObject {

  protected:
    Vector2 pos;
    Collider *collider = nullptr;

  public:
    virtual ~GameObject();
    virtual void update(float dt) = 0;
    virtual void draw() const = 0;
    virtual Vector2 get_position() const;
    virtual Vector2 get_center() const;

    Collider *get_collider() const;
    void set_collider(float width, float height);
};

#endif // GAMEOBJ_H
