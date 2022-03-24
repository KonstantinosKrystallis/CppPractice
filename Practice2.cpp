#include <iostream>
#include <cstring>
#include <string>
#include <new>
#include <array>

using namespace std;

#pragma region Student(+)
class Student
{
    // The default access identifier is private and there is no real reason to include it,
    // but it is considered good practice to do so. Also I personally like to see it.
    // It makes the code easier to read.
private:
    char *studentRegistryNumber;  // Student's registry number
    string firstLastName;         // Student's name
    unsigned int currentSemester; // Student's current semester
    unsigned int noPassedClasses; // Number of passed classes
    float *passedClassesGrades;   // The grades for each passed class

public:
    // These are the constructors
    Student(const char *, string);
    Student(char *, string, unsigned int);
    Student(char *, string, unsigned int, unsigned int, float *);
    Student(const Student &);

    // These are the getters
    char *getStudentRegistryNumber();
    string getFirstLastName();
    unsigned int getCurrentSemester();
    unsigned int getNoPassedClasses();
    float *getPassedClassesGrades();

    // These are the setters
    void setStudentRegistryNumber(char *);
    void setFirstLastName(string);
    void setCurrentSemester(unsigned int);
    void setNoPassedClasses(unsigned int);
    void setPassedClassesGrades(float *);

    ~Student(); // This is the destructor

    void Print(); // This prints the first three atributes of the student
    void printGrades();
    void addGrade(float);
};

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

#pragma endregion

//----------------------------------MAIN----------------------------------------------//

int main(int argc, char *argv[])
{
    Student student1 = Student("cs161010", "Konstantinos Krystallis");
    Student student2 = Student(student1);
    Student student3 = student1;
    Student student4 = Student("ΑΜ123456", "Μιχάλης Ιορδάνης", 2, 3, new float[3]{5.4, 7, 6.2});

    // Demonstrating that the copy constructor in fact create a deep copy of student 1
    cout << "Περιεχόμενα του student1: ";
    student1.Print();
    cout << "Περιεχόμενα του student2: ";
    student2.Print();
    cout << "Περιεχόμενα του student3: ";
    student3.Print();
    cout << "Περιεχόμενα του student4: ";
    student4.Print();

    // Changing some of the values to demonstrate the use of setters
    student1.setStudentRegistryNumber("cs171010"); // The compiler throws a warning for this, but that never stopped anyone from doing anything
    student1.setFirstLastName("Joe Doe");
    student2.setCurrentSemester(6);
    // student3.setNoPassedClasses(4);
    student3.setPassedClassesGrades(new float[4]{5, 8.5, 7, 5.95});

    // Printing the changes
    cout << "\n======================= Προσθήκη στοιχείων με την χρήση setters =========================\n\n";
    cout << "Περιεχόμενα του student1: ";
    student1.Print();
    cout << "Περιεχόμενα του student2: ";
    student2.Print();
    cout << "Περιεχόμενα του student3: ";
    student3.Print();

    // Adding grades to student 1
    student1.addGrade(7.2);
    student1.addGrade(5);
    student1.addGrade(9.5);
    cout << "\n======================== Προσθήκη βαθμών στον student1 ========================\n\n";
    cout << "Περιεχόμενα του student1: ";
    student1.Print();

    // Using getters to print student1
    cout << "\n========================= Εκτύπωση στοιχείων student1 με την χρήση getters =======================\n\n";
    cout << "Περιεχόμενα του student1: ";
    cout << "Αριθμός Μητρώου: " << student1.getStudentRegistryNumber() << " "
         << "Ονοματεπώνυμο: " << student1.getFirstLastName() << " "
         << "Εξάμηνο: " << student1.getCurrentSemester() << " "
         << "Αριθμός Περασμένων Μαθημάτων: " << student1.getNoPassedClasses() << " || ";
    if (student1.getPassedClassesGrades() != NULL)
    {
        cout << "Βαθμοί: ";
        int t = student1.getNoPassedClasses();
        float *temp = new float[student1.getNoPassedClasses()];
        memcpy(temp, student1.getPassedClassesGrades(), t * sizeof(float));
        float sum = 0;
        for (int i = 0; i < t; i++)
        {
            sum += temp[i];
            cout << "Μάθημα " << i + 1 << ": " << temp[i] << " ";
        }
        cout << "Μέσος όρος: " << sum / student1.getNoPassedClasses() << endl;
    }

    return 0;
}
