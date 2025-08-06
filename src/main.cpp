#include "../raylib/raylib.h"
#include "../raylib/raymath.h"
#include "gameobj.hpp"
#include "tilemap.hpp"
#include <cmath>
#include <vector>

int main() {

    const int screen_width = 800;
    const int screen_height = 600;

    InitWindow(screen_width, screen_height, "turn down for what");
    SetTargetFPS(60);

    float tile_size = 32;
    Tilemap tilemap(25, 19, tile_size);

    Vector2 start_pos{tile_size * 1.5f, tile_size * 1.5f};
    float player_speed = 300.0f;
    float player_size = tile_size;

    Player player(&tilemap, start_pos, player_speed, player_size);

    Camera2D camera = {0};
    camera.target = player.get_position();
    camera.offset = {screen_width / 2.0f, screen_height / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    const float camera_lerp = 0.3f;

    // make walls around the tilemap perimeter;

    for (int x = 0; x < 25; ++x) {
        tilemap.set_tile({(float)x, 0}, WALL);
        tilemap.set_tile({(float)x, 18}, WALL);
    }

    for(int y = 0; y < 19; ++y){
	tilemap.set_tile({0, (float)y}, WALL);
	tilemap.set_tile({24, (float)y}, WALL);
    }


    while (!WindowShouldClose()) {

	float dt = GetFrameTime();

	player.update(dt);

	Vector2 player_pos = player.get_position();
	camera.target = Vector2Lerp(camera.target, player_pos, camera_lerp);

	BeginDrawing();

	ClearBackground(BLACK);

	BeginMode2D(camera);

	tilemap.draw();
	player.draw();

	EndMode2D();
	EndDrawing();
    
    }

    CloseWindow();

    return 0;



    return 0;
}
