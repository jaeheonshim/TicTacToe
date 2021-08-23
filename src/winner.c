#include "raylib.h"
#include "game.h"

static int fontSize = 102;
static char *xWins = "X Wins!";
static char *oWins = "O Wins!";

void DisplayWinner(int winner) {
    float measure;
    if(winner == TOKEN_X) {
        measure = MeasureText(xWins, fontSize);
        DrawText(xWins, GetScreenWidth() / 2 - measure / 2, GetScreenHeight() / 2 - fontSize, fontSize, BLACK);
    } else if(winner == TOKEN_O) {
        measure = MeasureText(oWins, fontSize);
        DrawText(oWins, GetScreenWidth() / 2 - measure / 2, GetScreenHeight() / 2 - fontSize, fontSize, BLACK);
    }
}