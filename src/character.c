#include "character.h"
#include <raymath.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void drawPlayer (Character *player)
{
    Rectangle srcDimension = {player->currentFrame * 64/4, player->currentRow * 112/7, 64/4, 112/7};
    Rectangle desDimension = {player->mapPos.x, player->mapPos.y, 64/4*1.5, 112/7*1.5};
    Vector2 origin = {0, 0};
    DrawTexturePro(*player->characterTexture, srcDimension, desDimension, origin, 0, WHITE);
}
void updatePlayerPos (Character *player)
{
    player->direction = (Vector2){0, 0};
    if (IsKeyDown(KEY_A)) {
        player->direction.x = -1;
    }
    if (IsKeyDown(KEY_D)) {
        player->direction.x = 1;
    }
    if (IsKeyDown(KEY_W)) {
        player->direction.y = -1;
    }
    if (IsKeyDown(KEY_S)) {
        player->direction.y = 1;
    }
    player->direction = Vector2Scale(Vector2Normalize(player->direction), player->speed);
    
    player->mapPos = Vector2Add(player->mapPos, player->direction);
}
Character createCharacter (const char *texturePath ,Vector2 mapPos, int maxFrame, int speed)
{
    int pathSize = 0;
    while (texturePath[pathSize] != '\0')
    {
        pathSize ++;
    }
    
    char *walk_w = "Walk.png";
    char *attack_w = "Attack.png";
    char *idle_w = "Idle.png";
    char *walkTexturePath = malloc(strlen(texturePath) + strlen(walk_w) + 1);
    char *idleTexturePath = malloc(strlen(texturePath) + strlen(attack_w) + 1);
    char *attackTexturePath = malloc(strlen(texturePath) + strlen(idle_w) + 1);
    strcpy(walkTexturePath, texturePath);
    strcat(walkTexturePath, walk_w);
    strcpy(idleTexturePath, texturePath);
    strcat(idleTexturePath, idle_w);
    strcpy(attackTexturePath, texturePath);
    strcat(attackTexturePath, attack_w);
    
    printf("_%s_ path_size %d \n", walkTexturePath, pathSize);
    Character character = {
        .walkTexture = LoadTexture(walkTexturePath),
        .idleTexture = LoadTexture(idleTexturePath),
        .attackTexture = LoadTexture(attackTexturePath),
        .mapPos = mapPos,
        .currentFrame = 3,
        .currentRow = 0,
        .maxRow = 4,
        .direction = {0 ,0},
        .speed = speed,
        .screenPos = {0 ,0},
        .maxFrame = maxFrame,
        .updateAnimationTime = 0,
        .characterState = Walking,
    };

    character.characterTexture = &character.walkTexture;
    free(walkTexturePath);
    free(idleTexturePath);
    free(attackTexturePath);
    return (character);
}
void updateCharacterAnimation (Character *player, float deltaTime)
{
    if (player->direction.x == 0 && player->direction.y == 0)
    {
        changeCharacterTexture(player, Idling);
    }
    else{
        changeCharacterTexture(player, Walking);
    }
    if (player->updateAnimationTime > 0.2)
    {
        player->updateAnimationTime = 0;
        player->currentRow++;
        if (player->currentRow >= player->maxRow)
        {
            player->currentRow = 0;
        }
    }
    player->updateAnimationTime += deltaTime;
}
void changeCharacterTexture (Character *character, CharacterState state)
{
    if (character->characterState == state)
    {
        return;
    }
    else
    {
        character->characterState = state;
    }
    switch (state)
    {
    case Attacking:
        character->characterTexture = &character->attackTexture;
        break;
    case Walking:
        character->characterTexture = &character->walkTexture;
        break;
    case Idling:
        character->characterTexture = &character->idleTexture;
        break;
    default:
        character->characterTexture = &character->walkTexture;
        break;
    }
}
void appraochCharacter (Character *AIPlayer, Character *player)
{
    AIPlayer->direction = Vector2Normalize(Vector2Subtract(player->mapPos, AIPlayer->mapPos));
    AIPlayer->mapPos = Vector2Add(AIPlayer->mapPos, Vector2Scale(AIPlayer->direction, AIPlayer->speed));
}