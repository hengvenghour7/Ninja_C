#include "stdio.h"
#include "raylib.h"
#include "game.h"

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "MyGame - Raylib Startup");

    // Set target FPS
    SetTargetFPS(60);

    // Game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        // TODO: Add game logic here

        printTest();
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello, Raylib!", 190, 200, 40, LIGHTGRAY);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}