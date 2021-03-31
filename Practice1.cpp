#include <iostream>

using namespace std;

int globalIntArray[] = {1, 3, 5, 7};

void ChangeValueOfConst(const int &n);
void TestForNewDel();
void TestPassByReference(int &);
int &TestReturnReference(int);
void TestDefaultParams(int = 1, int = 2);

int main(int argc, char *argv[])
{

    const int number = 5;
    ChangeValueOfConst(number);
    cout << endl; //Just adding some spacing
    TestForNewDel();
    cout << endl;
    int localNumber = 2;
    cout << "Printing LocalNumber in main: " << localNumber << endl;
    TestPassByReference(localNumber);
    cout << "Printing LocalNumber in main after TestPassByReference is called: " << localNumber << endl;
    cout << endl;
    cout << "Printing the 3rd element of globalIntArray " << TestReturnReference(2) << endl;
    cout << endl;
    TestDefaultParams();     //Call with no params given from the user
    TestDefaultParams(5, 5); //Call with params given from the "user
    return 0;
}

void ChangeValueOfConst(const int &n)
{
    int *ptr = const_cast<int *>(&n);
    cout << "The initial value of number is: " << n << endl;
    *ptr = 3;
    cout << "The new value of number is: " << n << endl;
}

void TestForNewDel()
{
    int *ptr = new int(65);   //Creating an empty pointer with a value of 65
    int *array = new int[10]; //Creating an empty array with a size of 10

    /*Do programming things*/
    cout << "Value of ptr = " << *ptr << endl;

    for (size_t i = 0; i < 10; i++)
    {
        array[i] = i + 1; //Placing i + 1 into array
        cout << "i: " << i << " | Element value: " << array[i] << endl;
    }

    delete ptr;     //Destroying ptr
    delete[] array; //Destroying array

    cout << "Printing after delete  and delete[]" << endl;
    /*
    Anything printed now is basicly "random" if the data that was there is overwitten we will get "junk".
    If things work out we'll get the original data. Basicly this falls under the 'Undefined behavior'.
    As explained in this stackoverflow post https://stackoverflow.com/questions/2397984/undefined-unspecified-and-implementation-defined-behavior
    In reality delete does not destroy the data. It simply let's the Operating System it does no use the specified memory range.
    */
    cout << "Value of ptr = " << *ptr << endl;
    for (size_t i = 0; i < 10; i++)
    {
        array[i] = i + 1; //Placing i + 1 into array
        cout << "i: " << i << " | Element value: " << array[i] << endl;
    }
}

void TestPassByReference(int &funcLocal)
{
    cout << "Printing LocalNumber in TestPassByReference before change: " << funcLocal << endl;
    funcLocal++;
    cout << "Printing LocalNumber in TestPassByReference after change: " << funcLocal << endl;
}

int &TestReturnReference(int index)
{
    return globalIntArray[index];
}

void TestDefaultParams(int a, int b)
{
    cout << "a = " << a << " b = " << b << " a * b = " << a * b << endl;
}
