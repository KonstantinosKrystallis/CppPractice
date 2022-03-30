#include <string>
#include <vector>

#include "AppSystem.h"
#include "Game.h"
#include "OfficeApp.h"
#include "Developer.h"
#include "UserReview.h"

AppSystem::AppSystem()
{
}

AppSystem::~AppSystem()
{
}

void AppSystem::insertGame()
{
    char *code;
    std::string description;
    Developer developer;
    std::vector<UserReview> review;
    float price;
    bool online;
    std::string category;

    //get data from user

    //Creating Object
    appCollection.push_back(new Game(code, description, developer, review, price, online, category));
}

void AppSystem::insertOfficeApp()
{
    char *code;
    std::string description;
    Developer developer;
    std::vector<UserReview> review;
    float price;
    std::string associated;

    //get data from user

    //Creating Object
    appCollection.push_back(new OfficeApp(code, description, developer, review, price, associated));
}

void AppSystem::insertDeveloper()
{
}

void AppSystem::insertReview()
{
}