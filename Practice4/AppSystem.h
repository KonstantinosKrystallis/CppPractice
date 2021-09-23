#ifndef AppSystem_h
#define AppSystem_h

#include <iostream>
#include <string>
#include <list>

#include "App.h"
#include "Developer.h"
#include "UserReview.h"

class AppSystem
{
private:
    std::list<App *> appCollection;

public:
    AppSystem();
    ~AppSystem();
    void insertGame();
    void insertOfficeApp();
    void insertDeveloper();
    void insertReview();
};
#endif
