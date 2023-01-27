/**************************************************************************
* AUTHOR : Janelle Gwynn M. Hamoy                                         *
* PROJECT #4 : Parallel Arrays						  *
* CLASS : CSC5 								  *
* SECTION : MW 2:20PM - 5:30PM 						  *
* DUE DATE : 5/25/22 							  *
*************************************************************************/

#include "myheader.h"

/********************************************************************
 * Definition of LoadArraysFromFile  				    *
 * This function will load the information from the input file into *
 * arrays.						 	    *
 ******************************************************************/

void LoadArraysFromFile(ifstream &inFile, string name[], int idNum[],
			float balances[], const int SIZE)
{
	for (int count = 0; count < SIZE; count++)
	{
		getline(inFile, name[count]);
		inFile >> idNum[count];
		inFile >> balances[count];
		inFile.ignore();
	}

}
