#ifndef MAZE_H
#define MAZE_H

#include <ncurses.h>
#include "Color.h"

using namespace std;

class Maze
{
public:
    Maze(int x, int y);
    Maze(fstream &map);

    // Maze(Maze &) = delete;             // disable copy ructor
    // Maze &operator=(Maze &) = delete;  // disable copy assignment
    // Maze(Maze &&) = delete;            // disable move ructor
    // Maze &operator=(Maze &&) = delete; // disable move assignment

    ~Maze(); // destructor

    void GenerateMaze(int x, int y);

    void Show(const Color &color);

    char *getMaze();
    int getWidth();
    int getHeight();
    int myrand();

private:
    int width;
    int height;
    char *maze;
    mt19937 engine;
    uniform_int_distribution<int> dist;
};
#endif