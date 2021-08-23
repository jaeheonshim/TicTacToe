#include "raylib.h"
#include "util.h"
#include "game.h"

#define NORMAL 0
#define TEXTURE 1

static Texture2D t_background;
static Texture2D t_x;
static Texture2D t_o;

static Rectangle spot0;
static float scale;
static Vector2 position;

static Rectangle spots[9];

static char cursorState = NORMAL;
static float cursorScale = 0.20;

static void UpdateRectangles() {
    float width = t_background.width * scale * 0.33;
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
        if(CheckCollisionPointRec(mousePosition, spots[i]) && GameGetToken(i) == 0) {
            HideCursor();
            cursorState = TEXTURE;
            break;
        }
    }

    if(i >= 9) {
        ShowCursor();
        cursorState = NORMAL;
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
}

static void HandleClick() {
    Vector2 mousePosition = GetMousePosition();

    for(int i = 0; i < 9; i++) {
        if(CheckCollisionPointRec(mousePosition, spots[i])) {
            GamePlaceToken(i);
            break;
        }
    }
}

static void DrawCursorTexture() {
    Vector2 mousePosition = GetMousePosition();
    if(GameToPlay() == TOKEN_X) {
        DrawTextureEx(t_x, Vector2(mousePosition.x - t_x.width * cursorScale / 2, mousePosition.y - t_x.height * cursorScale / 2), 0, cursorScale, WHITE);
    } else if(GameToPlay() == TOKEN_O) {
        DrawTextureEx(t_o, Vector2(mousePosition.x - t_o.width * cursorScale / 2, mousePosition.y - t_o.height * cursorScale / 2), 0, cursorScale, WHITE);
    }
}

void InitGameBoard() {
    t_background = LoadTexture("assets/background.png");
    t_x = LoadTexture("assets/x.png");
    t_o = LoadTexture("assets/o.png");
}

void UpdateGameBoard() {
    scale = (GetScreenWidth() / (float) t_background.width) * 0.5;

    position.x = GetScreenWidth() / 2 - (t_background.width * scale) / 2;
    position.y = GetScreenHeight() / 2 - (t_background.height * scale) / 2;

    UpdateRectangles();
    UpdateCursor();

    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        HandleClick();
    }
}

void DrawGameBoard() {
    float width = t_background.width * scale * 0.3333;
    DrawTextureEx(t_background, position, 0, scale, WHITE);

    for(int i = 0; i < 9; i++) {
        if(GameGetToken(i) == TOKEN_O) {
            DrawTextureEx(t_o, Vector2((position.x + width * (i % 3)) + (width - t_o.width * scale) / 2, (position.y + width * (i / 3)) + (width - t_o.height * scale) / 2), 0, scale, WHITE);
        } else if(GameGetToken(i) == TOKEN_X) {
            DrawTextureEx(t_x, Vector2((position.x + width * (i % 3)) + (width - t_x.width * scale) / 2, (position.y + width * (i / 3)) + (width - t_x.height * scale) / 2), 0, scale, WHITE);
        }
    }

    if(cursorState == TEXTURE) {
        DrawCursorTexture();
    }
}