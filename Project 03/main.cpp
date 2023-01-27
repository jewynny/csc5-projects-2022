/**************************************************************************
* AUTHOR : Janelle Gwynn M. Hamoy                                         *
* PROJECT #3 : Functions						  *
* CLASS : CSC5 								  *
* SECTION : MW 2:20PM - 5:30PM 						  *
* DUE DATE : 5/9/22 							  *
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**************************************************************************
 *
 * COMPUTING SALES DEPARTMENT ORDERS
 * ______________________________________________________________________
 * This program will compute a customer's charges from an outfitter's
 * catalog. This program will first ask the user for their account
 * number, the date of sale, the county code, the total sale amount
 * (before tax), and the shipping weight. After the user has completed
 * all their input, this program will then compute the proper discount,
 * proper sales tax, and proper shipping. The proper discount will be
 * applied based on the month ordered. The proper sales tax will be based
 * on the the county inputed by the user. The proper shipping will be
 * calculated based on its given weight. Once the discount, sales tax,
 * and shipping costs have been computed, this program will then output
 * an invoice to the user with all the appropriate costs.
 *
 * Computation for discount is based on the formula:
 * Discount = Sales Amount (Before Tax) * Discount Percentage
 *
 * Computation for the sales tax is based on the formula:
 * Sales Tax = (Sales Amount - Discount) * Tax Percentage
 *
 * Computation for the shipping is based on the formula:
 * Shipping = Flat Rate + ((Each Pound Above 25) * Rate) + ((Each Pound
 * 	          Above 50) * Rate)
 *
 * ______________________________________________________________________
 * INPUT
 * 	accountNum		: User's Account Number
 * 	month			: Numerical Value of Month
 * 	day				: Numerical Value of Day
 * 	year			: Numerical Value for Year
 * 	countyCode		: County Code
 * 	salesAmount		: Sales Amount Before Tax
 * 	shippingWeight	: Shipping Weight
 *
 * OUTPUT
 *	countyName		: String for County Name
 *	discount		: Total Discount
 *	countyTax		: Total County Tax
 *	shippingCost	: Total Shipping Cost
 *
 **************************************************************************
 *
 * GetSalesInfo
 * ______________________________________________________________________
 * This function will accept variables by reference and ask the	user for
 * the account number, month, day, year, county code, sales amount, and
 * shipping weight. The user input will be saved in the variables passed
 * by reference.
 * ______________________________________________________________________
 * INPUT
 * 	accountNum		: User's Account Number
 * 	month			: Numerical Value of Month
 * 	day				: Numerical Value of Day
 * 	year			: Numerical Value for Year
 * 	countyCode		: County Code
 * 	salesAmount		: Sales Amount Before Tax
 * 	shippingWeight	: Shipping Weight
 *
 ***************************************************************************
 *
 * CalcDiscount
 * ______________________________________________________________________
 * This function will accept the month and sales amount as an argument
 * and compute the appropriate discount. Discount will vary based on
 * the month input by the user.
 * ______________________________________________________________________
 * OUTPUT
 *  discount	: The computed discount
 *
 ***************************************************************************
 *
 * CalcSalesTax
 * ______________________________________________________________________
 * This function will accept the county code, sales amount, discount,
 * as an argument. The county name variable will be passed to this
 * function by reference. This function will compute the appropriate
 * sales tax based on the county. This function will also assign the
 * correct county along with the sales tax.
 * ______________________________________________________________________
 * OUTPUT
 *	salesTax	: The computed sales tax
 *
 ***************************************************************************
 *
 * CalcShipping
 * ______________________________________________________________________
 * This function will accept the shipping weight as an argument
 * and compute the proper shipping weight. The shipping cost varies
 * based on the weight. Once the weight has passed the base weight
 * each pound past that base weight will be computed accordingly.
 * ______________________________________________________________________
 * INPUT
 *  baseShipping 	: Flat Rate for Base Shipping
 *  lowestShipping  : Lowest Tier for Shipping Weight
 *  highestShipping : Highest Tier for Shipping Weight
 *
 * OUTPUT
 *	shippingCost	: Computed Total Shipping Costs
 *
 ***************************************************************************
 *
 * OutputInvoice
 * ______________________________________________________________________
 * This function will accept the account number, county name, month,
 * day, year, sales amount, discount, county tax, and shipping costs as
 * an argument. The total will be computed for the invoice. This function
 * will then output the invoice to the user.
 *
 *************************************************************************/

//Function Prototypes
void GetSalesInfo(int 	&accountNum,
			int	&month,
			int 	&day,
			int 	&year,
			char 	&countyCode,
			float &salesAmount,
			int 	&shippingWeight);
float CalcDiscount(int 	 month,
	           float salesAmount);
float CalcSalesTax(char   countyCode,
		   float  salesAmount,
		   float  discount,
		   string &countyName);
