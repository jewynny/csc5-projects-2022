/**************************************************************************
* AUTHOR : Janelle Gwynn M. Hamoy                                         *
* PROJECT #4 : Parallel Arrays						  *
* CLASS : CSC5 								  *
* SECTION : MW 2:20PM - 5:30PM 						  *
* DUE DATE : 5/25/22 							  *
*************************************************************************/

#include "myheader.h"

/********************************************************************
 * Definition of PrintHeaderToFile				    *
 * This function will output the header to the output file. 	    *
 ******************************************************************/

void PrintHeaderToFile(ofstream &outFile)
{

   /***********************************************************************
   * CONSTANTS
   * ---------------------------------------------------------------------
   * PROGRAMMER : Programmer's Name
   * CLASS 	 : Student's Courses
   * SECTION 	 : Class Days and Time
   * PROJ_NUM 	 : Project Number
   * PROJ_NAME  : Title of the Project
   **********************************************************************/

	const char PROGRAMMER[30] = "Janelle Gwynn M. Hamoy";
	const char CLASS[5] = "CSC5";
	const char SECTION[25] = "MW 2:20PM-5:30PM";
	const int  PROJ_NUM = 4;
	const char PROJ_NAME[17] = "Parallel Arrays";

	outFile << left;
	outFile << "**************************************************";
	outFile << "\n* PROGRAMMED BY : " << PROGRAMMER;
	outFile << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	outFile << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	outFile << "\n* PROJECT #" << setw(5) << PROJ_NUM << ": " << PROJ_NAME;
	outFile << "\n**************************************************\n\n";
	outFile << right;


}


