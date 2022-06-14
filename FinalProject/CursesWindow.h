#ifndef CW_W
#define CW_W

class CursesWindow
{
private:
    int x;
    int y;

public:
    CursesWindow(); // default construct c-style things

    ~CursesWindow();

    int getx();
    int gety();
};
#endif
