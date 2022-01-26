#include <iostream>
#include "student.h"
#include "roster.h"



using namespace std;

int main()
{
		// Student Data table
		string studentData[] = {
			"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Dillon,Charles,dchar18@wgu.edu,23,30,33,40,SOFTWARE"
	} ;
		// Print to screen
		cout << "Scripting and Programming - Applications - C867" << endl;
		cout << "Written in C++." << endl;
		cout << "Student ID: 000733464" << endl;
		cout << "Dillon Charles" << endl;
		
		// Add students to classRoster
		Roster* classRoster = new Roster(5, studentData);

		// Print
		classRoster->printAll();
		classRoster->printInvalidEmails();

		//Print average days left in courses
		classRoster->printAverageDaysInCourse("A1");
		classRoster->printAverageDaysInCourse("A2");
		classRoster->printAverageDaysInCourse("A3");
		classRoster->printAverageDaysInCourse("A4");
		classRoster->printAverageDaysInCourse("A5");

		//Print by Degree program
		classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);

		//Remove student by ID
		classRoster->remove("A3");

		//Print new results
		classRoster->printAll();

		//Verify error message when attempting to remove non-existant ID
		classRoster->remove("A3");

		//Reset
		classRoster->~Roster();
	
}