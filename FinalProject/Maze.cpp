#include <iostream>
#include <fstream>
#include <random>
#include <ncurses.h>

#include "Maze.h"

using namespace std;

Maze::Maze(string fileName)
{
    ifstream map(fileName);

    if (!map.is_open())
    {
        throw invalid_argument("Το αρχείο δεν άνοιξε. Ελεγξτε αν το αρχείο υπάρχει.\n");
    }
    else
    {
        vector<char> t;
        char currentChar;
        height = width = 0;
        while (map.get(currentChar))
        {
            if (currentChar != '\n')
            {
                t.push_back(currentChar);
                width++;
            }
            else
            {
                height++;
                width = 0;
            }
        }
        height++;

        maze = new char[width * height];

        for (int i = 0; i < width * height; i++)
        {
            maze[i] = t[i];
        }

        map.close();
    }
}

Maze::~Maze() { delete[] maze; }

void Maze::Show(const Color &color)
{
    attron(COLOR_PAIR(color));
    move(0, 0);
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            printw(maze[y * width + x] == '*' ? "*" : ".");
        }
        printw("\n");
    }
    attroff(COLOR_PAIR(color));
}

char *Maze::getMaze() { return maze; }
int Maze::getWidth() { return width; }
int Maze::getHeight() { return height; }
void Maze::setWidth(int w) { width = w; }
void Maze::setHeight(int h) { height = h; }
int Maze::myrand() { return dist(engine); }