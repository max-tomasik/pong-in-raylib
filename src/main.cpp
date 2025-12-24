#include "raylib.h"
#include <iostream>

int main()
{
    std::cout << "hello, world" << std::endl;

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Pong in Raylib");
    SetTargetFPS(0);

    // Player rectangle
    Rectangle LeftPlayer = {
        40,                        // x
        screenHeight / 2.0f - 40,  // y
        20,                        // width
        80                         // height
    };

    Rectangle RightPlayer = {
        40,                        // x
        screenHeight / 2.0f - 40,  // y
        20,                        // width
        80                         // height
    };

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update event for the left player
        if (IsKeyDown(KEY_W))   LeftPlayer.y -= 1.0f;
        if (IsKeyDown(KEY_S)) LeftPlayer.y += 1.0f;

        if (IsKeyDown(KEY_UP))   RightPlayer.y -= 4.0f;
        if (IsKeyDown(KEY_DOWN)) RightPlayer.y += 4.0f;

        //Collison logic for the player on the left using w and s
        if ((LeftPlayer.y + screenHeight) >= GetScreenWidth()){
            int borderhit = 0;
            borderhit += 1;
            std::cout << "border hit" << borderhit << std::endl;
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangleRec(LeftPlayer, WHITE);
        DrawRectangleRec(RightPlayer, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
