/**************************************************************************
* AUTHOR : Janelle Gwynn M. Hamoy                                         *
* PROJECT #4 : Parallel Arrays					          *
* CLASS : CSC5 								  *
* SECTION : MW 2:20PM - 5:30PM 					 	  *
* DUE DATE : 5/25/22 							  *
*************************************************************************/

#include "myheader.h"

int main()

{
   /**********************************************************************
	* CONSTANTS
	* --------------------------------------------------------------------
	* SIZE   	: Array size
	*
	*********************************************************************/

	//Constants
	const int SIZE = 1000;

	//Variables
	string inFileName;	   //INPUT  - Name of input file user wants to use
	string outFileName;	   //INPUT  - Name of output file user wants to use
	ofstream outFile;	   //INPUT  - Variable used to open output file
	ifstream inFile;	   //INPUT  - Variable used to open input file
	string searchName;	   //INPUT  - Name of employee user wants to search
	int    position;	   //INPUT  - Receives the position of employee
				   //         searched
	int    match[SIZE];	   //INPUT  - Holds the subscript of employee
	int    counter = 0;	   //INPUT  - Counter
	string name[SIZE];	   //OUTPUT - Holds the names of employees from
				   //         input file
	int    idNum[SIZE];	   //OUTPUT - Holds the id numbers of employees
				   //         from input file
	float  balances[SIZE]; //OUTPUT - Holds the balances of the employees
			       //         from input file

	//Get file names from user.
	cout << "What input file would you like to use? ";
	cin >> inFileName;
	cout << "What output file would you like to use? ";
	cin >> outFileName;
	cout << endl;
	//Open InputFile

	inFile.open(inFileName.c_str());

	//Open Output File
	outFile.open(outFileName.c_str());

	//Load Arrays from File
	LoadArraysFromFile(inFile, name, idNum, balances, SIZE);

	//Ask User What to Search For
	cout << "Who do you want to search for (enter done to exit): ";
	cin.ignore();
	getline(cin, searchName);
	while (searchName != "done" && searchName != "Done")
	{
		position = SearchForMatch(searchName, name, SIZE);
		if (position != -1)
		{
			match[counter] = position;
			counter++;
		}

		//Reread
		cout << "Who do you want to search for (enter done to exit): ";
		getline(cin, searchName);
	}

	cout << endl;
	cout << "Thank you for using my program." << endl;

	//Print Header to File
	PrintHeaderToFile(outFile);

	//Print to File
	PrintReportToFile(outFile, position, name, idNum, balances, match,
					 counter, SIZE);

	//Close Input File
	inFile.close();

	//Close Output File
	outFile.close();

	return 0;
}
