#include "raylib.h"
#include "game.h"
#include "gameboard.h"
#include "winner.h"
#include "fade.h"

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Minesweeper");    
    SetTargetFPS(60);

    InitGameBoard();

    Color backgroundColor = WHITE;

    while (!WindowShouldClose())
    {
        float delta = GetFrameTime();
        BeginDrawing();

        ClearBackground(backgroundColor);

        if(!FadeComplete()) {
            UpdateGameBoard();
            DrawGameBoard();
        }

        if(GameGetWinner() != 0) {
            FadeEffect(0.5);
            if(FadeComplete()) {
                DisplayWinner(GameGetWinner());
            } else {
                DrawFade();
            }
        }

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}