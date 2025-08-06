#include "tilemap.hpp"

Tilemap::Tilemap(int w, int h, float ts) : width(w), height(h), tile_size(ts) {
    tiles.resize(h, std::vector<TileType>(w, EMPTY));
}

TileType Tilemap::get_tile(Vector2 pos) const {

    // bounds check
    if (pos.y >= 0 && pos.y < height && pos.x >= 0 && pos.x < width) {
        return tiles[pos.y][pos.x];
    }

    // return a solid wall by default
    return WALL;
}

void Tilemap::set_tile(Vector2 pos, TileType type) {

    // bounds check
    if(pos.y >= 0 && pos.y < height && pos.x >= 0 && pos.x < width){
	tiles[pos.y][pos.x] = type;
    }
}

bool Tilemap::is_colliding(Vector2 pos, float size) const {

    float tile_x = (float)(pos.x / tile_size);
    float tile_y = (float)(pos.y / tile_size);

    float tile_x2 = (float)((pos.x + size) / tile_size);
    float tile_y2 = (float)((pos.y + size) / tile_size);

    return get_tile({tile_x, tile_y}) == WALL ||
	get_tile({tile_x2, tile_y}) == WALL ||
	get_tile({tile_x, tile_y2}) == WALL ||
	get_tile({tile_x2, tile_y2}) == WALL;
}

void Tilemap::draw() {

    for(int y = 0; y < height; ++y){
	for(int x = 0; x < width; ++x){
	    Color color;
	    if(tiles[y][x] == WALL){
		color = GRAY;
	    } else {
		color = GREEN;
	    }

	    DrawRectangle(x * tile_size, y * tile_size, tile_size, tile_size, color);
	}
    }
}
