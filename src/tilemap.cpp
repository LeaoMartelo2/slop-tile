#include "tilemap.hpp"
#include <cmath>

TileMap::TileMap(int w, int h, float ts) : width(w), height(h), tile_size(ts) {
    tiles.resize(h, std::vector<TileType>(w, EMPTY));
}

TileType TileMap::get_tile(int x, int y) const {

    // bounds check
    if (y >= 0 && y < height && x >= 0 && x < width) return tiles[y][x];

    // assume WALL if outside the area
    return WALL;
}

void TileMap::set_tile(int x, int y, TileType type) {

    // bounds check
    if (y >= 0 && y < height && x >= 0 && x < width) {

        tiles[y][x] = type;
    }
}

void TileMap::surround_map(TileType type) {

    for (int x = 0; x < width; ++x) {

        set_tile(x, 0, type);
        set_tile(x, width - 1, type);
    }

    for (int y = 0; y < height; ++y) {
        set_tile(0, y, type);
        set_tile(height - 1, y, type);
    }
}

int TileMap::get_width() const { return width; }
int TileMap::get_height() const { return height; }
float TileMap::get_tile_size() const { return tile_size; }

std::vector<Rectangle> TileMap::get_nearby_walls(float x, float y, float w, float h) const {

    std::vector<Rectangle> walls;

    // somehow make this shit readable lmao

    int i_min = std::max(0, (int)(std::floor((x - tile_size) / tile_size)));
    int i_max = std::min(width - 1, (int)std::floor((x + w + tile_size) / tile_size));

    int j_min = std::max(0, (int)(std::floor((y - tile_size) / tile_size)));
    int j_max = std::min(height - 1, (int)(std::floor((y + h + tile_size) / tile_size)));

    for (int j = j_min; j <= j_max; j++) {

        for (int i = i_min; i <= i_max; i++) {

            if (tiles[j][i] == WALL) {
                walls.push_back({i * tile_size, j * tile_size, tile_size, tile_size});
            }
        }
    }

    return walls;
}

void TileMap::draw() const {

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            Color color = GREEN;

            if (tiles[y][x] == WALL) {
                color = GRAY;
            }

            DrawRectangle(x * tile_size, y * tile_size, tile_size, tile_size, color);
        }
    }
}
