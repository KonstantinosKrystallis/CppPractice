#include <string>
#include <vector>

#include "OfficeApp.h"

OfficeApp::OfficeApp()
{
}

OfficeApp::OfficeApp(char *code, std::string description, Developer developer, std::vector<UserReview> review, float price, std::string associated)
{
    appCode = new char[strlen(code) + 1];
    strcpy(appCode, code);
    appDescription = description;
    appDeveloper = developer;
    appReviews = review;
    appPrice = price;
    associatedFileTypes = associated;
}

OfficeApp::~OfficeApp()
{
}
