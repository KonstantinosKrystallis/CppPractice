#include <iostream>
#include <array>
#include <cstring>
#include <string>

#include "Course.h"
#include "Student.h"

using namespace std;

// Default constructor
Student::Student()
{
    studentRegistryNumber = new char[3];
    strcpy(studentRegistryNumber, "Χωρίς ΑΜ");
    firstLastName = "Χωρίς Ονοματεπώνυμο";
    currentSemester = 1;
    noPassedClasses = 0;
    passedClassesGrades = new float[0];
    studentCoursesCount = 0;
    courses = new Course[0];
}
// Two argument constructor
Student::Student(const char *r, string s)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = 1;
    noPassedClasses = 0;
    passedClassesGrades = new float[0];
    studentCoursesCount = 0;
    courses = new Course[0];
}
// Three argument constructor
Student::Student(char *r, string s, unsigned int no)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = no;
    noPassedClasses = 0;
    studentCoursesCount = 0;
}
Student::Student(char *r, string s, unsigned int n, unsigned int no, float *g)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = n;
    noPassedClasses = no;
    passedClassesGrades = new float[no];
    for (int i = 0; i < no; i++)
    {
        passedClassesGrades[i] = g[i];
    }
    studentCoursesCount = 0;
    courses = new Course[0];
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
    if (t.noPassedClasses > 0)
    {
        passedClassesGrades = new float[t.noPassedClasses];
        memcpy(passedClassesGrades, t.passedClassesGrades, t.noPassedClasses);
    }
    else
    {
        passedClassesGrades = new float[0];
    }
    studentCoursesCount = t.studentCoursesCount;
    if (t.studentCoursesCount > 0)
    {
        courses = new Course[t.studentCoursesCount];
        memcpy(courses, t.courses, t.studentCoursesCount);
    }
    else
    {
        courses = new Course[0];
    }
}

//============================================================================
// These are the getters
char *Student::getStudentRegistryNumber() { return studentRegistryNumber; }
string Student::getFirstLastName() { return firstLastName; }
unsigned int Student::getCurrentSemester() { return currentSemester; }
unsigned int Student::getNoPassedClasses() { return noPassedClasses; }
float *Student::getPassedClassesGrades() { return passedClassesGrades; }
unsigned int Student::getStudentCoursesCount() { return studentCoursesCount; }
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
void Student::setStudentCoursesCount(unsigned int c) { studentCoursesCount = c; }
void Student::setCourses(Course *cs)
{
    courses = new Course[studentCoursesCount];
    memcpy(courses, cs, studentCoursesCount * sizeof(Course));
    courses = cs;
}

// This is the destructor
Student::~Student()
{
    delete[] studentRegistryNumber;
    delete[] passedClassesGrades;
    delete[] courses;
}

void Student::Print()
{
    cout << "Αριθμός Μητρώου: " << studentRegistryNumber << " "
         << "Ονοματεπώνυμο: " << firstLastName << " "
         << "Εξάμηνο: " << currentSemester << endl;
}
void Student::Print(ostream &os)
{
    os << "Αριθμός Μητρώου: " << studentRegistryNumber << " "
       << "Ονοματεπώνυμο: " << firstLastName << " "
       << "Εξάμηνο: " << currentSemester << endl;
}
void Student::printGrades()
{
    string output;
    float sum = 0;

    for (int i = 0; i < noPassedClasses; i++)
    {
        sum += passedClassesGrades[i];
        output.append("Μάθημα %d: %f\n", i + 1, passedClassesGrades[i]);
    }
    output.append("Μέσος όρος Μαθημάτων: %f\n", sum / noPassedClasses);

    cout << output;
}
void Student::printCourses()
{
    for (int i = 0; i < studentCoursesCount; i++)
    {
        cout << "Κωδικός Μαθήματος: "
             << courses[i].getCourseId()
             << " | Τίτλος Μαθήματος: "
             << courses[i].getCourseName()
             << " | Εξάμηνο: "
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
void Student::IncreaseSemester()
{
    currentSemester++;
}

// Operators overload
void Student::operator+=(const Course &c)
{
    studentCoursesCount++;
    realloc(courses, studentCoursesCount); // Resizing Initial array
    courses[studentCoursesCount - 1] = c;  // Appending new element
}

int Student::operator==(const Student &s) { return (s.currentSemester == currentSemester); }
int Student::operator!=(const Student &s) { return (s.currentSemester != currentSemester); }
int Student::operator<(const Student &s) { return (s.currentSemester < currentSemester); }
int Student::operator<=(const Student &s) { return (s.currentSemester <= currentSemester); }
int Student::operator>(const Student &s) { return (s.currentSemester > currentSemester); }
int Student::operator>=(const Student &s) { return (s.currentSemester >= currentSemester); }

ostream &operator<<(ostream &os, const Student &s)
{
    string output = "";
    float sum = 0;
    if (s.noPassedClasses == 0)
    {
        os << "Ο μαθητής " + s.firstLastName + " δεν έχει περασμένα μαθήματα" << endl;
    }
    else
    {
        os << "Φοιτητής/τρια: " << s.firstLastName << endl;
        os << "Βαθμοί Περασμένων Μαθημάτων(" << s.noPassedClasses << "): \n";
        for (int i = 0; i < s.noPassedClasses; i++)
        {
            sum += s.passedClassesGrades[i];
            os << "\t " << i + 1 << ": " << s.passedClassesGrades[i] << endl;
        }
        os << "Μέσος όρος: " << sum / s.noPassedClasses << endl;
    }

    return os;
}
