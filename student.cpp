#include "student.h"
#include <iostream>
using std::cout;
using std::endl;

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, DegreeProgram degree, int numDays[])
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->degree = degree;
    for (int index = 0; index < daysToCompleteArraySize; index++) {
        this->numDays[index] = numDays[index];
    }
}
// Access functions
string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName()  {
    return firstName;
}

string Student::getLastName()  {
    return lastName;
}

string Student::getEmail()  {
    return emailAddress;
}

int Student::getAge()  {
    return age;
}

int* Student::getNumDays() {
    return numDays;
}

DegreeProgram Student::getDegree() {
    return degree;
}

// Mutator functions
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setNumDays(int numDays[]) {
    for (int index = 0; index < daysToCompleteArraySize; index++)
    {
        this->numDays[index] = numDays[index];
    }
}

void Student::setDegree(DegreeProgram degree) {
    this->degree = degree;
}



// Method to print
void Student:: print() {
    cout << studentID << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "daysInCourse: {";
    cout <<numDays[1] << ", ";
    cout <<numDays[2] << ", ";
    cout <<numDays[1] << "}\t";
    cout << "Degree Program: ";
    switch (degree)
    {
    case DegreeProgram::SECURITY:
        cout << "Security";
        break;
    case DegreeProgram::NETWORK:
        cout << "Network";
        break;
    case DegreeProgram::SOFTWARE:
        cout << "Software";
        break;
    }
    cout << endl;
}

Student::~Student(){}