float CalcShipping(int shippingWeight);
void OutputInvoice(int    accountNum,
		   string countyName,
		   int	  month,
		   int	  day,
		   int	  year,
		   float  salesAmount,
		   float  discount,
		   float  countyTax,
		   float  shippingCost,
		   float  total);

/**********************************************************************
* CONSTANTS
* --------------------------------------------------------------------
* ORANGE_COUNTY_TAX   	: Orange County Sales Tax Percentage
* SANDIEGO_COUNTY_TAX 	: San Diego County Sales Tax Percentage
* LOSANGELES_COUNTY_TAX	: Los Angeles County Sales Tax Percentage
* BEG_YEAR_DISCOUNT		: Discount for Jan.-May.
* MID_YEAR_DISCOUNT		: Discount for Jun.-Aug.
* END_YEAR_DISCOUNT		: Discount for Sep.-Dec.
*
*********************************************************************/

//Global Constant Variables
const float ORANGE_COUNTY_TAX = 0.0775;
const float SANDIEGO_COUNTY_TAX = 0.0825;
const float LOSANGELES_COUNTY_TAX = 0.08;
const float BEG_YEAR_DISCOUNT = 0.05;
const float MID_YEAR_DISCOUNT = 0.1;
const float END_YEAR_DISCOUNT = 0.15;

int main()
{
	//Variables
	int 	accountNum;	//INPUT  - User's Account Number
	int 	month;		//INPUT  - Numerical Value of Month
	int 	day;		//INPUT  - Numerical Value of Day
	int 	year;		//INPUT	 - Numerical Value of Year
	char 	countyCode;	//INPUT	 - County Code
	float 	salesAmount;	//INPUT  - Sales Amount Before Tax
	int 	shippingWeight;	//INPUT  - Shipping Weight
	string  countyName;	//OUTPUT - String County Name
	float 	discount;	//OUTPUT - Total Discount
	float   countyTax;	//OUTPUT - Total County Tax
	float 	shippingCost;	//OUTPUT - Total Shipping Cost
	float   total;		//OUTPUT - Total Due

	//Header
	cout << "**************************************************";
	cout << "\n* PROGRAMMED BY : Janelle Gwynn M. Hamoy";
	cout << "\n* CLASS         : CSC5";
    	cout << "\n* SECTION       : MW 2:20PM - 5:30PM";
    	cout << "\n* PPROJECT #3   : Repetition & Switch Statement";
	cout << "\n**************************************************";
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		//Call function GetSalesInfo and Get User Information
		GetSalesInfo(accountNum, month, day, year, countyCode,
					salesAmount, shippingWeight);

		//Call Function CalcDiscount Compute Discount
		discount = CalcDiscount(month, salesAmount);

		//Call Function CalcSalesTax Compute Sales Tax
		countyTax = CalcSalesTax(countyCode, salesAmount, discount,
								 countyName);

		//Call CalcShipping and Compute Shipping Costs
		shippingCost = CalcShipping(shippingWeight);

		//Compute Total
		total = salesAmount - discount + countyTax + shippingCost;

		//Call Function OutputInvoice and Output the Invoice
		OutputInvoice(accountNum, countyName, month, day, year,
			      salesAmount, discount,  countyTax, shippingCost,
			      total);
	}
	return 0;
}

/********************************************************************
 * Definition of GetSalesInfo					    *
 * This function will accept variables by reference and ask the	    *
 * user for the account number, month, day, year, county code,	    *
 * sales amount, and shipping weight. The user input will be saved  *
 * in the variables passed by reference.			    *
 ******************************************************************/

void GetSalesInfo(int 	&accountNum,
			int 	&month,
			int 	&day,
			int 	&year,
			char 	&countyCode,
			float &salesAmount,
			int 	&shippingWeight)
{
	cout << endl;
	cout <<"Please Enter your Account Number: ";
	cin >> accountNum;
	cout << "Please Enter the Sales Date." << endl;
	cout << "Enter Month: ";
	cin >> month;
	cout << "Enter Day: ";
	cin >> day;
	cout << "Enter Year: ";
	cin >> year;
	cout << "Please Enter the County Code: ";
	cin >> countyCode;
	while ((countyCode != 'o' && countyCode != 'O') &&
		   (countyCode != 's' && countyCode != 'S') &&
		   (countyCode != 'l' && countyCode != 'L'))
	{
		cout << "Invalid Input! Please only enter O, S, or L: ";
		cin >> countyCode;
	}
	cout<< "Please Enter the Sales Amount: ";
	cin >> salesAmount;
	while (salesAmount < 0)
	{
		cout << "Invalid Input! Please enter a positive number: ";
		cin >> salesAmount;
	}
	cout << "Please Enter the Weight: ";
	cin >> shippingWeight;
	while (shippingWeight < 0)
	{
		cout << "Invalid Input! Please enter a positive number: ";
		cin >> shippingWeight;
	}
	cout << endl;
}

