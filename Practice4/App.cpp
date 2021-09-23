#include <vector>

#include "App.h"

App::App()
{
}

App::App(char *code, std::string description, Developer developer, std::vector<UserReview> review, float price)
{
    appCode = new char[strlen(code) + 1];
    strcpy(appCode, code);
    appDescription = description;
    appDeveloper = developer;
    appReviews = review;
    appPrice = price;
}

App::~App()
{
    delete[] appCode;
}
