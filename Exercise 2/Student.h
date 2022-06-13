#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
    // The default access identifier is private and there is no real reason to include it,
    // but it is considered good practice to do so. Also I personally like to see it.
    // It makes the code easier to read.
private:
    char *studentRegistryNumber;  // Student's registry number
    string firstLastName;         // Student's name
    unsigned int currentSemester; // Student's current semester

public:
    // These are the constructors
    Student();
    Student(const char *, string);
    Student(char *, string, unsigned int);
    Student(const Student &);

    // These are the getters
    char *getStudentRegistryNumber();
    string getFirstLastName();
    unsigned int getCurrentSemester();

    // These are the setters
    void setStudentRegistryNumber(char *);
    void setFirstLastName(string);
    void setCurrentSemester(unsigned int);

    ~Student(); // This is the destructor

    void Print(); // This prints the first three atributes of the student
    void IncreaseSemester();
};
#endif
