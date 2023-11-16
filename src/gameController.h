#include "player.cpp"
#include "ball.cpp"

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
