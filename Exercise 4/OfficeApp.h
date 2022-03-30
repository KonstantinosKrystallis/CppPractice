#ifndef OfficeApp_h
#define OfficeApp_h

#include <string>
#include <vector>

#include "App.h"

class OfficeApp : public App
{
private:
    std::string associatedFileTypes;

public:
    OfficeApp();
    OfficeApp(char *, std::string, Developer, std::vector<UserReview>, float, std::string);
    ~OfficeApp();
};
#endif