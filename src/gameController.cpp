#include "gameController.h"

gameController::gameController() { set(); }

void gameController::set()
{
    score = 0;
    player_one.set(PLAYER_ONE);
    player_two.set(PLAYER_TWO);
}

void gameController::draw()
{
    game_ball.draw();
    player_one.draw();
    player_two.draw();
}

void gameController::logic()
{
    if (game_ball.in_goal())
    {
        score++;
        game_ball.reset();
        player_one.reset();
        player_two.reset();
    }
    
    game_ball.logic(player_one, player_two);
    player_one.logic();
    player_two.logic();
}
