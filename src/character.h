#ifndef CHARACTER_H
#define CHARACTER_H

#include <raylib.h>
#include <stdio.h>

typedef enum DirectionState {
    Left,
    Right,
    Up,
    Down
} DirectionState;
typedef struct Character {
    Vector2 mapPos;
    Vector2 screenPos;
    int currentFrame;
    int maxFrame;
    int speed;
    Vector2 direction;
} Character;
Character createCharacter (Vector2 mapPos, int maxFrame, int speed);
void drawPlayer (Character *player);
void updatePlayerPos (Character *player);

void drawAIPlayer (Vector2 mapPos, Character character);

#endif