#include "raylib.h"
#include "gameboard.h"

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Minesweeper");    
    SetTargetFPS(60);

    InitGameBoard();

    Color backgroundColor = GetColor(0x103c52FF);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(backgroundColor);

        UpdateGameBoard();
        DrawGameBoard();

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}