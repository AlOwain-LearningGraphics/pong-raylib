#pragma once
#include "raylib.h"
#include "player.h"
#include <cmath>
#include <iostream>

class ball {
public:
    const int size = 5;

    ball();

    enum ball_state {
        INITIAL,
        PLAYING
    };

    void draw();
    void logic(player player_one, player player_two);
    void reset();
    bool in_goal();
    Vector2 get_pos();
private:
    ball_state state;
    Vector2 pos;
    int trajectory;
    float speed;
    const float max_speed = 10;
    const float initial_speed = 3;
    
    void start();
    void check_for_wall_deflect();
    void check_for_player_deflect(player player_one, player player_two);
};
