#include "raylib.h"

static Texture2D background;
static Rectangle spot0;
static float scale;
static Vector2 position;

static void UpdateRectangles() {
    spot0.x = position.x;
    spot0.y = position.y;
    spot0.height = background.width * scale * 0.33;
    spot0.width = background.width * scale * 0.33;
}

static void UpdateCursor() {
    Vector2 mousePosition = GetMousePosition();
    if(CheckCollisionPointRec(mousePosition, spot0)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    } else {
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
    DrawRectangleRec(spot0, RED);
}