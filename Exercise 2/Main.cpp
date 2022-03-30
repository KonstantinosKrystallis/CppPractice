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
    Student student4 = Student("ΑΜ123456", "Μιχάλης Ιορδάνης", 2);
    Student student5;

    // Demonstrating that the copy constructor in fact create a deep copy of student 1
    cout << "Περιεχόμενα του student1: ";
    student1.Print();
    cout << "Περιεχόμενα του student2: ";
    student2.Print();
    cout << "Περιεχόμενα του student3: ";
    student3.Print();
    cout << "Περιεχόμενα του student4: ";
    student4.Print();
    cout << "Περιεχόμενα του student5: ";
    student5.Print();

    // Changing some of the values to demonstrate the use of setters
    student1.setStudentRegistryNumber("cs171010"); // The compiler throws a warning for this, but that never stopped anyone from doing anything
    student1.setFirstLastName("Joe Doe");
    student2.setCurrentSemester(6);

    // Printing the changes
    cout << "\n======================= Προσθήκη στοιχείων με την χρήση setters =========================\n\n";
    cout << "Περιεχόμενα του student1: ";
    student1.Print();
    cout << "Περιεχόμενα του student2: ";
    student2.Print();
    cout << "Περιεχόμενα του student3: ";
    student3.Print();
    cout << "Περιεχόμενα του student4: ";
    student4.Print();

    // Incresing students currentSemester
    student1.IncreasSemester();
    student2.IncreasSemester();
    student3.IncreasSemester();
    student4.IncreasSemester();
    cout << "\n======================= Αύξηση εξαμήνου όλων των φοιτητών, κατά ένα =========================\n\n";
    cout << "Περιεχόμενα του student1: ";
    student1.Print();
    cout << "Περιεχόμενα του student2: ";
    student2.Print();
    cout << "Περιεχόμενα του student3: ";
    student3.Print();
    cout << "Περιεχόμενα του student4: ";
    student4.Print();

    // Using getters to print student1
    cout << "\n========================= Εκτύπωση στοιχείων student1 με την χρήση getters =======================\n\n";
    cout << "Περιεχόμενα του student1: ";
    cout << "Αριθμός Μητρώου: " << student1.getStudentRegistryNumber() << " "
         << "Ονοματεπώνυμο: " << student1.getFirstLastName() << " "
         << "Εξάμηνο: " << student1.getCurrentSemester() << endl;

    return 0;
}
