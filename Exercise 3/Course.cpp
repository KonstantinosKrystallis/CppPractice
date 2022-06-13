#include <iostream>
#include <string>

#include "Course.h"

using namespace std;

// Constructors
Course::Course() {}
Course::Course(string id, string name, unsigned int semester)
{
    courseId = id;
    courseName = name;
    courseSemester = semester;
}
// Destructor
Course::~Course() {}

// Getters
string Course::getCourseId() { return courseId; }
string Course::getCourseName() { return courseName; }
unsigned int Course::getCourseSemester() { return courseSemester; }
