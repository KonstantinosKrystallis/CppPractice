#include <iostream>
#include <array>
#include <cstring>
#include <fstream>
#include <new>
#include <string>

#include "Student.h"
#include "Course.h"

using namespace std;

//----------------------------------MAIN----------------------------------------------//

int main(int argc, char *argv[])
{
    try
    {
        ofstream out("out.txt");

        if (!out.is_open())
            throw "out was not opened.";

        Student student1 = Student("cs161010", "Konstantinos Krystallis");
        Student student2 = Student(student1);
        Student student3 = student1;
        Student student4 = Student("ΑΜ123456", "Μιχάλης Ιορδάνης", 2, 4, new float[4]{5, 8.5, 6.65, 5.95});
        Student student5;

        // Demonstrating that the copy constructor in fact create a deep copy of student 1
        out << "Περιεχόμενα του student1: ";
        student1.Print(out);
        out << "Περιεχόμενα του student2: ";
        student2.Print(out);
        out << "Περιεχόμενα του student3: ";
        student3.Print(out);
        out << "Περιεχόμενα του student4: ";
        student4.Print(out);
        out << "Περιεχόμενα του student5: ";
        student5.Print(out);

        // Changing some of the values to demonstrate the use of setters
        student1.setStudentRegistryNumber("cs171010"); // The compiler throws a warning for this, but that never stopped anyone from doing anything
        student1.setFirstLastName("Joe Doe");
        student2.setCurrentSemester(6);
        student1.setStudentCoursesCount(4);
        Course course1 = Course("cs1", "Course 1", 1);
        Course course2 = Course("cs2", "Course 2", 1);
        Course course3 = Course("cs3", "Course 3", 2);
        Course course4 = Course("cs4", "Course 4", 3);
        student1.setCourses(new Course[4]{course1, course2, course3, course4});

        // Printing the changes
        out << "\n======================= Προσθήκη στοιχείων με την χρήση setters =========================\n\n";
        out << "Περιεχόμενα του student1: ";
        student1.Print(out);
        out << "Περιεχόμενα του student2: ";
        student2.Print(out);
        out << "Περιεχόμενα του student3: ";
        student3.Print(out);
        out << "Περιεχόμενα του student4: ";
        student4.Print(out);

        // Increasing students currentSemester
        student1.IncreaseSemester();
        student2.IncreaseSemester();
        student3.IncreaseSemester();
        student4.IncreaseSemester();
        out << "\n======================= Αύξηση εξαμήνου όλων των φοιτητών, κατά ένα =========================\n\n";
        out << "Περιεχόμενα του student1: ";
        student1.Print(out);
        out << "Περιεχόμενα του student2: ";
        student2.Print(out);
        out << "Περιεχόμενα του student3: ";
        student3.Print(out);
        out << "Περιεχόμενα του student4: ";
        student4.Print(out);

        // Using getters to print student1
        out << "\n========================= Εκτύπωση στοιχείων student1 με την χρήση getters =======================\n\n";
        out << "Περιεχόμενα του student1: ";
        out << "Αριθμός Μητρώου: " << student1.getStudentRegistryNumber() << " "
            << "Ονοματεπώνυμο: " << student1.getFirstLastName() << " "
            << "Εξάμηνο: " << student1.getCurrentSemester() << endl;

        out << "\n======================= Επίδειξη υπερφόρτωσης τελεστή += =========================\n\n";
        Course course5 = Course("cs5", "Course 5", 5);
        Course course6 = Course("cs6", "Course 6", 6);
        student4 += course5;
        student4 += course6;
        student4.Print(out);

        out << "\n========================= Επίδειξη υπερφόρτωσης τελεστών σύγκρισης =======================\n\n";
        student2.setCurrentSemester(2);
        student3.setCurrentSemester(3);
        out << "student2.currentSemester: " << student2.getCurrentSemester() << "\tstudent3.currentSemester: " << student3.getCurrentSemester() << endl;
        out << "student2 == student3: " << (student2 == student3) << endl;
        out << "student2 != student3: " << (student2 != student3) << endl;
        out << "student2 < student3: " << (student2 < student3) << endl;
        out << "student2 <= student3: " << (student2 <= student3) << endl;
        out << "student2 > student3: " << (student2 > student3) << endl;
        out << "student2 >= student3: " << (student2 >= student3) << endl;

        out << "\n======================= Επίδειξη υπερφόρτωσης τελεστή << =========================\n\n";
        out << student4 << endl;

        out.close();
        cout << "======================= Αποθήκευση εξόδου στο αρχείο \"out.txt\" =======================\"\n\n";

        cout << "======================= Εκτύπωση περιεχομένων του αρχείου \"out.txt\" =======================\"\n\n";
        ifstream in("out.txt");
        cout << in.rdbuf();
        in.close();

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
}
