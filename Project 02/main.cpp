/**************************************************************************
* AUTHOR : Janelle Gwynn M. Hamoy                                         *
* PROJECT #2 : Repetition & Switch Statement							  *
* CLASS : CSC5 															  *
* SECTION : MW 2:20PM - 5:30PM 											  *
* DUE DATE : 4/4/22 													  *
*************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**************************************************************************
 *
 * CALCULATE GPA
 * ______________________________________________________________________
 * This program will obtain letter grades from the user and calculate
 * total grade points and grade point average. Each letter grade has a
 * numeric value. Letter input will be converted to a numeric value and
 * will be used to calculate total grade points and grade point average.
 * This program will also validate user input and ensure only valid
 * inputs are being inputed.
 *
 * Computation is based on the formula:
 * GPA = Total Grade Points / Amount of Grades Inputed
 * ______________________________________________________________________
 * CONSTANTS
 * GRADE_A			: Number value for A Grade
 * GRADE_B			: Number value for B Grade
 * GRADE_C			: Number value for C Grade
 * GRADE_D			: Number value for D Grade
 * GRADE_F			: Number value for F Grade
 *
 * INPUT
 * counterLoop	 	: Counter for loop
 * letterGrade	 	: Letter grade input by user
 * counterGrade  	: Counter for grade
 *
 * OUTPUT
 * totalGPA			: Total grade points
 * GPA				: Grade Point Average
 *
 *************************************************************************/

int main()
{
	//CONSTANTS
	const int GRADE_A = 4;
	const int GRADE_B = 3;
	const int GRADE_C = 2;
	const int GRADE_D = 1;
	const int GRADE_F = 0;

	//Variables
	int    counterLoop;		//INPUT  - Counter for Loop
	char   letterGrade;		//INPUT  - Letter grade input by user
	float  counterGrade;	//INPUT  - Counter for grade
	int    totalGPA;		//OUTPUT - Total grade points
	float  GPA;				//OUTPUT - Grade Point Average

	//Initialize Variables
	totalGPA = 0;
	counterGrade = 0;
	counterLoop = 0;

	//Header
	cout << "**************************************************";
	cout << "\n* PROGRAMMED BY : Janelle Gwynn M. Hamoy";
	cout << "\n* CLASS         : CSC5";
    cout << "\n* SECTION       : MW 2:20PM - 5:30PM";
    cout << "\n* ASSIGNMENT #2 : Repetition & Switch Statement";
	cout << "\n**************************************************";

	for (int i = 0; i < 3; i++)
	{
		++counterLoop;
		cout << endl <<"TEST #" << counterLoop << ":";
		cout << endl << endl;

		//Initialize Variables
		totalGPA = 0;
	    counterGrade = 0;

		//Get Input From User and Validate Input
	    cout << setw(48);
		cout << "Enter Letter Grade (enter 'X' to exit): ";
		cin >> letterGrade;

		while (!(letterGrade == 'x' || letterGrade == 'X'))
		{
			switch (letterGrade)
			{
				case 'a':
				case 'A':
						  ++counterGrade;
						  totalGPA += GRADE_A;;
						  break;
				case 'b':
				case 'B':
						  ++counterGrade;
						  totalGPA += GRADE_B;
						  break;
				case 'c':
				case 'C':
						  ++counterGrade;
						  totalGPA += GRADE_C;;
						  break;
				case 'd':
				case 'D':
						  ++counterGrade;
						  totalGPA += GRADE_D;
						  break;
				case 'f':
				case 'F':
						  counterGrade++;
						  totalGPA += GRADE_F;
						  break;
				default:
					      cout << setw(37);
						  cout << endl << "Invalid Letter grade, please ";
						  cout << "try again" << endl << endl;
			}
		//Reread
		cout << setw(48);
		cout << "Enter Letter Grade (enter 'X' to exit): ";
		cin >> letterGrade;

		}
		if (counterGrade > 0)
		{
			//Compute GPA
			GPA = totalGPA / counterGrade;

			//Set output
			cout << fixed << showpoint << setprecision(2);

			//Output Results
			cout << endl << "Total Grade Points: " << totalGPA << endl;
			cout << "GPA: " << GPA << endl << endl;
		}
	}
	return 0;
}
