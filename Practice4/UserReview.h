#ifndef UserReview_h
#define UserReview_h

#include <string>

class UserReview
{
private:
    float stars;
    std::string userName;
    std::string comment;

public:
    UserReview(/* args */);
    ~UserReview();
};
#endif
