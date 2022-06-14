#include <iostream>
#include <fstream>
#include <random>
#include <ncurses.h>

#include "Maze.h"

using namespace std;

Maze::Maze(int x, int y)
    : width{x}, height{y}
{
    maze = new char[width * height];
    for (int i = 0; i < height * width; ++i)
        maze[i] = 1;

    random_device seeder;
    mt19937 eng(seeder());
    engine = eng;
    uniform_int_distribution<int> dt(0, 3);
    dist = dt;

    // Make a maze
    maze[1 * width + 1] = 0;
    for (int y = 1; y < height; y += 2)
    {
        for (int x = 1; x < width; x += 2)
        {
            GenerateMaze(x, y);
        }
    }

    // Set up the entry and exit points.
    maze[0 * width + 1] = 0;
    maze[(height - 1) * width + (width - 2)] = 0;
}

Maze::Maze(fstream &map)
{

    while (int i = map.get() != '\n')
    {
        if (i != '\n')
        {
            ++width;
        }
        else if (i == '\n')
        {
            height++;
            width = 0; // reset for next line.
        }
    }
    if ()
    {
        /* code */
    }
    maze = new char[width * height];
}

Maze::~Maze()
{
    delete[] maze;
}

void Maze::GenerateMaze(int x, int y)
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, dx = 0, dy = 0, dir = 0, count = 0;
    dir = myrand();
    while (count < 4)
    {
        dx = 0;
        dy = 0;
        switch (dir)
        {
        case 0:
            dx = 1;
            break;
        case 1:
            dy = 1;
            break;
        case 2:
            dx = -1;
            break;
        default:
            dy = -1;
            break;
        }
        x1 = x + dx;
        y1 = y + dy;
        x2 = x1 + dx;
        y2 = y1 + dy;
        if (x2 > 0 && x2 < width && y2 > 0 && y2 < height && maze[y1 * width + x1] == 1 && maze[y2 * width + x2] == 1)
        {
            maze[y1 * width + x1] = 0;
            maze[y2 * width + x2] = 0;
            x = x2;
            y = y2;
            dir = myrand();
            count = 0;
        }
        else
        {
            dir = (dir + 1) % 4;
            count += 1;
        }
    }
}

void Maze::Show(const Color &color)
{
    attron(COLOR_PAIR(color));
    move(0, 0);
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            printw(maze[y * width + x] == 1 ? "*" : ".");
        }
        printw("\n");
    }
    attroff(COLOR_PAIR(color));
}

char *Maze::getMaze() { return maze; }
int Maze::getWidth() { return width; }
int Maze::getHeight() { return height; }
int Maze::myrand() { return dist(engine); }