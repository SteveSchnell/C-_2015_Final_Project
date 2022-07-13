// ---------------------------------------------------------------------------
// This software is in the public domain, furnished "as is", without technical
// support, and with no warranty, express or implied, as to its usefulness for
// any purpose.
//
// Random.h,v 1.0 11/25/2015 10:50     
// Description:This is a random class. It is used to generate an array, sort and display it and save it to a text file
// 
// Author: Steve Schnell
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include<fstream>
using namespace std;

/* -- global -----------------------------------------------------------------
** void
** LodeArray(int *array, int size)
**
** Description:This function reads an array of a text file
** -------------------------------------------------------------------------*/

/* -- global -----------------------------------------------------------------
** void
** SaveArray(int *array, int size)
**
** Description:This function saves an array to a text file
** -------------------------------------------------------------------------*/

/* -- global -----------------------------------------------------------------
** void
** Generate(int *array, int sizr, int range)
**
** Description:This function generates an array of random numbers
** -------------------------------------------------------------------------*/

/* -- global -----------------------------------------------------------------
** void
** selectionSort(int array[], int size)
**
** Description:This function uses selection sort to sort an array
** -------------------------------------------------------------------------*/

/* -- global -----------------------------------------------------------------
** void
** binarySearch(int array[], int size, int target)
**
** Description:This function uses binary search to search for a number in an array
** -------------------------------------------------------------------------*/

/* -- global -----------------------------------------------------------------
** int
** ModeCal(int a[], int size)
**
** Description:This function calculates a mode in an array
** -------------------------------------------------------------------------*/

/* -- global -----------------------------------------------------------------
** int
** AverageCal(int a[], int size)
**
** Description:This function calculates the average in an array
** -------------------------------------------------------------------------*/

/* -- global -----------------------------------------------------------------
** int
** MedianCal(int a[], int size)
**
** Description:This function calculates the median in an array
** -------------------------------------------------------------------------*/



class Random
{


public:Random(int ZERO)//Constructor of a random class
{
}

	   void Random::LodeArray(int *array, int size)//This function loads an array out of a text file
	   {
		   ifstream Data;//Initiates a new if stream

		   Data.open("project.txt");//Opens a text file named project txt
		   for (int index = 0; index < size; index++)//Loops through the entire text file
		   {
			   Data >> *array;//Sets the text file data to the array pointer
			   array++;//Adds one to the pointer	
		   }
		   Data.close();//Closes the text file
	   }


	   void Random::SaveArray(int *array, int size)//This function saves an array to the text file
	   {
		   ofstream Data;//Initiates the new off stream

		   int temp;//Temporary location of an array variable

		   Data.open("project.txt");//Opens a text file
		   for (int index = 0; index < size; index++)//Loops through the entire array
		   {
			   temp = *array;//Sets array pointer equal to temp
			   array++;//Adds one to the pointer
			   Data << temp;//Saves temp to the text file
			   Data << "\n";//Goes one line down
		   }
		   Data.close();//Closes the text file
	   }


	   void Random::Generate(int *array, int sizr, int range)//This function generates random numbers
	   {

		   for (int index = 0; index < sizr; index++)//Loops through the entire array and generates numbers
		   {
			   *array = rand() % range + 1;//Generates a random number and adds it to the array
			   array++;//Adds one to the pointer
		   }
	   }


	   void Random::selectionSort(int array[], int size)//Selection sort function inputs an array and the size of the array
	   {
		   int startScan,//Starting point of the scan
			   minIndex;//Minimum index of the array

		   int minValue;//Minimum value in the array

		   for (startScan = 0; startScan < (size - 1); startScan++)//For loop runs for the entire lenghts of the array
		   {
			   minIndex = startScan;//Sets the minimum index equal to the starting index
			   minValue = array[startScan];//Sets the minimum value equal to the first number in the array
			   for (int index = startScan + 1; index < size; index++)//For loop goes to the entire array and compares numbers
			   {
				   if (array[index] < minValue)//If the current number is smaller than the minimum number
				   {
					   minValue = array[index];//Sets the minimum value equal to the current number
					   minIndex = index;//Sets the minmum index equal to the current index
				   }
			   }
			   array[minIndex] = array[startScan];//Sets the number at the minimum index equal to the number at the starting index
			   array[startScan] = minValue;//Sets the number at the starting index equal to the minimum value
		   }
	   }

