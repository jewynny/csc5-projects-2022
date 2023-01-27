/**************************************************************************
* AUTHOR : Janelle Gwynn M. Hamoy                                         *
* PROJECT #4 : Parallel Arrays						  *
* CLASS : CSC5 								  *
* SECTION : MW 2:20PM - 5:30PM 						  *
* DUE DATE : 5/25/22 							  *
*************************************************************************/

#include "myheader.h"

/********************************************************************
 * Definition of Search  					    *
 * This function will receive employee name input by the user as an *
 * argument. This function will then search for the employee name   *
 * user wants to search for. If found, position of the employee     *
 * name in array will be returned. If not found, -1 is returned.    *
 ******************************************************************/

int SearchForMatch(string searchName, string name[], const int SIZE)
{
	int index = 0;		//INPUT  - Counter to step through array
	int position = -1;	//INPUT  - To flag if value is found
	bool found = false;     //OUTPUT - Position in array

	//Linear Search
	while (index < SIZE && !found)
	{
		if (name[index] == searchName)
		{
			found = true;
			position = index;
		}
		index++;
	}


	if (position != -1)
		cout << "Found." << endl << endl;
	else
		cout << searchName << " was not found." << endl << endl;

	return position;
}


