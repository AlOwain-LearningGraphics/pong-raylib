#include "raylib.h"

enum player_id {
    PLAYER_ONE,
    PLAYER_TWO
};

class player {
public:
    player();

    void set(player_id id);
    void draw();
    void logic();
    void reset();
private:
    int posY;
    player_id id;
    const Vector2 size = {10, 100};
};