/********************************************************************
 * Definition of CalcDiscount					    *
 * This function will accept the month and sales amount as an	    *
 * argument and compute the appropriate discount. Discount will	    *
 * vary based on the month inputed by the user. This function will  *
 * return the computed discount.				    *
 ******************************************************************/

float CalcDiscount(int month, float salesAmount)
{
	//Variables
	float discount;	//Output - Total Discount

	if (month <= 5)
		discount = salesAmount * BEG_YEAR_DISCOUNT;
	else if (month <= 8)
		discount = salesAmount * MID_YEAR_DISCOUNT;
	else if (month <= 12)
		discount = salesAmount * END_YEAR_DISCOUNT;

	return discount;
}

/********************************************************************
 * Definition of CalcSalesTax				       	    *
 * This function will accept the county code, sales amount, 	    *
 * discount, as an argument. The county name variable will be 	    *
 * passed to this function by reference. This function will compute *
 * the appropriate sales tax based on the county. This function	    *
 * will also assign the correct county appropriate to the sales tax.*
 * This function will return the computed sales tax.		    *
 ******************************************************************/

float CalcSalesTax (char   countyCode,
		    float  salesAmount,
		    float  discount,
		    string &countyName)
{
	//Variables
	float salesTax;	//Output - Total Sales Tax

	switch (countyCode)
	{
		case 'o':
		case 'O': salesTax = (salesAmount - discount) * ORANGE_COUNTY_TAX;
				  countyName = "Orange County";
				  break;
		case 's':
		case 'S': salesTax = (salesAmount - discount)
							  * SANDIEGO_COUNTY_TAX;
				  countyName = "San Diego County";
				  break;
		case 'l':
		case 'L': salesTax = (salesAmount - discount)
							  * LOSANGELES_COUNTY_TAX;
				  countyName = "Los Angeles County";
				  break;
	}
	return salesTax;
}

/********************************************************************
 * Definition of CalcShipping					    *
 * This function will accept the shipping weight as an argument	    *
 * and compute the proper shipping weight. The shipping cost varies *
 * based on the weight. Once the weight has passed the base weight  *
 * each pound past that base weight will be computed accordingly.   *
 * This function will return the calculated shipping costs.	    *
 ******************************************************************/

float CalcShipping(int shippingWeight)
{
	//Variables
	float baseShipping;	//Input  - Flat Rate for Base Shipping
	int lowestShipping;	//Input  - Lowest Tier for Shipping Rate
	int highestShipping;	//Input  - The Flat Rate for Base Shipping
	float shippingCost;	//Output - Total Shipping Costs


	//Initialize Variables
	baseShipping    = 5.00;
	lowestShipping  = 25;
	highestShipping = 50;

	//Compute Shipping Costs Based on Weight
	if (shippingWeight <= lowestShipping)
	{
		shippingCost = baseShipping;
	}
	else if (shippingWeight > lowestShipping &&
			 shippingWeight < highestShipping)
	{
		shippingCost = baseShipping + ((shippingWeight - lowestShipping)
					   * 0.10);
	}
	else if (shippingWeight > highestShipping)
	{
		shippingCost = baseShipping + (lowestShipping * 0.10)
					   + ((shippingWeight - highestShipping)
					   * 0.07);
	}
	return shippingCost;
}

/********************************************************************
 * Definition of OutputInvoice					    *
 * This function will accept the account number, county name, 	    *
 * month, day, year, sales amount, discount, county tax, and 	    *
 * shipping costs as an argument. This function will then output    *
 * the invoice to the user.					    *
 ******************************************************************/

void OutputInvoice(int 	  accountNum,
		   string countyName,
		   int 	  month,
		   int 	  day,
		   int 	  year,
		   float  salesAmount,
		   float  discount,
		   float  countyTax,
		   float  shippingCost,
		   float  total)
{
	cout << "ACCOUNT NUMBER" << setw(33) << "COUNTY" << endl;
	cout << setw(9) << accountNum << setw(42) << countyName << endl;
	cout << endl;
	cout << "DATE OF SALE: " << month << "/" << day << "/" << year << endl;
	cout << endl << endl << setprecision(2) << fixed << showpoint;
	cout << "SALE AMOUNT:" << setw(8) << "$" << setw(8) << salesAmount;
	cout << endl << setprecision(2) << fixed << showpoint;
	cout << "DISCOUNT:" << setw(11) << "$" << setw(8) << discount;
	cout << endl << setprecision(2) << fixed << showpoint;
	cout << "SALES TAX:" << setw(10) << "$" << setw(8) << countyTax;
	cout << endl << setprecision(2) << fixed << showpoint;
	cout << "SHIPPING:" << setw(11) << "$" << setw(8) << shippingCost;
	cout << endl << setprecision(2) << fixed << showpoint;
	cout << "TOTAL DUE:" << setw(10) << "$" << setw(8) << total << endl;
	cout << endl;
}
