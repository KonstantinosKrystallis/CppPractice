#include <iostream>
#include <random>
#include <ncurses.h>

#include "Player.h"
#include "Maze.h"

Player::Player(int xx, int yy) // ructor
    : x{xx}, y{yy}, counter{0}
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

void Player::mov(Maze &m, int xx, int yy)
{
    static auto mz = m.getMaze();

    if (x + xx <= 0 || x + xx >= m.getWidth() ||
        y + yy <= 0 || y + yy >= m.getHeight())
        return; // Check bounds

    if (mz[(y + yy) * m.getWidth() + (x + xx)] == 1)
        return; // Check collisions

    x += xx;
    y += yy; // Change current position
    ++counter;
}

int Player::getpos_x() { return x; }
int Player::getpos_y() { return y; }
int Player::getcounter() { return counter; }
