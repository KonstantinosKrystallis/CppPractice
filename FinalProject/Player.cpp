#include <iostream>
#include <random>
#include <ncurses.h>

#include "Player.h"
#include "Maze.h"

Player::Player(int X, int Y) // ructor
    : x{X}, y{Y}, counter{0}
{
}

Player::Player() : x{1}, y{0}, counter{0} {} // default ructor

void Player::Show(const Color &color)
{
    attron(COLOR_PAIR(color));
    move(y, x * 1); // x*2 cause "  " and "[]" have 2 chars
    printw("0");
    attroff(COLOR_PAIR(color));
}

void Player::ShowInfo(Maze &m, const Color &color)
{
    attron(COLOR_PAIR(color));
    move(m.getHeight() + 1, 0);
    printw("Current Position X: %i, Y: %i\nTotal moves: %i", x, y, counter);
    attroff(COLOR_PAIR(color));
}

void Player::ShowWin(const Color &color)
{
    move(0, 0);
    clear();
    refresh();
    attron(COLOR_PAIR(color));
    printw("You WIN!!!!! Total moves: %i", counter);
    getch();
    attroff(COLOR_PAIR(color));
}

void Player::makeMove(Maze &m, int X, int Y)
{
    char *mz = m.getMaze();

    if (x + X <= 0 || x + X >= m.getWidth() ||
        y + Y <= 0 || y + Y >= m.getHeight())
        return; // Check bounds

    if (mz[(y + Y) * m.getWidth() + (x + X)] == '*')
        return; // Check collisions

    x += X;
    y += Y; // Change current position
    ++counter;
}

int Player::getPosX() { return x; }
int Player::getPosY() { return y; }
int Player::getcounter() { return counter; }
