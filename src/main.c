#include "globalVar.h"
#include "stdio.h"
#include "raylib.h"
#include "character.h"
#include "game.h"

int main(void)
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "MyGame - Raylib Startup");

    Character enemies[5];
    enemies[2] = createCharacter((Vector2){200, 500}, 5, 2);
    Character player = createCharacter((Vector2){200, 200}, 5, 2);
    SetTargetFPS(60);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello, Raylib!", 190, 200, 40, LIGHTGRAY);
        drawPlayer(&player);
        drawPlayer(&enemies[2]);
        updatePlayerPos(&player);
        updatePlayerPos(&enemies[2]);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}