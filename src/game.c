#include "game.h"

static char state[9] = {0};
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

int GameGetWinner() {
    for(int i = 0; i < 3; i++) {
        if(state[i * 3] != 0 && state[(i * 3)] == state[(i * 3) + 1] && state[(i * 3) + 1] == state[(i * 3) + 2]) return state[i * 3];
        if(state[i] != 0 && state[i] == state[i + 3] && state[i + 3] == state[i + 6]) return state[i];
    }

    if(state[0] == state[4] && state[4] == state[8]) return state[0];
    if(state[2] == state[4] && state[4] == state[6]) return state[2];

    return 0;
}

/*
0 1 2
3 4 5
6 7 8
*/