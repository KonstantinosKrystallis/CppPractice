// https://docs.google.com/document/d/1wjq9RxXDn78q2N9pnXMmOFRxzOvKuyqv4p1qRPuI0Ac/edit

#include <random>
#include <iostream>
#include <fstream>

#include <panel.h>
#include <ncurses.h>
#include <stdlib.h>

#include "CursesWindow.h"
#include "Player.h"
#include "Maze.h"
#include "Color.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        cout << "Μη επαρκείς παράμετροι στην γραμμή εντολών.\n";
    }

    // Read map from file
    fstream map(argv[1]);

    if (!map.is_open())
    {
        cout << "Το αρχείο δεν άνοιξε. Ελεγξτε αν το αρχείο υπάρχει.\n";
    }

    // Start sizes and increase conform screen
    // int width = 23, height = 15;
    // while (width < (my_window.getx() / 2) - 3)
    //     width += 2;
    // while (height < my_window.gety() - 4)
    //     height += 2;

    bool exitFlag = false;

    // Create maze and add player and jewel
    CursesWindow my_window;
    Maze maze = Maze(map);
    Player potter, malfoy, jewel;
    int ch = 0;
    while (!exitFlag)
    {
        maze.Show(Color::green);
        potter.Show(Color::red);
        potter.ShowInfo(maze, Color::white);
        ch = getch();
        switch (ch)
        {
        case KEY_UP:
            potter.mov(maze, 0, -1);
            break;
        case KEY_DOWN:
            potter.mov(maze, 0, 1);
            break;
        case KEY_LEFT:
            potter.mov(maze, -1, 0);
            break;
        case KEY_RIGHT:
            potter.mov(maze, 1, 0);
            break;
        case KEY_EXIT:
        case 27:
            exitFlag = true;
            break;
        default:
            refresh();
        }
        // Check for winner
        if (potter.getpos_y() == maze.getHeight() - 1)
        {
            potter.ShowWin(Color::white);
            exitFlag = true;
        }
    }

    return 0;
}
