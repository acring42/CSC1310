#include "course.h"

Course* createCourse(string a, string b, int c, int d){
    Course* course = new Course;
    course->name = a;
    course->location = b;
    course->numHours = c;
    course->numSections = d;
    course->sections = new string[course->numSections];

    return course;
}

void destroyCourse(Course* myCourse){
    delete [] myCourse->sections;
}

void printCourse(Course* myCourse){
    cout << "COURSE NAME:\t\t" << myCourse->name << endl;
    cout << "COURSE LOCATION:\t" << myCourse->location << endl;
    cout << "COURSE HOURS:\t\t" << myCourse->numHours << endl;
    cout << "SECTIONS:" << endl;

    for(int i=0; i<myCourse->numSections; i++)
        cout << "\t\t\t" << myCourse->sections[i] << endl;

}