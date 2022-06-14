#include <iostream>
#include <ncurses.h>
#include "CursesWindow.h"

using namespace std;

CursesWindow::CursesWindow() : x{0}, y{0}
{
    initscr();
    if (has_colors() == FALSE)
    {
        endwin();
        cout << "Your terminal does not support colors\n";
        exit(1);
    }
    noecho();
    keypad(stdscr, TRUE);
    start_color();
    curs_set(0);
    init_pair(1, COLOR_RED, COLOR_BLACK); // must match enum class Color
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    getmaxyx(stdscr, y, x);
}

CursesWindow::~CursesWindow()
{
    endwin(); // destructor restore console at exit
}

int CursesWindow::getx() { return x; }
int CursesWindow::gety() { return y; }
