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

    bool exitFlag = false;

    try
    {
        CursesWindow my_window;

        // Create maze and add player and jewel
        Maze maze = Maze(argv[1]);

        ifstream map(argv[1]);

        if (!map.good())
        {
            throw invalid_argument("Το αρχείο δεν άνοιξε. Ελεγξτε αν το αρχείο υπάρχει.\n");
        }
        else
        {
            vector<char> t;

            int w = 0, h = 0;
            char currentChar;
            while (map.get(currentChar))
            {
                if (currentChar != '\n')
                {
                    w++;
                    t.push_back(currentChar);
                }
                else
                {
                    h++;
                    w = 0;
                }
            }
            map.close();

            for (int i = 0; i < w * h; i++)
            {
                cout << t[i];
                if (i % w == 0 && i != 0)
                {
                    cout << endl;
                }
            }

            cout << w << " " << h << endl;
        }

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
                potter.makeMove(maze, 0, -1);
                break;
            case KEY_DOWN:
                potter.makeMove(maze, 0, 1);
                break;
            case KEY_LEFT:
                potter.makeMove(maze, -1, 0);
                break;
            case KEY_RIGHT:
                potter.makeMove(maze, 1, 0);
                break;
            case 32:
                potter.makeMove(maze, 0, 0);
                break;
            case KEY_EXIT:
            case 27:
                exitFlag = true;
                break;
            default:
                refresh();
            }
            // Check for winner
            if (potter.getPosY() == maze.getHeight() - 1)
            {
                potter.ShowWin(Color::white);
                exitFlag = true;
            }
        }
    }

    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }

    return 0;
}
