#include <raylib.h>
#include <cmath>
#include "ball.h"

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
    trajectory = GetRandomValue(0, 360);
    speed = initial_speed;
}

void ball::reset()
{
    state = INITIAL;
    pos = { (float) GetScreenWidth() / 2, (float) GetScreenHeight() / 2};
    speed = 0;
    start();
}

void ball::deflect()
{
    speed *= 1.05;
    trajectory = 360 - trajectory;
}

bool ball::inGoal()
{
    if (pos.x - size <= 0 || pos.x + size >= GetScreenWidth()) { return true; }

    return false;
}

void ball::logic()
{
    //      This calculates the cos & sin of the trajectory which outputs a value between -1 to 1,
    //  which is then multiplied by the speed and added to the current position.
    pos.x = (cosd(trajectory) * speed) + pos.x;
    pos.y = (sind(trajectory) * speed) + pos.y;

    //      This ensures that the ball deflects of the wall.
    if (pos.y - size <= 0 || pos.y + size >= GetScreenHeight()) {
        deflect();
    }

    if (speed >= max_speed) {
        speed = max_speed;
    }
}
