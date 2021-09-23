class Moving
{
private:
    struct currentPosition
    {
        int unsigned x;
        int unsigned y;
    };

    struct nextPosition
    {
        int unsigned x;
        int unsigned y;
    };

public:
    // Constructors & Destructor
    Moving(/* args */);
    ~Moving();

    // Decide on next move
    void MakeMove();
    void SetCurrentPosition();
};

Moving::Moving(/* args */)
{
}

Moving::~Moving()
{
}
