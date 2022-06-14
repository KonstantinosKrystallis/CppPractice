#ifndef MAZE_H
#define MAZE_H

#include <ncurses.h>
#include "Color.h"

using namespace std;

class Maze
{
public:
    Maze(int x, int y);
    Maze(string fileName);

    ~Maze();

    void GenerateMaze(int x, int y);

    void Show(const Color &color);

    char *getMaze();
    int getWidth();
    int getHeight();
    void setWidth(int);
    void setHeight(int);
    int myrand();

private:
    int width;
    int height;
    char *maze;
    mt19937 engine;
    uniform_int_distribution<int> dist;
};
#endif