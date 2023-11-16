#include "player.h"
#include <raylib.h>

player::player(player_id id)
{
    this->id = id;
    posY = GetScreenHeight() / 2;
}

void player::draw()
{
    if (id == PLAYER_ONE) { DrawRectangle(size.x, posY - (size.y / 2), size.x, size.y, RAYWHITE); }
    if (id == PLAYER_TWO) { DrawRectangle(GetScreenWidth() - (size.x * 2), posY - (size.y / 2), size.x, size.y, RAYWHITE); }
}

void player::logic()
{
    if (id == PLAYER_ONE)
    {
        if (IsKeyDown(KEY_W)) { posY -= 10; }
        if (IsKeyDown(KEY_S)) { posY += 10; }
    }
    else 
    {
        if (IsKeyDown(KEY_UP)) { posY -= 10; }
        if (IsKeyDown(KEY_DOWN)) { posY += 10; }
    }
    if (posY - (size.y / 2) < 0) { posY = size.y / 2; }
    else if (posY + (size.y / 2) > GetScreenHeight()) { posY = GetScreenHeight() - (size.y / 2); }
}
