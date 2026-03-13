#include "character.h"

void drawPlayer (Character *player)
{
    Rectangle srcDimension = {player->currentFrame * 64/4, player->currentRow * 112/7, 64/4, 112/7};
    Rectangle desDimension = {player->mapPos.x, player->mapPos.y, 64/4*1.5, 112/7*1.5};
    Vector2 origin = {0, 0};
    DrawTexturePro(player->characterTexture, srcDimension, desDimension, origin, 0, WHITE);
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
Character createCharacter (const char *texturePath ,Vector2 mapPos, int maxFrame, int speed)
{
    int pathSize = 0;
    while (texturePath[pathSize] != '\0')
    {
        pathSize ++;
    }
    printf("_%s_ path_size %d \n", texturePath, pathSize);
    const char *walkTexturePath;
    const char *runTexturePath;
    const char *fightTexturePath;
    Character character = {
        .characterTexture = LoadTexture(texturePath),
        .mapPos = mapPos,
        .currentFrame = 3,
        .currentRow = 0,
        .maxRow = 4,
        .direction = {0 ,0},
        .speed = 2,
        .screenPos = {0 ,0},
        .maxFrame = maxFrame,
        .updateAnimationTime = 0
    };
    return (character);
}
void updateCharacterAnimation (Character *player, float deltaTime)
{
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
