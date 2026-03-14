#include <raylib.h>
#include <stdio.h>

typedef struct Game {
    bool isGameOver;
} Game;

Game createGame();