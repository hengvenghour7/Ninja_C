#include "globalVar.h"
#include "stdio.h"
#include "raylib.h"
#include "character.h"
#include "game.h"
#include "helpers.h"

int main(void)
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ninja_C");
    char *file = loadFile("resources/maps/main_map.tmj");
    if (file != NULL)
    {
        printf("file sucess");
    } else
    {
        printf("failed to open file_ ");
    }
    Texture2D mapTexture = LoadTexture("resources/images/main_map.png");
    Character enemies[5];
    enemies[2] = createCharacter( "resources/images/Caveman2/SeparateAnim/",(Vector2){200, 500}, 5, 1);
    Character player = createCharacter( "resources/images/Boy/SeparateAnim/",(Vector2){200, 200}, 5, 2);
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        float deltaTime = GetFrameTime();
        ClearBackground(RAYWHITE);
        Vector2 mapPos = {0, 0};
        DrawTexture(mapTexture, mapPos.x, mapPos.y, WHITE);
        drawPlayer(&player);
        drawPlayer(&enemies[2]);
        updatePlayerPos(&player);
        updateCharacterAnimation (&player, deltaTime);
        appraochCharacter(&enemies[2], &player);
        updateCharacterAnimation (&enemies[2], deltaTime);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}