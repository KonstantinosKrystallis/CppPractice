#include <iostream>
#include <string.h>
#include <string>
#include <new>
#include <array>

using namespace std;

class Course
{
private:
    string courseId;
    string courseName;
    unsigned int courseSemester;

public:
    //Construstors
    Course();
    Course(string, string, unsigned int);
    ~Course();
    //Getters
    string getCourseId();
    string getCourseName();
    unsigned int getCourseSemester();
    //Setters
    void setCourseId(string);
    void setCourseName(string);
    void setCourseSemester(unsigned int);
};

class Student
{
    //The default access identifier is private and there is no real reason to include it,
    //but it is considered good practice to do so. Also I personally like to see it.
    //It makes the code easier to read.
private:
    char *studentRegistryNumber;  // Student's registry number
    string studentName;           // Student's name
    unsigned int studentSemester; // Student's current semester
    unsigned int noPassedClasses; //Number of passed classes
    float *passedClassesGrades;   //The grades for each passed class
    unsigned int studentCourses;  // The number of courses the student is attending in a semester
    Course *courses;              // The list of courses the student is attending in a semester

public:
    //These are the constructors
    Student(const char *, string);
    Student(char *, string, unsigned int);
    Student(char *, string, unsigned int, unsigned int, float *);
    Student(const Student &);
    //These are the getters
    char *getStudentRegistryNumber();
    string getstudentName();
    unsigned int getstudentSemester();
    unsigned int getNoPassedClasses();
    float *getPassedClassesGrades();
    unsigned int getstudentCourses();
    Course *getCourses();
    //These are the setters
    void setStudentRegistryNumber(char *);
    void setstudentName(string);
    void setstudentSemester(unsigned int);
    void setNoPassedClasses(unsigned int);
    void setPassedClassesGrades(float *);
    void setStudentCourses(unsigned int);
    void setCourses(Course *);
    //This is the destructor
    ~Student();
    //This prints the first three atributes of the student
    void Print();
    void printGrades();
    void printCourses();
    void addGrade(float);
    //Operators
    void operator+=(const Course &);
    int operator==(const Student &);
    int operator!=(const Student &);
    int operator<(const Student &);
    int operator<=(const Student &);
    int operator>(const Student &);
    int operator>=(const Student &);
    friend ostream &operator<<(ostream &, const Student &);
};

//===============================COURSE===============================//
//Constructors
Course::Course() {}
Course::Course(string id, string name, unsigned int semester)
{
    courseId = id;
    courseName = name;
    courseSemester = semester;
}
//Destructor
Course::~Course() {}

//Getters
string Course::getCourseId() { return courseId; }
string Course::getCourseName() { return courseName; }
unsigned int Course::getCourseSemester() { return courseSemester; }

//===============================STUDENT===============================//

//These are the constructors
Student::Student(const char *r, string s)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    //studentRegistryNumber = "cs161010";
    studentName = s;
    studentSemester = 1;
    noPassedClasses = 0;
    passedClassesGrades = NULL;
}

Student::Student(char *r, string s, unsigned int no)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    studentName = s;
    studentSemester = 1;
    noPassedClasses = no;
    passedClassesGrades = NULL;
    //passedClassesGrades = (no > 0) ? new float[no] : NULL; //This is the short version of if, the Ternary Operator.
}

Student::Student(char *r, string s, unsigned int n, unsigned int no, float *g)
{
    studentRegistryNumber = new char[strlen(r) + 1];
    strcpy(studentRegistryNumber, r);
    studentName = s;
    studentSemester = n;
    noPassedClasses = no;
    passedClassesGrades = g; //This needs to be a float array
}

//Copy constructor
Student::Student(const Student &t)
{
    int srnLen = strlen(t.studentRegistryNumber) + 1;
    studentRegistryNumber = new char[srnLen];
    memcpy(studentRegistryNumber, t.studentRegistryNumber, srnLen);
    studentName = t.studentName;
    studentSemester = t.studentSemester;
    noPassedClasses = t.noPassedClasses;
    passedClassesGrades = new float[noPassedClasses];
    memcpy(passedClassesGrades, t.passedClassesGrades, noPassedClasses * sizeof(float));
}

