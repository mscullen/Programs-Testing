///////////////////////////////////////////////////////////
//Project: Lab5 Rent Program 
//Programmer: Matthew Cullen
//Date: November 5,2016
//Class: CS 2010 2:30pm-4:00pm
//Despcription: This program will calcualte a users monthly rent with an additional late fee.
//
//All code is mine unless otherwise indicated.
/////////////////////////////////////////////////////////////


#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

///////////////////////////////////////////////
//function prototypes
///////////////////////////////////////////////

void displayWelcome();
void getData(double&,int&);
double calcTotal(double,int);
void displayResults(double,double,double);
	
int main()
{
	//variables;
	double rent =0.0;
	int late =0;
	double total =0.0;

	displayWelcome();
	getData(rent,late);
	total= calcTotal(rent,late);
	displayResults(total,rent,late);

		

	return 0;
}

///////////////////////////////
// function defintions
//////////////////////////////


void getData (double& tempRent, int& tempLate)
{
	cout << "Enter your Rent per Month: ";
	cin >> tempRent;

	while (tempRent < 1)
	{
		cout << "Error, Rent is Invalid: ";
		cin >> tempRent;
	}

	cout << "Enter the number of days late: ";
	cin >> tempLate;

	while (tempLate < 0)
	{
		cout << "Error, Number of Days is Invalid:  ";
		cin >> tempLate;
	}
	
}	

double calcTotal(double tempRent, int tempLate)
{
	double answer;
	if (tempLate >= 10)
	{
		answer = (tempRent * .10) + tempRent;
	}
	else
	{
		answer = tempRent;
	}
	return answer;
}


void displayResults(double tempTotal, double tempRent, double tempLate)
{
	cout <<"-----------------------------------" << endl;
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Monthy Rent:  $" << tempRent << endl;
	cout <<   "Late Fee  :  $"   << tempRent *.10 << endl;
	cout << "Total Due  :  $"   << tempTotal << endl;
	cout <<"-----------------------------------" << endl;
}


void displayWelcome()
{
	cout << "*************************************" << endl;
	cout << "Welcome To Eagles Landing Apartments " << endl;
	cout << "*************************************" << endl;
}

