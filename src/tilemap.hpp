#ifndef TILEMAP_H
#define TILEMAP_H

#include "../raylib/raylib.h"
#include <vector>

enum TileType {
    EMPTY,
    WALL,
};

class TileMap {

  private:
    int width, height;
    float tile_size;
    std::vector<std::vector<TileType>> tiles;

  public:
    TileMap(int w, int h, float ts);
    TileType get_tile(int x, int y) const;
    void set_tile(int x, int y, TileType type);
    void surround_map(TileType type);
    int get_width() const;
    int get_height() const;
    float get_tile_size() const;

    std::vector<Rectangle> get_nearby_walls(float x, float y, float w, float h) const;

    void draw() const;
};

#endif // TILEMAP_H
