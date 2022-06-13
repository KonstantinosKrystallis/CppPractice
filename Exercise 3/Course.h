#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course
{
private:
    string courseId;
    string courseName;
    unsigned int courseSemester;

public:
    // Constructors
    Course();
    Course(string, string, unsigned int);
    ~Course();
    // Getters
    string getCourseId();
    string getCourseName();
    unsigned int getCourseSemester();
    // Setters
    void setCourseId(string);
    void setCourseName(string);
    void setCourseSemester(unsigned int);
};
#endif
