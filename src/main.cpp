#include "../raylib/raylib.h"

int main(void) {

    InitWindow(800, 600, "teste");

    while (!WindowShouldClose()) {

        BeginDrawing();
        {
            ClearBackground(BLACK);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
