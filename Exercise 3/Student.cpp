#include <iostream>
#include <string>
#include <cstring>
#include <array>

#include "Student.h"
#include "Course.h"

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

Student::Student(char *r, string s, unsigned int n, unsigned int no, float *g)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = n;
    noPassedClasses = no;
    passedClassesGrades = g;
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
unsigned int Student::getNoPassedClasses() { return noPassedClasses; }
float *Student::getPassedClassesGrades() { return passedClassesGrades; }
unsigned int Student::getStudentCourses() { return studentCourses; }
Course *Student::getCourses() { return courses; }

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
    passedClassesGrades = new float[noPassedClasses];
    memcpy(passedClassesGrades, g, noPassedClasses * sizeof(float));
    passedClassesGrades = g;
}
void Student::setStudentCourses(unsigned int c) { studentCourses = c; }
void Student::setCourses(Course *cs)
{
    courses = new Course[studentCourses];
    memcpy(courses, cs, studentCourses * sizeof(Course));
    courses = cs;
}

// This is the destructor
Student::~Student()
{
    delete[] studentRegistryNumber;
}

void Student::Print()
{
    cout << "Registry Number: " << studentRegistryNumber << " "
         << "Name: " << firstLastName << " "
         << "Semester: " << currentSemester << endl;
}
void Student::printGrades()
{
    float sum = 0;
    for (int i = 0; i < noPassedClasses; i++)
    {
        sum += passedClassesGrades[i];
        cout << "Class " << i + 1 << ": " << passedClassesGrades[i] << endl;
    }
    cout << "Mean grade: " << sum / noPassedClasses << endl;
}
void Student::printCourses()
{
    for (int i = 0; i < studentCourses; i++)
    {
        cout << "Course ID: "
             << courses[i].getCourseId()
             << " | Course name: "
             << courses[i].getCourseName()
             << " | Semester: "
             << courses[i].getCourseSemester()
             << endl;
    }
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

// Operators overload
void Student::operator+=(const Course &c)
{
    studentCourses++;
    realloc(courses, studentCourses); // Resizing Initial array
    courses[studentCourses - 1] = c;  // Appending new element
}

int Student::operator==(const Student &s) { return (s.currentSemester == currentSemester); }
int Student::operator!=(const Student &s) { return (s.currentSemester != currentSemester); }
int Student::operator<(const Student &s) { return (s.currentSemester < currentSemester); }
int Student::operator<=(const Student &s) { return (s.currentSemester <= currentSemester); }
int Student::operator>(const Student &s) { return (s.currentSemester > currentSemester); }
int Student::operator>=(const Student &s) { return (s.currentSemester >= currentSemester); }

ostream &operator<<(ostream &os, const Student &s)
{
    os << "Registry Number: " << s.studentRegistryNumber << " | Name: " << s.firstLastName;
    return os;
}

//============================================================================
void Student::Print()
{
    cout << "Αριθμός Μητρώου: " << studentRegistryNumber << " "
         << "Ονοματεπώνυμο: " << firstLastName << " "
         << "Εξάμηνο: " << currentSemester << endl;
}

void Student::IncreaseSemester()
{
    currentSemester++;
}