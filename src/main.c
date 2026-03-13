#include "globalVar.h"
#include "stdio.h"
#include "raylib.h"
#include "character.h"
#include "game.h"

int main(void)
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "MyGame - Raylib Startup");

    Character enemies[5];
    enemies[2] = createCharacter( "resources/images/character_2.png",(Vector2){200, 500}, 5, 2);
    Character player = createCharacter( "resources/images/boy/Walk.png",(Vector2){200, 200}, 5, 2);
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        float deltaTime = GetFrameTime();
        ClearBackground(RAYWHITE);

        drawPlayer(&player);
        drawPlayer(&enemies[2]);
        updatePlayerPos(&player);
        updateCharacterAnimation (&player, deltaTime);
        updatePlayerPos(&enemies[2]);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}