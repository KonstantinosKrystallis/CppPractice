#include <iostream>
#include <string.h>
#include <string>
#include <new>
#include <array>

using namespace std;

class Student
{
    //The default access identifier is private and there is no real reason to include it,
    //but it is considered good practice to do so. Also I personally like to see it.
    //It makes the code easier to read.
private:
    char *studentRegistryNumber;  // Student's registry number
    string firstLastName;         // Student's name
    unsigned int currentSemester; // Student's current semester
    unsigned int noPassedClasses; //Number of passed classes
    float *passedClassesGrades;   //The grades for each passed class

public:
    //These are the constructors
    Student(const char *, string);
    Student(char *, string, unsigned int);
    Student(char *, string, unsigned int, unsigned int, float *);
    Student(const Student &);
    //These are the getters
    char *getStudentRegistryNumber();
    string getFirstLastName();
    unsigned int getCurrentSemester();
    unsigned int getNoPassedClasses();
    float *getPassedClassesGrades();
    //These are the setters
    void setStudentRegistryNumber(char *);
    void setFirstLastName(string);
    void setCurrentSemester(unsigned int);
    void setNoPassedClasses(unsigned int);
    void setPassedClassesGrades(float *);
    //This is the destructor
    ~Student();
    //This prints the student
    void Print()
    {
        cout << "Registry Number: " << studentRegistryNumber << " "
             << "Name: " << firstLastName << " "
             << "Semester: " << currentSemester << " "
             << "Passed Classes: " << noPassedClasses;
        cout << endl;
    }
};
//These are the constructors
Student::Student(const char *r, string s)
{
    studentRegistryNumber = new char[strlen(r)];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = 1;
    noPassedClasses = 0;
    passedClassesGrades = NULL;
}

Student::Student(char *r, string s, unsigned int no)
{
    studentRegistryNumber = new char[strlen(r)];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = 1;
    noPassedClasses = no;
    passedClassesGrades = NULL;
}

Student::Student(char *r, string s, unsigned int n, unsigned int no, float *g)
{
    studentRegistryNumber = new char[strlen(r)];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = n;
    noPassedClasses = no;
    passedClassesGrades = g;
}

//TODO this is not correct
Student::Student(const Student &t)
{
    memcpy(studentRegistryNumber = new char[strlen(t.studentRegistryNumber)], t.studentRegistryNumber, strlen(t.studentRegistryNumber));
    // studentRegistryNumber = t.studentRegistryNumber;
    // firstLastName = t.firstLastName;
    // currentSemester = t.currentSemester;
    // noPassedClasses = t.noPassedClasses;
    // passedClassesGrades = t.passedClassesGrades;
}

//These are the getters
char *Student::getStudentRegistryNumber() { return studentRegistryNumber; }
string Student::getFirstLastName() { return firstLastName; }
unsigned int Student::getCurrentSemester() { return currentSemester; }
unsigned int Student::getNoPassedClasses() { return noPassedClasses; }
float *Student::getPassedClassesGrades() { return passedClassesGrades; }

//These are the setters
void Student::setStudentRegistryNumber(char *r) { studentRegistryNumber = r; }
void Student::setFirstLastName(string s) { firstLastName = s; }
void Student::setCurrentSemester(unsigned int n) { currentSemester = n; }
void Student::setNoPassedClasses(unsigned int no) { noPassedClasses = no; }
void Student::setPassedClassesGrades(float *g) { passedClassesGrades = g; }

//This is the destructor
Student::~Student()
{
    delete[] studentRegistryNumber;
    delete[] passedClassesGrades;
}

int main(int argc, char *argv[])
{
    Student student1 = Student("161010", "Konstantinos Krystallis");
    //This is done to demonstrate the use of getters
    cout << "Contents of student1: ";
    student1.Print();
    cout << "Contents of student2: ";
    Student student2 = Student("171010", "Konstantinos Mpampis");
    student2.Print();
    return 0;
}
