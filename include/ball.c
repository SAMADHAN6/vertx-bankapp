#include "raylib.h"

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Bouncing Ball Simulation");

    Vector2 ballPosition = { screenWidth / 2, screenHeight / 2 };
    Vector2 ballSpeed = { 300.0f, 200.0f };  // Speed in pixels per second
    float ballRadius = 20.0f;

    SetTargetFPS(60); // Set the game to run at 60 frames per second

    while (!WindowShouldClose()) {
        // Update
        float deltaTime = GetFrameTime();

        // Move the ball
        ballPosition.x += ballSpeed.x * deltaTime;
        ballPosition.y += ballSpeed.y * deltaTime;

        // Check for collisions with window boundaries and reverse direction if needed
        if ((ballPosition.x - ballRadius <= 0) || (ballPosition.x + ballRadius >= screenWidth)) {
            ballSpeed.x *= -1;  // Reverse X direction
        }
        if ((ballPosition.y - ballRadius <= 0) || (ballPosition.y + ballRadius >= screenHeight)) {
            ballSpeed.y *= -1;  // Reverse Y direction
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircleV(ballPosition, ballRadius, BLUE);
        DrawText("Bouncing Ball Simulation", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
