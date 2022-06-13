// https://docs.google.com/document/d/1wjq9RxXDn78q2N9pnXMmOFRxzOvKuyqv4p1qRPuI0Ac/edit

#include <random>
#include <iostream>
#include <fstream>

#include <panel.h>
#include <ncurses.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        cout << "Μη επαρκείς παράμετροι στην γραμμή εντολών.\n";
    }
    fstream map(argv[1]);
    if (!map.is_open())
    {
        cout << "Το αρχείο δεν άνοιξε. Ελεγξτε αν το αρχείο υπάρχει.\n";
    }
    cout << map.rdbuf() << endl;

    return 0;
}
