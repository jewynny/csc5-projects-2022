/**************************************************************************
* AUTHOR : Janelle Gwynn M. Hamoy                                         *
* PROJECT #1 : Basic Input / Output					  *
* CLASS : CSC5 							          *
* SECTION : MW 2:20PM - 5:30PM 						  *
* DUE DATE : 3/14/22 							  *
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


/**************************************************************************
 *
 * COMPUTE SALARY INFORMATION
 * ______________________________________________________________________
 * This program will obtain from the user the user's full name, current
 * annual salary and a percent increase due on that salary. It will
 * compute the new salary, new monthly salary, and retroactive pay. The
 * program will run 3 times and will ask user for the appropriate input.
 * It will then display the computed values from the given input.
 *
 * Computation are based on the assumption that input values are
 * effective on January 1 and calculations are effective for July 1.
 * ______________________________________________________________________
 *
 * INPUT
 *	 user_name : User's full name
 *	 salary    : Current Annual Salary
 *	 salInc    : Percent Increase due
 *
 * OUTPUT
 * 	 salNew    : New salary after percent increase
 * 	 salMon    : New monthly salary
 * 	 retPay    : Retroactive pay due
 *
 *************************************************************************/


int main ()
{
	/**********************************************************************
	* CONSTANTS
	* --------------------------------------------------------------------
	* PROGRAMMER  : Programmer's Name
	* CLASS       : Student's Course
	* SECTION     : Class Days and Time
	* LAB_NUM     : Lab Number
	* PROJ_NAME   : Title of the Project
	*********************************************************************/
	const char PROGRAMMER[30] = "Janelle Gwynn M. Hamoy";
	const char CLASS[5] = "CSC5";
	const char SECTION[25] = "MW 2:20PM - 5:30PM";
	const int  LAB_NUM = 1;
	const char PROJ_NAME[22] = "Basic Input / Output";

	cout << left;
	cout << "**************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* ASSIGNMENT #" << setw(2) << LAB_NUM << ": " << PROJ_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;

	/**********************************************************************
	* CONSTANTS
	* --------------------------------------------------------------------
	* MONTHS       : Total number of months
	* RETRO_MONTHS : Number of months retroactive
	*********************************************************************/

	for (int i = 0; i < 3; i++)
	{
	//Constants
	const int MONTHS = 12;
	const int RETRO_MONTHS = 6;

	//Variables
	string user_name;      // INPUT - User's full name
	float salary;		   // INPUT - Current annual salary
	float payInc;		   // INPUT - Percent increase
	float salNew;		   // OUTPUT - New salary after increase
	float salMon;		   // OUTPUT - New monthly salary
	float retPay;		   // OUTPUT - Retroactive pay

	//Retrieving Information From the User
	cout << left << setw(30) << "What is your name? ";
	getline(cin, user_name);
	cout << setw(30) << "What is your current salary? ";
	cin >> salary;
	cout << setw (30) << "What is your pay increase? ";
	cin >> payInc;
	cin.get( );

	//Compute the New Salary
	salNew = (salary * payInc) + salary;

	//Compute the New Monthly Salary
	salMon = salNew / MONTHS;

	//Compute Retroactive Pay
	retPay = (salNew / MONTHS) * RETRO_MONTHS;
	retPay -= (salary / MONTHS) * RETRO_MONTHS;

	//Display Output
	cout << endl << user_name << "'s SALARY INFORMATION\n";
	cout << left << setw(15) << "New Salary" << setw(19);
	cout << "Monthly Salary" << setw(15) << "Retroactive Pay\n";
	cout << right << setw(10) << setprecision(2) << fixed << salNew;
	cout << setw(19) << setprecision(2) << fixed <<salMon;
	cout << setw(20) << setprecision(2) << fixed << retPay << endl;
	cout << "\n<Press Enter to Continue>\n\n";
	cin.get( );
	}
	return 0;
}
