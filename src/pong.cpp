#include "raylib.h"
#include "player.cpp"
#include "ball.cpp"

int main(int argc, char* argv[])
{
    InitWindow(800, 600, "example");
    SetTargetFPS(60);
    
    player player_one(PLAYER_ONE);
    player player_two(PLAYER_TWO);
    ball ball;

    while(!WindowShouldClose())
    {
        player_one.logic();
        player_two.logic();
        ball.logic();
        BeginDrawing();
            player_one.draw();
            player_two.draw();
            ball.draw();
            ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
