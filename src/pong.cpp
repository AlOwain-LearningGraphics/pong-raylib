#include "raylib.h"
#include "gameController.cpp"

int main(int argc, char* argv[])
{
    InitWindow(800, 600, "example");
    SetTargetFPS(60);
    
    gameController game;

    while(!WindowShouldClose())
    {
        game.logic();
        BeginDrawing();
            game.draw();
            ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
