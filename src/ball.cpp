#include "ball.h"
#include <raylib.h>

// This calculates the cos and the sin in degrees instead of radians.
float cosd(float x) { return cos(fmod((x),360) * M_PI / 180); }
float sind(float x) { return sin(fmod((x),360) * M_PI / 180); }

ball::ball()
{
    reset();
}

void ball::draw()
{
    DrawCircle(pos.x, pos.y, size, RAYWHITE);
}

void ball::start()
{
    state = PLAYING;
    trajectory = GetRandomValue(20, 340);
    speed = initial_speed;
}

void ball::reset()
{
    state = INITIAL;
    pos = { (float) GetScreenWidth() / 2, (float) GetScreenHeight() / 2};
    speed = 0;
    start();
}

void ball::check_for_wall_deflect()
{
    if (pos.y - size <= 0 || pos.y + size >= GetScreenHeight()) {
        speed *= 1.05;
        trajectory = 360 - trajectory;
        if (speed >= max_speed) { speed = max_speed; }
    }
}

void ball::check_for_player_deflect(player player_one, player player_two)
{
    if (pos.x - player_one.size.x * 2 < 5 )
    {
        if (player_one.get_pos() - get_pos().y >= 0
            && player_one.get_pos() - get_pos().y <= player_one.size.y / 2) {
            trajectory = GetRandomValue(300, 360);
        }
        else if (player_one.get_pos() - get_pos().y < 0
            && get_pos().y - player_one.get_pos() <= player_one.size.y / 2) {
            trajectory = GetRandomValue(0, 60);
        }
        return; // Returns here to avoid increasing the speed if no collision was made
    }
    else if ((GetScreenWidth() - player_two.size.x * 2) - get_pos().x < 5) {
        if (player_two.get_pos() - get_pos().y >= 0
            && player_two.get_pos() - get_pos().y <= player_two.size.y / 2) {
            trajectory = GetRandomValue(180, 240);
        }
        else if (player_two.get_pos() - get_pos().y < 0
            && get_pos().y - player_two.get_pos() <= player_two.size.y / 2) {
            trajectory = GetRandomValue(120, 180);
        }
        return; // Returns here to avoid increasing the speed if no collision was made
    }
    else { return; } // Returns here to avoid increasing the speed if no collision was made
    
    speed *= 1.1;
    if (speed >= max_speed) { speed = max_speed; }
}

bool ball::in_goal()
{
    if (pos.x - size <= 0 || pos.x + size >= GetScreenWidth()) { return true; }

    return false;
}

Vector2 ball::get_pos() { return pos; }

void ball::logic(player player_one, player player_two)
{
    //      This calculates the cos & sin of the trajectory which outputs a value between -1 to 1,
    //  which is then multiplied by the speed and added to the current position.
    pos.x = (cosd(trajectory) * speed) + pos.x;
    pos.y = (sind(trajectory) * speed) + pos.y;

    check_for_wall_deflect();

    check_for_player_deflect(player_one, player_two);
}
