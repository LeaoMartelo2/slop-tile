#include "../raylib/raylib.h"

int main(void){

    InitWindow(800, 600, "Slop-Tile");

    while (!WindowShouldClose()) {


	BeginDrawing();
	ClearBackground(BLACK);
	EndDrawing();
    
    }

    CloseWindow();


    return 0;
}
