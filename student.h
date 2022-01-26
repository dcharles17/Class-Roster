#pragma once

#include "degree.h"
#include <string>
using std::string;

class Student
{
public:
    const static int daysToCompleteArraySize = 3;

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    DegreeProgram degree;
    int numDays[daysToCompleteArraySize];

public:
    // Constructor
    Student(string studentID, string firstName, string lastName, string email, int age, DegreeProgram degree, int numDays[]);

    //Accessors (Getters)
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    DegreeProgram getDegree();
    int* getNumDays();

    //Mutators (Setters)
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDegree(DegreeProgram degree);
    void setNumDays(int numDays[]);

    //Method to print
    void print();

    //Destructor
    ~Student();
};