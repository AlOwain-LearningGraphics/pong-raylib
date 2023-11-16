#include "raylib.h"
#include "player.cpp"

int main(int argc, char* argv[])
{
    InitWindow(800, 600, "example");
    SetTargetFPS(60);
    
    player player_one(PLAYER_ONE);
    player player_two(PLAYER_TWO);
    while(!WindowShouldClose())
    {
        player_one.logic();
        player_two.logic();
        BeginDrawing();
            player_one.draw();
            player_two.draw();
            ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
