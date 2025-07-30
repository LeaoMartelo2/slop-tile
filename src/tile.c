#include "tile.h"

void draw_grid(Rectangle rect) {

    float offset_width = rect.width / 4;
    float offset_height = rect.height /4;

    for (size_t i = 1; i < 4; ++i) {

        DrawLine(rect.x + i * offset_width, rect.y, rect.x + i * offset_width, rect.y + rect.height, WHITE);

        DrawLine(rect.x, rect.y + i * offset_height, rect.x + rect.width, rect.y + i * offset_height, WHITE);
    }
}

