#include "raylib.h"

static Texture2D background;
static Rectangle spot0;
static float scale;
static Vector2 position;

static Rectangle spots[9];

static void UpdateRectangles() {
    float width = background.width * scale * 0.33;
    for(int i = 0; i < 9; i++) {
        spots[i].x = position.x + (i % 3) * width;
        spots[i].y = position.y + (i / 3) * width;
        spots[i].height = width;
        spots[i].width = width;
    }
}

static void UpdateCursor() {
    Vector2 mousePosition = GetMousePosition();
    int i;
    for(i = 0; i < 9; i++) {
        if(CheckCollisionPointRec(mousePosition, spots[i])) {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            break;
        }
    }

    if(i >= 9) {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
}

void InitGameBoard() {
    background = LoadTexture("assets/background.png");
}

void UpdateGameBoard() {
    scale = (GetScreenWidth() / (float) background.width) * 0.5;

    position.x = GetScreenWidth() / 2 - (background.width * scale) / 2;
    position.y = GetScreenHeight() / 2 - (background.height * scale) / 2;

    UpdateRectangles();
    UpdateCursor();
}

void DrawGameBoard() {
    DrawTextureEx(background, position, 0, scale, WHITE);

    for(int i = 0; i < 9; i++) {
        DrawRectangleRec(spots[i], BLUE);
    }
}