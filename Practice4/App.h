#ifndef App_h
#define App_h

#include <string>
#include <vector>

#include "Developer.h"
#include "UserReview.h"

class App
{
protected:
    char *appCode;
    std::string appDescription;
    Developer appDeveloper;
    std::vector<UserReview> appReviews;
    float appPrice;

public:
    App();
    App(char *, std::string, Developer, std::vector<UserReview>, float);
    virtual ~App();
};
#endif
