#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "../raylib/raylib.h"
#include "../raylib/raymath.h"
#include "tilemap.hpp"

class GameObject {
  public:
    virtual void update(float delta_time) = 0;
    virtual void draw() = 0;
    virtual Vector2 get_position() const = 0;
};


class Player : public GameObject {

    private:
	Vector2 pos;
	float speed;
	float size;
	Tilemap * tilemap;

    public:
	Player(Tilemap *tm, Vector2 start_pos, float s, float sz);
	void update(float delta_time) override;
	void draw() override;
	Vector2 get_position() const override;

};

#endif // GAMEOBJ_H
