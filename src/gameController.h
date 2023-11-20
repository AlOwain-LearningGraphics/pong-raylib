#pragma once
#include "ball.h"
#include "player.h"

class gameController {
public:
    gameController();
   
    void set();
    void logic();
    void draw();
private:
    int score;
    ball game_ball;
    player player_one;
    player player_two;
};
