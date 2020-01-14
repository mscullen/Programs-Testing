////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FILE NAME:		lab4.cpp
// TITLE NAME:		Lab 4 structs
// SUBMITTED BY:	Matthew Cullen
// FOR COURSE:		CS 2020
// DUE DATE:		2/6/2017
//
// ALL CODE IS MINE UNLESS OTHERSWISE INDICATED.
//
// PURPOSE:		The purpose of this program is to collect user input from a 
//			user who is entering student exam grades. The program will then
//			display the input for the ten students that the user entered into 
//			the program. The user will also be able to look up a students 
//			score by entering in a Student ID code for a specific student.  
//
//
//
//
//
// OVERALL METHOD:	1. Ask the user for the studenets name, score on the exam,
//			the percentage that the student recived on the exam, and then enter 
//			if the student passed or failed the exam by entering true or false.
//			2.Program will loop for a grand total of 10 times before ending.
//			3.The program will then display all of the information that the 
//			teacher has just entered.
//			4.The user then will be asked to enter a student ID code, so that
//			he or she can look for a specific students score on the exam.
//			5.Program will end when the user is done browsing through the test scores.
//
//
//
//
//
// FUCNTIONS:		1. fillArrayfromUser - This function will gather infromation from the user 
//			regarding: name of student, score on exam, the percentage on the exam, and 
//			entering wether or not the student passed the exam.
//			-NOTE-: the score on the exam will be shown as how many points the student 
//			earned out of the total points possible. Example: Score: 15/20.
//			-Note-: The program will ask the user if the student passed the exam. This will
//			be answered using true or false. 
//			2. displayInformation- This function will display the output for the ten students 
//			that the user input into the program. This info will be displayed by telling the 
//			user the name,score,percentage,and if the student passed the exam or not. 
//			3. searchID - This will allow the user to search for various students and see
//			what scores which students revcieved on the exam. The student ID code will be 
//			a string variable, so that teachers have an easier time finding which student 
//			they want to look up.  
//
//
//
//
// INCLUDE FILES:	1.iostream
//			2.fstream
//			3.iomanip
//			4.string
//
// DATA FILES:		1.A data file will be used at a later time for this program.
//
//
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////



// Adam
// 99
// 99
// 1
// Don
// 100
// 100
// 1
// Rick
// 56
// 56
// 0
// Larry
// 78
// 78
// 1
// Marty
// 100
// 100
// 1
// Frank
// 98
// 98
// 1

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;


struct Students
{
	string name;
	int score;
	double percentage;
	bool passed;
};

void fillfromUser(Students[],int);
void fillUsingRedirection(Students[],int);
void fillUsingfstream(Students[],int);
void displayInformation(Students[],int);

const int MAX = 3;



int main ()
{
	Students myStudent[MAX];
	fillfromUser(myStudent,MAX);
	displayInformation(myStudent,MAX);	
	fillUsingRedirection(myStudent,MAX);
	displayInformation(myStudent,MAX);	
	fillUsingfstream(myStudent,MAX);
	displayInformation(myStudent,MAX);	


	return 0;
}


void fillfromUser(Students temp[],int MAX)
{
	string answer;
	string tempName;
	int tempScore;
	double tempPercentage;
	bool tempPassed;
	int i=0;

		cout << "Do you have a Student grade to enter:  y or n ";
		cin >> answer;
		while (answer == "y" && i<MAX)
		{

			cout << "Name:     ";
			cin >> tempName;;
			cout << tempName << endl;
			cout << "Score:    ";		
			cin >> tempScore;
			cout << tempScore << endl;
			cout <<"Percentage:     ";
			cin >> tempPercentage;
			cout << tempPercentage << endl;
			cout << "Passed:     ";
			cin >> tempPassed;
			cout << tempPassed << endl;
		
			temp[i].name = tempName;
			temp[i].score = tempScore;
			temp[i].percentage= tempPercentage;
			temp[i].passed = tempPassed;


			i++;
			cin.ignore();
			cout << "Do you have more grades to enter?:  y or n";
			cin >> answer;
		}



}

void fillUsingRedirection(Students temp[], int MAX)
{

	//variables
	
	string tempName;
	int tempScore;
	double tempPercentage;
	bool tempPassed;
	int i=0;

	cout << "Name:    ";
	getline(cin,tempName);
	cout << tempName << endl;

		while(!cin.eof() &&  i<MAX)
		{
			cout << "Score:   ";
			cin >> tempScore;
			cout << tempScore << endl;
			cout << "Percentage    ";
			cin >> tempPercentage;
			cout << tempPercentage << endl;
			cout << "Passed:     ";
			cin >> tempPassed;
			cout << tempPassed << endl;
		
			temp[i].name = tempName;
			temp[i].score = tempScore;
			temp[i].percentage = tempPercentage;
			temp[i].passed = tempPassed;

			i++;
			cin.ignore();
			getline(cin, tempName);
			cout << tempName << endl;

		}

	

}

void fillUsingfstream(Students temp[], int MAX)
{
	//variables

	string tempName;
	int tempScore;
	double tempPercentage;
	bool tempPassed;
	int i=0;

	ifstream indata;
	indata.open("student.txt");
	if (!indata)
	{
		cout << "File not found." << endl;
		return;
	}
	
	getline (indata, tempName);	
	

		while (!indata.eof () && i<MAX )
		{
			cout << tempName << endl;
			indata >> tempScore;
			cout << tempScore << endl;
			indata >> tempPercentage;
			cout << tempPercentage << endl;
			indata >> tempPassed;
			cout << tempPassed << endl;

			temp[i].name = tempName;
			temp[i].score = tempScore;
			temp[i].percentage = tempPercentage;
			temp[i].passed = tempPassed;

			i++;
			indata.ignore();
			getline(indata, tempName);
	
		}
		indata.close();

	
}

void displayInformation(Students temp[], int MAX)

{
	cout << endl;
	cout << endl;
	cout << "Display Information" << endl;
	
	for (int i=0; i<MAX; i++)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << temp[i].name << endl;
		cout << temp[i].score << endl;
		cout << temp[i].percentage << endl;
		if (temp[i].passed == 1)
		
			cout << "This student passed the exam "<< endl;
	
			else

			cout << "This student failed the exam" << endl;
		
	}
	
}









