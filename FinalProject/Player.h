#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Player
{
private:
    string playerName;
    string playerColor;

public:
    // Constructors
    Player();
    Player(string, string);
    ~Player();
    // Getters
    string getPlayerName();
    string getPlayerColor();
    // Setters
    void setPlayerName(string);
    void setPlayerColor(string);
};
#endif
