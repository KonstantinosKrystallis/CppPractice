#ifndef Developer_h
#define Developer_h

#include <string>

class Developer
{
private:
    char *developerCode;
    std::string developerName;
    std::string developerEmail;

public:
    Developer(/* args */);
    ~Developer();
};
#endif
