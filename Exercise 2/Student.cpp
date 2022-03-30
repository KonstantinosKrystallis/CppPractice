#include <iostream>
#include <string>
#include <cstring>
#include <array>

#include "Student.h"

using namespace std;

// Default constructor
Student::Student()
{
    studentRegistryNumber = new char[3];
    strcpy(studentRegistryNumber, "Χωρίς ΑΜ");
    firstLastName = "Χωρίς Ονοματεπώνυμο";
    currentSemester = 1;
}

// Two argument constructor
Student::Student(const char *r, string s)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = 1;
}

// Three argument constructor
Student::Student(char *r, string s, unsigned int no)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = 1;
}

// Copy constructor
Student::Student(const Student &t)
{
    int srnLen = strlen(t.studentRegistryNumber) + 1;
    studentRegistryNumber = new char[srnLen];
    memcpy(studentRegistryNumber, t.studentRegistryNumber, srnLen);
    firstLastName = t.firstLastName;
    currentSemester = t.currentSemester;
}

//============================================================================
// These are the getters
char *Student::getStudentRegistryNumber() { return studentRegistryNumber; }
string Student::getFirstLastName() { return firstLastName; }
unsigned int Student::getCurrentSemester() { return currentSemester; }

// These are the setters
void Student::setStudentRegistryNumber(char *r)
{
    int srnLen = strlen(r) + 1;
    delete studentRegistryNumber;
    studentRegistryNumber = new char[srnLen];
    memcpy(studentRegistryNumber, r, srnLen);
}
void Student::setFirstLastName(string s) { firstLastName = s; }
void Student::setCurrentSemester(unsigned int n) { currentSemester = n; }

// This is the destructor
Student::~Student()
{
    delete[] studentRegistryNumber;
}

//============================================================================
void Student::Print()
{
    cout << "Αριθμός Μητρώου: " << studentRegistryNumber << " "
         << "Ονοματεπώνυμο: " << firstLastName << " "
         << "Εξάμηνο: " << currentSemester << endl;
}

void Student::IncreasSemester()
{
    currentSemester++;
}