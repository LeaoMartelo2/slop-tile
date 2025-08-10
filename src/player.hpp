#ifndef PLAYER_H
#define PLAYER_H

#include "../raylib/raylib.h"
#include "gameobj.hpp"
#include "tilemap.hpp"

class Player : public GameObject {

  private:

    float speed;
    TileMap *tilemap;
    Camera2D *camera;

  public:
    
    Player(TileMap *tm, Vector2 start_pos, float s, Vector2 sz, Camera2D *cm);

    void update(float dt) override;
    void draw() override;

};

#endif // PLAYER_H
