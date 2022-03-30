#include <iostream>
#include <string>
#include <cstring>
#include <array>

#include "Student.h"

using namespace std;

// These are the constructors
// Two argument constructor
Student::Student(const char *r, string s)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    // studentRegistryNumber = "cs161010";
    firstLastName = s;
    currentSemester = 1;
    noPassedClasses = 0;
    passedClassesGrades = NULL;
}

// Three argument constructor
Student::Student(char *r, string s, unsigned int no)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = 1;
    noPassedClasses = no;
    passedClassesGrades = NULL;
    // passedClassesGrades = (no > 0) ? new float[no] : NULL; //This is the short version of if, the Ternary Operator.
}

// Five argument constructor
Student::Student(char *r, string s, unsigned int n, unsigned int no, float *g)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = n;
    noPassedClasses = no;
    passedClassesGrades = g; // This needs to be a float array
}

// Copy constructor
Student::Student(const Student &t)
{
    int srnLen = strlen(t.studentRegistryNumber) + 1;
    studentRegistryNumber = new char[srnLen];
    memcpy(studentRegistryNumber, t.studentRegistryNumber, srnLen);
    firstLastName = t.firstLastName;
    currentSemester = t.currentSemester;
    noPassedClasses = t.noPassedClasses;
    passedClassesGrades = new float[noPassedClasses];
    memcpy(passedClassesGrades, t.passedClassesGrades, noPassedClasses * sizeof(float));
}

//============================================================================
// These are the getters
char *Student::getStudentRegistryNumber() { return studentRegistryNumber; }
string Student::getFirstLastName() { return firstLastName; }
unsigned int Student::getCurrentSemester() { return currentSemester; }
unsigned int Student::getNoPassedClasses() { return noPassedClasses; }
float *Student::getPassedClassesGrades() { return passedClassesGrades; }

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
void Student::setNoPassedClasses(unsigned int no) { noPassedClasses = no; }
void Student::setPassedClassesGrades(float *g)
{
    noPassedClasses = sizeof(+g); // Ensures the noPassedClasses is set to the size of the given array(No clue how it works but it does)
    cout << "Hi " << noPassedClasses << endl;
    passedClassesGrades = new float[noPassedClasses];
    memcpy(passedClassesGrades, g, noPassedClasses * sizeof(float));
    passedClassesGrades = g;
}

// This is the destructor
Student::~Student()
{
    delete[] studentRegistryNumber;
    delete[] passedClassesGrades;
}

//============================================================================
void Student::Print()
{
    cout << "Αριθμός Μητρώου: " << studentRegistryNumber << " "
         << "Ονοματεπώνυμο: " << firstLastName << " "
         << "Εξάμηνο: " << currentSemester << " "
         << "Αριθμός Περασμένων Μαθημάτων: " << noPassedClasses;
    int arrSize = sizeof(passedClassesGrades) / sizeof(*passedClassesGrades);
    if (noPassedClasses > 0) // Only print grades if they exist
        printGrades();
    cout << endl;
}

void Student::printGrades()
{
    cout << " || Βαθμοί: ";
    float sum = 0;
    for (int i = 0; i < noPassedClasses; i++)
    {
        sum += passedClassesGrades[i];
        cout << "Μάθημα " << i + 1 << ": " << passedClassesGrades[i] << " ";
    }
    cout << "Μέσος όρος: " << sum / noPassedClasses;
}

void Student::addGrade(float grade)
{
    noPassedClasses++;
    float *tmpArr = new float[noPassedClasses];
    memcpy(tmpArr, passedClassesGrades, (noPassedClasses - 1) * sizeof(float));
    delete[] passedClassesGrades;
    passedClassesGrades = tmpArr;
    passedClassesGrades[noPassedClasses - 1] = grade;
}