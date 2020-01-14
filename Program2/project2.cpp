/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//File Name: 		final.cpp
//Programmer: 		NBA Statistics Program
//Submitted by:		Matthew Cullen
//For Course: 		CS 2010 
//Due:			12/14/2016
//
//All code is mine unless otherwise indicated
//
// Purpose:		This program is designed to store NBA player stats into 7 arrays and calcuate a total score.
//
// Overall Method:	1.User enters data into six arrays
//			2.Program then adds points,rebounds,assists together, then divides by number of turnovers the player had.
//			3.Program then displays the player,position,points,rebounds,assists,turnovers,and total.
//
// Functions:		displayWelcome- Shows a welcome message to the user.
//			getData- gets the input from the user (player,position,points,rebounds,assists,turnovers.
//			calcTotal- adds points,rebounds,assists and divdes the sume by the number of turnovers.
//			displayResults- displays the player,position,points,rebounds,assists,turnovers in seven arrays for 12 players.
//
// Include Files:	1.iostream
//			2.iomanip
//			3.string
//
// Data Files: 		No data files were used to make this program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

///////////////////////////////////////////
//Function Prototypes
///////////////////////////////////////////

void displayWelcome();
void getData(string[],string[],int[],int[],int[],int[]); 
void calcTotal(int[],int[],int[],int[],double[]);
void displayResults(string[],string[],int[],int[],int[],int[],double[]);


// Constants
const int MAX =15;	



int main()
{
	

	//Variables
	
	string player[MAX];
	string position[MAX];
	int points[MAX] ;
	int assists[MAX] ;
	int rebounds[MAX] ;
	int turnovers[MAX] ;
	double total[MAX];

	
	displayWelcome();
	getData(player,position,points,rebounds,assists,turnovers);
	calcTotal(points,rebounds,assists,turnovers,total);
	displayResults(player,position,points,rebounds,assists,turnovers,total);	

	return 0;
}

////////////////////////////
//Function Definitions
///////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	getData - 	this function is the input section of the program, asking the user for the player,position,points,rebounds,assists,and turnovers
//	
//	Prototype- 	void getData(string,string,int,int,int,int)
//	Call- 		getData(player,position,points,reobunds,assists,turnovers)
//	Header- 	void getData(string tempPlayer[], string tempPosition[], int tempPoints[],int tempRebounds[], int tempAssists[], int tempTurnovers[]
//	
//	Notes: 		Once the user has entered all of the data, the program will then move onto the calcTotal function.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void getData (string tempPlayer[], string tempPosition[] , int tempPoints[], int tempRebounds[], int tempAssists[], int tempTurnovers[])
{
	for (int i=0 ;i<MAX; i++)
	{
		cout << "Enter Player:  ";
		cin >> tempPlayer[i];
		cout << "Enter Position:  ";
		cin >> tempPosition[i];
		cout << "Enter Points:  ";
		cin >> tempPoints[i];
		if (tempPoints < 0)
		{
			cout << "Error: Points must be at least zero or greater";
			cin >> tempPoints[i];
		}
		cout << "Enter Rebounds:  ";
		cin >> tempRebounds[i];
		if (tempRebounds < 0)
		{
			cout << "Error: Rebounds must be at least zero or greater";
			cin >> tempRebounds[i];
		}
		cout << "Enter Assists:  ";
		cin >> tempAssists[i];
		if (tempAssists < 0)
		{
			cout << "Error: Assists must be at least zero or greater";
			cin >> tempAssists[i];
		}
		cout << "Enter Turnovers:  ";
		cin >> tempTurnovers[i];
		if (tempTurnovers < 0)
		{
			cout << "Error: Turnovers must be at least zero or greater";
			cin >> tempTurnovers[i];
		}
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	
//		calcTotal -	this part of the function adds the points,rebounds, and assists together. Then the program divdies the sum by number of turnovers.
//
//		prototype-  	void calcTotal(int,int,int,int,double)
//		call-		calcTotal(points,rebounds,assists,turnovers,total)
//		header-		void calcTotal(int tempPoints[],int tempRebounds[],int tempAssists[], int tempTurnovers[], double tempTotal[])
//
//		Notes- The "Total" in this program is an efficiency rating, the higher your total, the more you helped the team.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  calcTotal (int tempPoints[], int tempRebounds[], int tempAssists[], int tempTurnovers[], double tempTotal[])
{
	for (int i=0 ;i<MAX; i++)
	{
		tempTotal[i]= (tempPoints[i]+tempRebounds[i]+tempAssists[i])/tempTurnovers[i];
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		
//		diplayResults -	this part of the program displays the input the user submitted, along with the calculated total of each player.
//
//		prototpye-	void displayResults(string,string,int,int,int,int,double)
//		call-		displayResults(player,position,points,rebounds,assits,turnovers,total)
//		header-		void displayerResults(string tempPlayer[],string tempPosition[],int tempPoints[],int tempRebounds,int tempAssists[],int tempTurnovers[],double tempTotal[])
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void displayResults (string tempPlayer[], string tempPosition[], int tempPoints[], int tempRebounds[], int tempAssists[], int tempTurnovers[], double tempTotal[])
{
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(5) << "PLAYER" << setw(10) << "POSITION" << setw(15) << "POINTS" << setw(20) << "REBOUNDS" << setw(25) << "ASSISTS" << setw(30) << "TURNOVERS" << setw(35) << "TOTAL" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i=0;i<MAX; i++)
	{
		cout << fixed << showpoint << setprecision(2) << endl;
		cout << setw(5) << tempPlayer[i] << setw(10) << tempPosition[i] << setw(15) << tempPoints[i] << setw(20) << tempRebounds[i] << setw(25) << tempAssists[i] << setw(30) << tempTurnovers[i] << setw(35) << tempTotal[i] <<  endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		dipslayWelcome- this is the first function of the program, displaying a welcome message to the user.
//
//		prototpye- 	void displayerWelcome()
//		call-	 	displayWelcome()
//		header-		void displayWelcome()
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void displayWelcome()
{
	cout << "****************************************************" << endl;
	cout << "Welcome to the San Antonio Spurs Statistics Program" << endl;
	cout << "****************************************************" << endl;
}
