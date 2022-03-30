#include <iostream>
#include <new>
#include <array>
#include <string>
#include <cstring>

#include "Student.h"

using namespace std;

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
