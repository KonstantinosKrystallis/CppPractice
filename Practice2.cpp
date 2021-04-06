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
    //This prints the first three atributes of the student
    void Print();
    void printGrades();
    void addGrade(float);
};
//These are the constructors
Student::Student(const char *r, string s)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    //studentRegistryNumber = "cs161010";
    firstLastName = s;
    currentSemester = 1;
    noPassedClasses = 0;
    passedClassesGrades = NULL;
}

Student::Student(char *r, string s, unsigned int no)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = 1;
    noPassedClasses = no;
    passedClassesGrades = NULL;
    //passedClassesGrades = (no > 0) ? new float[no] : NULL; //This is the short version of if, the Ternary Operator.
}

Student::Student(char *r, string s, unsigned int n, unsigned int no, float *g)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    firstLastName = s;
    currentSemester = n;
    noPassedClasses = no;
    passedClassesGrades = g; //This needs to be a float array
}

//Copy constructor
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
//These are the getters
char *Student::getStudentRegistryNumber() { return studentRegistryNumber; }
string Student::getFirstLastName() { return firstLastName; }
unsigned int Student::getCurrentSemester() { return currentSemester; }
unsigned int Student::getNoPassedClasses() { return noPassedClasses; }
float *Student::getPassedClassesGrades() { return passedClassesGrades; }

//These are the setters
void Student::setStudentRegistryNumber(char *r)
{
    int srnLen = strlen(r) + 1;
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

//This is the destructor
Student::~Student()
{
    delete[] studentRegistryNumber;
    delete[] passedClassesGrades;
}

//============================================================================
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

void Student::addGrade(float grade)
{
    noPassedClasses++;
    float *tmpArr = new float[noPassedClasses];
    memcpy(tmpArr, passedClassesGrades, (noPassedClasses - 1) * sizeof(float));
    delete[] passedClassesGrades;
    passedClassesGrades = tmpArr;
    passedClassesGrades[noPassedClasses - 1] = grade;
}

//----------------------------------MAIN----------------------------------------------//

int main(int argc, char *argv[])
{
    Student student1 = Student("cs161010", "Konstantinos Krystallis");
    Student student2 = Student(student1);
    Student student3 = student1;

    //Demostrating that the copy constructor in fact create a deep copy of student 1
    cout << "Contents of student1: ";
    student1.Print();
    cout << "Contents of student2: ";
    student2.Print();
    cout << "Contents of student3: ";
    student3.Print();

    //Changing some of the values to demonstrate the use of setters
    student1.setStudentRegistryNumber("cs171010"); //The compiler throws a warning for this, but that never stopped anyone from doing anything
    student1.setFirstLastName("Joe Doe");
    student2.setCurrentSemester(6);
    student3.setNoPassedClasses(4);
    float grades[] = {5, 8.5, 7, 5.95};
    student3.setPassedClassesGrades(grades);

    //Printing the changes
    cout << "======================= SETTERS =========================\n";
    cout << "Contents of student1: ";
    student1.Print();
    cout << "Grades of student1: \n";
    student1.printGrades();
    cout << "Contents of student2: ";
    student2.Print();
    cout << "Grades of student2: \n";
    student2.printGrades();
    cout << "Contents of student3: ";
    student3.Print();
    cout << "Grades of student3: \n";
    student3.printGrades();

    //Adding grades to student 1
    cout << "======================== ADD GRADE ========================\n";
    student1.addGrade(7.2);
    student1.addGrade(5);
    student1.addGrade(9.5);
    cout << "Contents of student1: ";
    student1.Print();
    cout << "Grades of student1: \n";
    student1.printGrades();

    //Using gettter to print student1
    cout << "========================= GETTERS =======================\n";
    cout << "Contents of student1: ";
    cout << "Registry Number: " << student1.getStudentRegistryNumber() << " "
         << "Name: " << student1.getFirstLastName() << " "
         << "Semester: " << student1.getCurrentSemester() << " "
         << "Number of passed classes: " << student1.getNoPassedClasses() << "\n";
    if (student1.getPassedClassesGrades() != NULL)
    {
        cout << "Grades: \n";
        int t = student1.getNoPassedClasses();
        float *temp = new float[student1.getNoPassedClasses()];
        memcpy(temp, student1.getPassedClassesGrades(), t * sizeof(float));
        for (int i = 0; i < t; i++)
        {
            cout << "Class " << i + 1 << ": " << temp[i] << endl;
        }
    }

    return 0;
}
