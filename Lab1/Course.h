#ifndef COURSE_H
#define COURSE_H

#include <iostream>
using namespace std;

struct Course{
    string name, location, *sections;
    int numSections, numHours;
};

Course* createCourse(string, string, int, int);
void destroyCourse(Course* myCourse);
void printCourse(Course* myCourse);

#endif
