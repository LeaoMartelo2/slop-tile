#include "../raylib/raylib.h"
#include "../raylib/raymath.h"
#include "player.hpp"
#include "tilemap.hpp"

int main() {

    const int screen_width = 800;
    const int screen_height = 600;

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(screen_width, screen_height, "turn down for what");
    SetTargetFPS(60);

    Camera2D camera = {0};
    camera.target = {0, 0};
    camera.offset = {screen_width * 0.5, screen_height * 0.5};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    const float camera_lerp = 0.3f;


    float tile_size = 32.0f;
    TileMap tilemap(25, 19, tile_size);
    Vector2 start_pos = {tile_size * 1.5f, tile_size * 1.5f};
    float player_speed = 500.0f;
    float player_size = 64;

    Player player(&tilemap, start_pos, player_speed, {32, 64}, &camera);

    
    // borders around the map

    for (int x = 0; x < 25; ++x) {

	tilemap.set_tile(x, 0, WALL);
	tilemap.set_tile(x, 18, WALL);
    }

    for(int y = 0; y< 19; ++y) {
	tilemap.set_tile(0, y, WALL);
	tilemap.set_tile(24, y, WALL);
    }

    tilemap.set_tile(5, 5, WALL);
    tilemap.set_tile(5, 6, WALL);
    tilemap.set_tile(6, 5, WALL);


    while(!WindowShouldClose()){
	float dt = GetFrameTime();

	// player.update(dt);
	camera.target = Vector2Lerp(camera.target, player.get_center(), camera_lerp);

	BeginDrawing();
	ClearBackground(BLACK);

	BeginMode2D(camera);



	tilemap.draw();
	player.draw();


	player.update(dt);

	DrawText(TextFormat("%f, %f", player.get_position().x, player.get_position().y),
		player.get_position().x + 30, player.get_position().y + 20, 20, WHITE);

	EndMode2D();

	EndDrawing();

    }

    CloseWindow();

    return 0;
}
