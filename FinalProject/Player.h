#ifndef PLAYER_H
#define PLAYER_H

#include "Maze.h"
#include "Color.h"

class Player
{
public:
    Player(int X, int Y);
    Player();
    void Show(const Color &color);

    void ShowInfo(Maze &m, const Color &color);

    void ShowWin(const Color &color);

    void makeMove(Maze &m, int X, int Y);

    int getPosX();
    int getPosY();
    int getcounter();

private:
    int x;
    int y;
    int counter;
};
#endif
