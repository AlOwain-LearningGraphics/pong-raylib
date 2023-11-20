#pragma once
#include "raylib.h"

enum player_id {
    PLAYER_ONE,
    PLAYER_TWO
};

class player {
public:
    const Vector2 size = {10, 100};
    
    player();

    void set(player_id id);
    void draw();
    void logic();
    void reset();
    int get_pos();
private:
    int posY;
    player_id id;
};
