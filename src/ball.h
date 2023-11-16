#include "raylib.h"

class ball {
public:
    ball();

    enum ball_state {
        INITIAL,
        PLAYING
    };

    void draw();
    void logic();
    void reset();
    void deflect();
private:
    ball_state state;
    Vector2 pos;
    int trajectory;
    int speed;
    const int size = 5;
    const int max_speed = 10;
    const int initial_speed = 2;
    
    void start();
};
