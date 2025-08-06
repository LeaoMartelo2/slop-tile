#ifndef TILEMAP_H
#define TILEMAP_H

#include "../raylib/raylib.h"
#include <vector>

enum TileType {
    EMPTY,
    WALL
};

class Tilemap {

    private:
	int width, height;
	float tile_size;
	std::vector<std::vector<TileType>> tiles;

    public:
	Tilemap(int w, int h, float ts);
	TileType get_tile(Vector2 pos) const;
	void set_tile(Vector2 pos, TileType type);

	bool is_colliding(Vector2 pos, float size) const;


	void draw();

};

#endif // TILEMAP_H
