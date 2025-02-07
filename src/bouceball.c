#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void)
{
    // Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bouncing Ball Animation");
    SetTargetFPS(60);

    // Ball properties
    Vector2 ballPosition = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    Vector2 ballSpeed = {4, 3};
    float ballRadius = 20.0f;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button
    {
        // Update
        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        // Bounce off walls
        if ((ballPosition.x - ballRadius <= 0) || (ballPosition.x + ballRadius >= SCREEN_WIDTH))
        {
            ballSpeed.x *= -1;
        }
        if ((ballPosition.y - ballRadius <= 0) || (ballPosition.y + ballRadius >= SCREEN_HEIGHT))
        {
            ballSpeed.y *= -1;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(ballPosition, ballRadius, RED);
        DrawText("Bouncing Ball", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}