//============================================================================
//These are the getters
char *Student::getStudentRegistryNumber() { return studentRegistryNumber; }
string Student::getstudentName() { return studentName; }
unsigned int Student::getstudentSemester() { return studentSemester; }
unsigned int Student::getNoPassedClasses() { return noPassedClasses; }
float *Student::getPassedClassesGrades() { return passedClassesGrades; }
unsigned int Student::getstudentCourses() { return studentCourses; }
Course *Student::getCourses() { return courses; }

//These are the setters
void Student::setStudentRegistryNumber(char *r)
{
    int srnLen = strlen(r) + 1;
    studentRegistryNumber = new char[srnLen];
    memcpy(studentRegistryNumber, r, srnLen);
}
void Student::setstudentName(string s) { studentName = s; }
void Student::setstudentSemester(unsigned int n) { studentSemester = n; }
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

//This is the destructor
Student::~Student()
{
    delete[] studentRegistryNumber;
    delete[] passedClassesGrades;
    // delete[] courses;
}

//============================================================================
void Student::Print()
{
    cout << "Registry Number: " << studentRegistryNumber << " "
         << "Name: " << studentName << " "
         << "Semester: " << studentSemester << endl;
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

//============================================================================
//Operators
void Student::operator+=(const Course &c)
{
    studentCourses++;
    realloc(courses, studentCourses); //Resizing Initial array
    courses[studentCourses - 1] = c;  //Appending new element
}

int Student::operator==(const Student &s) { return (s.studentSemester == studentSemester); }
int Student::operator!=(const Student &s) { return (s.studentSemester != studentSemester); }
int Student::operator<(const Student &s) { return (s.studentSemester < studentSemester); }
int Student::operator<=(const Student &s) { return (s.studentSemester <= studentSemester); }
int Student::operator>(const Student &s) { return (s.studentSemester > studentSemester); }
int Student::operator>=(const Student &s) { return (s.studentSemester >= studentSemester); }

ostream &operator<<(ostream &os, const Student &s)
{
    os << "Registry Number: " << s.studentRegistryNumber << " | Name: " << s.studentName;
    return os;
}

//----------------------------------MAIN----------------------------------//

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
    student1.setstudentName("Joe Doe");
    student2.setstudentSemester(6);
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
         << "Name: " << student1.getstudentName() << " "
         << "Semester: " << student1.getstudentSemester() << " "
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

    //Creating courses for student1
    cout << "========================= COURSES =======================\n";
    student1.setStudentCourses(4);
    Course course1 = Course("cs1", "Course 1", 1);
    Course course2 = Course("cs2", "Course 2", 1);
    Course course3 = Course("cs3", "Course 3", 2);
    Course course4 = Course("cs4", "Course 4", 3);
    Course tmp[] = {course1, course2, course3, course4};
    student1.setCourses(tmp);
    printf("Printing intitial courses(%d)\n", student1.getstudentCourses());
    student1.printCourses();
    Course course5 = Course("cs5", "Course 5", 5);
    student1 += course5;
    printf("Printing updated courses(%d)\n", student1.getstudentCourses());
    student1.printCourses();
    cout << "========================= COMPARISSONS =======================\n";
    student2.setstudentSemester(2);
    student3.setstudentSemester(3);
    cout << "student2 == student3: " << (student2 == student3) << endl;
    cout << "student2 != student3: " << (student2 != student3) << endl;
    cout << "student2 < student3: " << (student2 < student3) << endl;
    cout << "student2 <= student3: " << (student2 <= student3) << endl;
    cout << "student2 > student3: " << (student2 > student3) << endl;
    cout << "student2 >= student3: " << (student2 >= student3) << endl;
    cout << "========================= << OVERLOAD =======================\n";
    cout << "student1: " << student1 << endl
         << "student2: " << student2 << endl
         << "student3: " << student3 << endl;
    return 0;
}
