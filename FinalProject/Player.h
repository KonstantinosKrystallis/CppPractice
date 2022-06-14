#ifndef PLAYER_H
#define PLAYER_H

#include "Maze.h"
#include "Color.h"

class Player
{
public:
    Player(int xx, int yy);
    Player();
    void Show(const Color &color);

    void ShowInfo(Maze &m, const Color &color);

    void ShowWin(const Color &color);

    void mov(Maze &m, int xx, int yy);

    int getpos_x();
    int getpos_y();
    int getcounter();

private:
    int x;
    int y;
    int counter;
};
#endif
