#include "../raylib/raylib.h"
#include "../raylib/raymath.h"
#include "tile.h"
#include <stddef.h>

int main(void) {

    Rectangle rect = {0};

    InitWindow(800, 600, "Slop-Tile");
    SetTargetFPS(60);

    Vector2 screen_half = (Vector2){GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f};

    rect.width = 600;
    rect.height = 500;
    rect.x = screen_half.x / 4;
    rect.y = screen_half.y / 4;

    Vector2 pos_1 = {300, 300};
    Vector2 pos_2 = {600, 300};

    Vector2 plr_pos = pos_1;

    float i = 0;

    bool is_right = false;

    float test = 0;

    float anim_time = 0;

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_D)) {
            is_right = true;
            anim_time = 0;
        }

        if (IsKeyPressed(KEY_A)) {
            is_right = false;
            anim_time = 0;
        }

        if (is_right) {
            if (anim_time < 1) {
                anim_time += GetFrameTime() * 8;
            }
            plr_pos = Vector2Lerp(pos_1, pos_2, anim_time);

            if (anim_time > 1) {
                anim_time = 1;
            }
        }

        if (!is_right) {
            if (anim_time < 1) {
                anim_time += GetFrameTime() * 8;
            }
            plr_pos = Vector2Lerp(pos_2, pos_1, anim_time);

            if (anim_time > 1) {
                anim_time = 1;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        //        DrawRectangleLinesEx(rect, 1, WHITE);

        DrawCircleV(pos_1, 5, RED);
        DrawCircleV(pos_2, 5, BLUE);

        DrawCircleV(plr_pos, 10, GREEN);

        DrawText(TextFormat("%f", test),
                 plr_pos.x, plr_pos.y + 15, 20, WHITE);

        DrawText(TextFormat("%f", anim_time), 5, 5, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
