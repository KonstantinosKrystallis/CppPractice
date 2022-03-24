#include <iostream>

using namespace std;

void ChangeValueOfConst(const double &n);
void TestForNewDel();
void TestPassByReference(int &);
int &TestReturnReference(int *, int);
void TestDefaultParams(int = 1, int = 2);

int main(int argc, char *argv[])
{
    int intArray[] = {1, 3, 5, 7};

    const int number = 5;
    ChangeValueOfConst(number);
    cout << endl; // Just adding some spacing
    TestForNewDel();
    cout << endl;
    int localNumber = 2;
    cout << "Εκτύπωση LocalNumber στην main: " << localNumber << endl;
    TestPassByReference(localNumber);
    cout << "Εκτύπωση LocalNumber στην main μετά την κλήση της TestPassByReference: " << localNumber << endl;
    cout << endl;
    cout << "Εκτύπωση του 3ου στοιχείου του intArray " << TestReturnReference(intArray, 2) << endl;
    cout << endl;
    TestDefaultParams();     // Call with no params given from the user
    TestDefaultParams(5, 5); // Call with params given from the "user
    return 0;
}

#pragma region Functions(+)

void ChangeValueOfConst(const double &n)
{
    double *ptr = const_cast<double *>(&n);
    cout << "Η αρχική τιμή του αριθμού είναι: " << n << endl;
    *ptr = 3;
    cout << "Η νέα τιμή του αριθμού είναι: " << n << endl;
}

void TestForNewDel()
{
    int *ptr = new int(65);   // Creating an empty pointer with a value of 65
    int *array = new int[10]; // Creating an empty array with a size of 10

    /*Do programming things*/
    cout << "Η τιμή του ptr είναι: " << *ptr << endl;

    for (size_t i = 0; i < 10; i++)
    {
        array[i] = i + 1; // Placing i + 1 into array
        cout << "i: " << i << " | Τιμή στοιχείου: " << array[i] << endl;
    }

    delete ptr;     // Destroying ptr
    delete[] array; // Destroying array

    cout << "Εκτύπωση μετά την χρήση των delete και delete[]" << endl;
    /*
    Anything printed now is basically "random" if the data that was there is overwitten we will get "junk".
    If things work out we'll get the original data. Basically this falls under the 'Undefined behavior'.
    In reality delete does not destroy the data. It simply let's the Operating System know it does no longer uses the specified memory range.
    */
    cout << "Η τιμή του ptr = " << *ptr << endl;
    for (size_t i = 0; i < 10; i++)
    {
        array[i] = i + 1; // Placing i + 1 into array
        cout << "i: " << i << " | Τιμή στοιχείου: " << array[i] << endl;
    }
}

void TestPassByReference(int &funcLocal)
{
    cout << "Εκτύπωση του LocalNumber στην TestPassByReference πριν την αλλαγή: " << funcLocal << endl;
    funcLocal++;
    cout << "Εκτύπωση του LocalNumber στην TestPassByReference μετά την αλλαγή: " << funcLocal << endl;
}

int &TestReturnReference(int *intArray, int index)
{
    return intArray[index];
}

void TestDefaultParams(int a, int b)
{
    cout << "a = " << a << " b = " << b << " a * b = " << a * b << endl;
}

#pragma endregion