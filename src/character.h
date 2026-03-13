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
    Texture2D characterTexture;
    Vector2 mapPos;
    Vector2 screenPos;
    int currentFrame;
    int currentRow;
    int maxFrame;
    int maxRow;
    int speed;
    Vector2 direction;
    float updateAnimationTime;
} Character;
Character createCharacter (const char *texturePath ,Vector2 mapPos, int maxFrame, int speed);
void drawPlayer (Character *player);
void updatePlayerPos (Character *player);
void updateCharacterAnimation (Character *player, float deltaTime);
void playerTick (float deltaTime);

void drawAIPlayer (Vector2 mapPos, Character character);

#endif