#include "fade.h"
#include "raylib.h"

static float fadeTime = 1;
static float fadeElapsed = 0;
static int fadeInit = 0;

void FadeEffect(float time) {
    if(!fadeInit) {
        fadeTime = time;
        fadeElapsed = 0;
        fadeInit = 1;
    }
}

void ResetFade() {
    fadeInit = 0;
    fadeTime = 0;
    fadeElapsed = 0;
}

void DrawFade() {
    if(fadeInit) {
        if(fadeElapsed <= fadeTime) {
            fadeElapsed += GetFrameTime();
        }
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenWidth(), GetColor((int) ((fadeElapsed / fadeTime) * 255) + 0xFFFFFF * 256));
    }
}

float FadeRemaining() {
    return fadeTime - fadeElapsed;
}

int FadeComplete() {
    return fadeElapsed >= fadeTime && fadeInit;
}