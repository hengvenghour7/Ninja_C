#include "character.h"

void drawPlayer (Character *player)
{
    DrawRectangle(player->mapPos.x, player->mapPos.y, 30, 30, ORANGE);
}
void updatePlayerPos (Character *player)
{
    if (IsKeyDown(KEY_A)) {
        player->mapPos.x --;
    }
    if (IsKeyDown(KEY_D)) {
        player->mapPos.x ++;
    }
    if (IsKeyDown(KEY_W)) {
        player->mapPos.y --;
    }
    if (IsKeyDown(KEY_S)) {
        player->mapPos.y ++;
    }
}
Character createCharacter (Vector2 mapPos, int maxFrame, int speed)
{
    Character character = {
        .mapPos = mapPos,
        .currentFrame = 0,
        .direction = {0 ,0},
        .speed = 2,
        .screenPos = {0 ,0},
        .maxFrame = maxFrame,
    };
    return (character);
}
