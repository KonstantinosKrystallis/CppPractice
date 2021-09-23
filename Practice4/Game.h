#ifndef Game_h
#define Game_h

#include <string>
#include "App.h"

class Game : public App
{
private:
    bool isOnline;
    std::string gameCategory;

public:
    Game();
    Game(char *, std::string, Developer, std::vector<UserReview>, float, bool, std::string);
    ~Game();
};
#endif
