/**************************************************************************
* AUTHOR : Janelle Gwynn M. Hamoy                                         *
* PROJECT #4 : Parallel Arrays						  *
* CLASS : CSC5 								  *
* SECTION : MW 2:20PM - 5:30PM 						  *
* DUE DATE : 5/25/22 							  *
*************************************************************************/

#include "myheader.h"

/********************************************************************
 * Definition of PrintReport to File	 			    *
 * This function will output the completed report to the output     *
 * file. The completed report will include the employee number,     *
 * name, and balance. This function will only use the employees the *
 * user has searched. The employees that were not found will not be *
 * output. This function will also output the average balance due   *
 * from the employees.						    *
 ******************************************************************/

void PrintReportToFile(ofstream &outFile, int positon, string name[],
		       int idNum[], float balances[], int match[],
		       int counter, const int SIZE)
{
	float  totalBalance = 0;  //INPUT  - Total balance due from employees
	float  average;		  //INPUT  - Temporarily holds the subscript
				  //	     with found employee position
				  //	     in array
	int    tempPos;		  //OUTPUT - The average balance due from
				  //	     employees

	outFile << endl;
	outFile << left << setw(9) <<  "ID #" << setw(25) << "NAME";
	outFile << setw(11) << "BALANCE DUE" << endl;
	outFile << setw(9) << "----" << setw(25) << "--------------------";
	outFile << setw(11) << "-----------" << endl;

	//Output Employees
	for (int count = 0; count < counter; count++)
	{
		tempPos = match[count];
		outFile << left << setw(9) << idNum[tempPos];
		outFile << setw(25) << name[tempPos];
		outFile << setprecision(2) << showpoint << fixed;
		outFile << "$" << right << setw(10) << balances[tempPos] << endl;
	}

	//Compute Average
	for (int count = 0; count < counter; count++)
	{
		tempPos = match[count];
		totalBalance += balances[tempPos];
	}

	average = totalBalance / counter;

	//Output Average
	outFile << endl;
	outFile << setw(35) << "Average Balance Due: $";
	outFile << setw(10) << average << endl;
}
