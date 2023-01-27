/**************************************************************************
* AUTHOR : Janelle Gwynn M. Hamoy                                         *
* PROJECT #4 : Parallel Arrays							  				  *
* CLASS : CSC5 															  *
* SECTION : MW 2:20PM - 5:30PM 											  *
* DUE DATE : 5/25/22 													  *
*************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

/**************************************************************************
 *
 * PROCESSING EMPLOYEE FILES
 * ______________________________________________________________________
 * This program will ask the user which input and output file they would
 * like to use. This function will then read information from an input
 * file and process it into arrays. This program will then ask the user
 * which employee they would like to search from. A linear search is then
 * performed on the array to find the employee. If the employee is found
 * the position is saved into an array. Once the user is finished
 * searching for employee names, the employee name, id number, and
 * balance of found employees is printed onto the output file.
 *
 * Computation is based on the formula:
 *	Average = Total Balance / Amount of Employees
 * ______________________________________________________________________
 * INPUT
 *	inFileName	: Name of input file user wants to use
 *	outFileName	: Name of output file user wants to use
 *	outFile		: Variable used to open output file
 *	inFile		: Variable used to open input file
 *	searchName	: Name of employee user wants to search
 *	position	: Receives the position of employee searched
 *	match[]		: Holds the subscript of employee
 *	counter		: Counter
 *
 * OUTPUT
 *	name[]		: Holds the names of employees from input file
 *	idNum[]		: Holds the id numbers of employees from input file
 *	balances[]	: Holds the balances of the employees from input file
 *
 *************************************************************************/

/**************************************************************************
 * Definition of LoadArraysFromFile
 * This function will load the information from the input file into arrays.
 *
 ************************************************************************/

void LoadArraysFromFile(ifstream &inFile, string name[], int idNum[],
						float balances[], const int SIZE);

/**************************************************************************
 * Definition of SearchForMatch
 * This function will receive employee name input by the user as an
 * argument. This function will then search for the employee name user
 * wants to search for. If found, position of the employee name in array
 * will be returned. If not found, -1 is returned.
 * ______________________________________________________________________
 * INPUT
 * 	index		: Counter to step through array
 * 	found		: To flag if value is found
 *
 * OUTPUT
 *	position	: Position in array
 *
 ************************************************************************/


int SearchForMatch(string searchName, string name[], const int SIZE);

/**************************************************************************
 * Definition of PrintHeaderToFile
 * This function will output the header to the output file.
 *
 ************************************************************************/

void PrintHeaderToFile(ofstream &outFile);

/**************************************************************************
 * Definition of PrintReportToFile
 * This function will output the completed report to OFile.txt. The
 * completed report will include the employee number, name, and balance.
 * This function will only use the employees the user has searched. The
 * employees that were not found will not be output. This function
 * will also output the average balance due from the employees.
 *
 * ______________________________________________________________________
 * INPUT
 * 	totalBalance	: Total balance due from employees
 *	tempPos			: Temporarily holds the subscript with found
 *					  employee position in array
 *
 * OUTPUT
 *	average			: The average balance due from employees
 *
 ************************************************************************/

void PrintReportToFile(ofstream &outFile, int position, string name[],
				 	   int idNum[], float balances[], int match[],
					   int counter, const int SIZE);

#endif /* MYHEADERH */
