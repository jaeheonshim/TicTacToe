#include "game.h"

static char state[9];
static char toPlay = TOKEN_X;

int GameGetToken(int i) {
    return state[i];
}

int GamePlaceToken(int i) {
    if(state[i] != 0) return 0;
    state[i] = toPlay;
    toPlay *= -1;

    return 1;
}

int GameToPlay() {
    return toPlay;
}