	   void Random::binarySearch(int array[], int size, int target)//This function uses binary search to search for a number
	   {
		   int indexs,//Index of the array
			   lowerbound = 0,//Smallest number
			   upperbound = size;//Largest number

		   int comparisonCount = 1;//count the number of comparisons 

		   // To start, find the subscript of the middle position.
		   indexs = (lowerbound + upperbound) / 2;

		   while ((array[indexs] != target) && (lowerbound <= upperbound))//While the target is not equal to the number in the array
		   {
			   comparisonCount++;//Adds one to the comparison counter
			   if (array[indexs] > target)//Checks if the array is bigger than the target         
			   {
				   upperbound = indexs - 1;//Sets upperbound equal to index minus one
			   }
			   else//If array smaller than target
			   {
				   lowerbound = indexs + 1;//Sets lower bounds equal to index plus one
			   }
			   indexs = (lowerbound + upperbound) / 2;//Sets index to lower bound plus upperbound divided by two
		   }
		   if (lowerbound <= upperbound)//If upperbound is bigger or equal to lowerbound
		   {
			   cout << "\n     The number was found in array indexs " << indexs << "\n\n";//Print out that the number has been found
			   cout << "     The binary search found the number after " << comparisonCount << " comparisons.\n\n";
		   }
		   else//If lowerbound is bigger than upperbound
		   {
			   cout << "\n     Sorry, the number is not in this array.\n\n";//Print out that the number has not been found
			   cout << "     The binary search made " << comparisonCount << " comparisons.\n\n";
		   }
	   }

	   int Random::AverageCal(int a[], int size)//Average function that calculates the average 
	   {
		   int sum = 0;//The sum of all the numbres

		   int *point = a;//Creates a pointer for the array

		   for (int X = 0; X < size; X++)//Loops through the array
		   {
			   sum = sum + *point;//Adds the number to the sum
			   point++;
		   }
		   //delete[]point;//Delete the point
		   return sum / size;//Devides the sum by the size
	   }

	   int Random::ModeCal(int a[], int size)//Mode function that calculates the mode
	   {
		   int *point = new int[size];//Creates a pointer for the array

		   for (int i = 0; i < size; ++i)//Loops through the array
		   {
			   point[i] = 0;//Sets point equal to zero
			   int j = 0;//Sets j equal to zero
			   bool found = false;//Sets found equal to false
			   while ((j < i) && (a[i] != a[j]))//While j is smaller than one, and a at i is not equal to a at j then it loops
			   {
				   if (a[i] != a[j])//If a at i is not equal to a at j
				   {
					   ++j;//Add one to j
				   }
			   }
			   ++(point[j]);//Add one to pointer at j
		   }

		   int iMaxRepeat = 0;//Set iMaxRepeat equal to zero
		   for (int i = 1; i < size; ++i)//Loops through the array
		   {
			   if (point[i] > point[iMaxRepeat])//If pointer at i is bigger than pointer at repeat
			   {
				   iMaxRepeat = i;//iMaxRepeat equal to i
			   }

		   }
		   delete[]point;//Delete the point
		   return a[iMaxRepeat];//Returns a at iMax Repeat
	   }

	   int Random::MedianCal(int a[], int size)//Median function that calculates the median 
	   {
		   int median = 0;
		   int *point = a;//Creates a pointer for the array

		   if ((size % 2) == 0)//If the array is not even
		   {
			   median = (point[size / 2] + point[(size / 2) - 1]) / 2;//Calculates the middle number
		   }
		   else//If the array is odd
		   {
			   median = point[size / 2];//Calculates the middle number
		   }
		   //delete[]point;//Delete the point
		   return median;//Returns the middle number
	   }

};






