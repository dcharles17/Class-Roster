//
//
#include "roster.h"
#include "student.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

Roster::Roster(int sizeOfArray, string studentData[])
{
    this->sizeOfArray = sizeOfArray;
    this->numberOfStudents = sizeOfArray;
    this->classRosterArray = new Student * [sizeOfArray];

    int index = 0;
    while (index < sizeOfArray)
    {
        vector<string> fields;
        stringstream streamInput(studentData[index]);
        string field;
        while (getline(streamInput, field, ','))
        {
            fields.push_back(field);
        }
        DegreeProgram program = DegreeProgram::SECURITY;
        if (fields[8] == "SECURITY")
            program = DegreeProgram::SECURITY;
        else if (fields[8] == "NETWORK")
            program = DegreeProgram::NETWORK;
        else if (fields[8] == "SOFTWARE")
            program = DegreeProgram::SOFTWARE;

        int days[3] = { stoi(fields[5]), stoi(fields[6]), stoi(fields[7]) };
        classRosterArray[index] = new Student(
            fields[0],
            fields[1],
            fields[2],
            fields[3],
            stoi(fields[4]),
            DegreeProgram::SECURITY,
            days
        );
    }
}


void Roster::add(string studentID, string firstName, string lastName, string email, int age, int numDays1,
    int numDays2, int numDays3, DegreeProgram degree)
{
    int days[3] = { numDays1, numDays2, numDays3 };
    classRosterArray[sizeOfArray] = new Student(studentID, firstName, lastName, email, age, degree, days);
    numberOfStudents++;
}

void Roster::remove(string studentID)
{
    bool IDexists = false;
    for (int index = 0; index < numberOfStudents; index++) {
        if (this->classRosterArray[index]->getStudentID() == studentID) {
            IDexists = true;
            classRosterArray[index] = classRosterArray[numberOfStudents - 1];
            numberOfStudents--;
            cout << "Student ID " << studentID << " has been removed." << endl;
        }
    }
    if (!IDexists)
    {
        cout << "Student not found." << endl;
    }

}

void Roster::printAverageDaysInCourse(string studentID)
{
    bool IDexists = false;
    for (int index = 0; index < numberOfStudents; index++) {
        if (this->classRosterArray[index]->getStudentID() == studentID) {
            IDexists = true;
            int* days = classRosterArray[index]->getNumDays();
            int average = (days[0] + days[1] + days[2]) / 3;
            cout << "Student ID " << studentID << " spent an average of" << average << " days in each course." << endl;
        }
    }
    if (!IDexists)
    {
        cout << "Student not found." << endl;
    }

}

void Roster::printAll()
{
    cout << "Printing";
    for (int index = 0; index < numberOfStudents; index++)
    {
        classRosterArray[index]->print();
    }
}

void Roster::printInvalidEmails()
{
    bool invalidFound = false;
    for (int index = 0; index < numberOfStudents; index++)
    {
        string email = this->classRosterArray[index]->getEmail();
        if (email.find('@') == string::npos)
        {
            cout << "The email: " << email << " is invalid" << endl;
            cout << "It is missing an '@' character." << endl;
            invalidFound = true;
        }
        else if (email.find('.') == string::npos)
        {
            cout << "The email: " << email << " is invalid" << endl;
            cout << "It is missing a '.' character." << endl;
            invalidFound = true;
        }
        else if (email.find(' ') != string::npos)
        {
            cout << "The email: " << email << " is invalid" << endl;
            cout << "Emails cannot have ' ' characters." << endl;
            invalidFound = true;
        }
    }
    if (!invalidFound)
    {
        cout << "No invalid emails found.";
    }

}

void Roster::printByDegreeProgram(DegreeProgram degree)
{
    bool degreeFound = false;
    for (int index = 0; index < numberOfStudents; index++)
    {
        if (classRosterArray[index]->getDegree() == degree)
        {
            classRosterArray[index]->print();
            degreeFound = true;
        }
    }


}

Roster::~Roster()
{
    delete[] classRosterArray;
}