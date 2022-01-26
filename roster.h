#pragma once
#include <string>
#include <iostream>
#include "student.h"

class Roster
{
private:
    int sizeOfArray;
    int numberOfStudents;
    Student** classRosterArray;
public:
    Roster(int sizeOfArray, string studentData[]);
    ~Roster();


    void add(string studentID, string firstName, string lastName, string email, int age, int numDays1, int numDays2, int numDays3, DegreeProgram degree);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degree);
};