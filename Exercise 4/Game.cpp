#include <vector>

#include "Game.h"

Game::Game()
{
}

Game::Game(char *code, std::string description, Developer developer, std::vector<UserReview> review, float price, bool online, std::string category)
{
    appCode = new char[strlen(code) + 1];
    strcpy(appCode, code);
    appDescription = description;
    appDeveloper = developer;
    appReviews = review;
    appPrice = price;
    isOnline = online;
    gameCategory = category;
}

Game::~Game()
{
}
