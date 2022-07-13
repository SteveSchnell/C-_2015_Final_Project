/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** File: main.cpp,v 1.0 11/15/2015 11:45
** Description:This program dispalys a menu where the user can generate an array, sort and display it
**
** Author: Steve Schnell
** -------------------------------------------------------------------------*/

#include <iostream>
#include "Random.h"//Imports the random class
#include <string>
#include <stdlib.h>

using namespace std;

char *inputCHAR;//This initializes an empty array named inputCHAR

bool isPositive(string N);//This function is used to verify that a number is positive

bool isDigit(string N);//This function is used to check if user input is a number

int main()
{
	int flagRED = 1;//Loop flag for a reset loop

	while (flagRED == 1)//Start the while loop so that the program can be reseted
	{
		flagRED = 0;//Sets the reset flag equal to the row

		int flag = 1,//Loop flag for the repeat loop
			SIZE = 1,//Size of the array
			range = 1;//Range of the numbers

		int *ARRAY;//Initiates a blank int array

		bool BOOL01 = false,//Bool flag to check if the array has been generated
			BOOL02 = false;//Bool flag to check if the array has been sorted

		string tempSIZE;//Temporary string variable

		do{
			system("CLS");//Clears the screen
			cout << "\n         WARNING: Arrays bigger than 50,000 take too long to generate.";//Displays a message
			cout << "\n         Please enter the size of the array :";//Asks the user to enter the size of the array
			cin >> tempSIZE;
		} while (!isPositive(tempSIZE));//Checks if the entered number is a positive number

		SIZE = atoi(tempSIZE.c_str());//Converts the string into an int

		do{
			system("CLS");//Clears the screen
			cout << "\n         Please enter the range of the random numbers that you\n         want to generate : 1 - ";//Asks the user to enter a range of numbers
			cin >> tempSIZE;
		} while (!isPositive(tempSIZE)); //Checks if the entered number is positive

		range = atoi(tempSIZE.c_str());//Converts the string into an int

		ARRAY = new int[SIZE];//Initiates an array to the user selected size

		Random GO(0);//Initiates the random class


		while (flag == 1)//Start the while loop so that the program can be repeaded
		{
			int input,//First input for the menu
				input1,//Second input for the menu
				indexArray = 0;//Index for printing the array

			string tempString;//Temporary location to hold the input

			system("CLS");//Clears the screen

			if (BOOL01)//Checks if the array has been generated
			{
				cout << "\n     The Array :\n     ";//Printa out text

				for (int index = 0; index < SIZE; index++)//Loops through the array
				{
					indexArray++;//Adds one to index array
					cout << ARRAY[index] << " ";//Prints out a number from the array

					if (indexArray == 10)//If ten numbers have been printed out
					{
						cout << "\n     ";//Go down one line
						indexArray = 0;//Index equals zero
					}
				}
			}

			//Prints out the menu
			cout << "\n\n         Enter a 1 for help";
			cout << "\n         Enter a 2 Generate";
			cout << "\n         Enter a 3 to Sort";
			cout << "\n         Enter a 4 to Search";
			cout << "\n         Enter a 5 to calculate the Median";
			cout << "\n         Enter a 6 to calculate the Mode";
			cout << "\n         Enter a 7 to calculate the average";
			cout << "\n         Enter a 8 to restart";
			cout << "\n         Enter a 9 to quit\n  ";
			cin >> tempString;

			if (isPositive(tempString))//Checks if the menu input is a number
			{
				input = atoi(tempString.c_str());//Converts the input into a int

				switch (input) {//Switch that controls the menu options
				case 1://Help option
					system("CLS");//Clears the screen
					cout << "\n\n  ";
					cout << "******************************<HELP>*****************************\n  ";//Prints out the help menu
					cout << "* This program allows the user to create a list of random       *\n  ";
					cout << "* numbers. This list of random numbers can be sorted, searched, *\n  ";
					cout << "* and the media, mode and average can be calculated.            *\n  ";
					cout << "* To start enter 2, to generate the list                        *\n  ";
					cout << "*                                                               *\n  ";
					cout << "* Enter 3 to sort the list                                      *\n  ";
					cout << "* Enter 4 to search for a specific number                       *\n  ";
					cout << "* Enter 5 to calculate the median of the number list            *\n  ";
					cout << "* Enter 6 to calculate the mode of the number list              *\n  ";
					cout << "* Enter 7 to calculate the average of the list                  *\n  ";
					cout << "* Enter 8 to restart the program                                *\n  ";
					cout << "* Enter 9 to quit                                               *\n  ";
					cout << "*****************************************************************\n\n\n";
					system("pause");//Pauses the program
					break;
				case 2://Generate option
					GO.Generate(ARRAY, SIZE, range);//Generates the array
					GO.SaveArray(ARRAY, SIZE);//Save the array to a file
					BOOL01 = true;//Sets generated to true
					BOOL02 = false;//Sets sorter to false
					break;
				case 3://Sort option
					if (BOOL01)//If the array has been generated
					{
						GO.LodeArray(ARRAY, SIZE);//Lodes the array from a text file
						GO.selectionSort(ARRAY, SIZE);//Sorts the array
						GO.SaveArray(ARRAY, SIZE);//Saves the array
						BOOL02 = true;//Sets sorter to two
					}
					else//If the array has not been generated
					{
						system("CLS");//Clears the screen
						cout << "\n         Please generate the array first\n\n";//Displays message
						system("pause");//Pauses the screen
					}
					break;
				case 4://Search option
					if (BOOL02)//If the array has been sorted
					{
						GO.LodeArray(ARRAY, SIZE);//Lods the array

						do{
							system("CLS");//Clears the screen
							cout << "\n         Enter a number  to search for :";//Asks the user to enter a number
							cin >> tempString;
						} while (!isPositive(tempString));//Checks if the user entered a positive number

						input1 = atoi(tempString.c_str());//Converts the input to int
						system("CLS");//Clears the screen
						GO.binarySearch(ARRAY, SIZE, input1);//Searches the array for the entered number
						GO.SaveArray(ARRAY, SIZE);//Saves the array
						system("pause");//Pauses the program
					}
					else//If the array has not been sorted
					{
						system("CLS");//Clears the screen
						cout << "\n         Please sort the array first\n\n";//Displays message
						system("pause");//Pauses the program
					}
					break;
				case 5://Meien option
					if (BOOL02)//If array has been sorted
					{
						GO.LodeArray(ARRAY, SIZE);//Lods the array
						system("CLS");//Clears the screen
						cout << "\n     The median is " << GO.MedianCal(ARRAY, SIZE) << "\n\n\n\n";//Calculates and displays the median
						GO.SaveArray(ARRAY, SIZE);//Saves the array
						system("pause");//Pauses the program
					}
					else//If the array has not been sorted
					{
						system("CLS");//Clears the screen
						cout << "\n         Please sort the array first\n\n";//Displays message
						system("pause");//Pauses the program
					}
					break;
				case 6://Mode option
					if (BOOL02)//If the array has been sorted
					{
						GO.LodeArray(ARRAY, SIZE);//Lods the array
						system("CLS");//Clears the screen
						cout << "\n     The mode is " << GO.ModeCal(ARRAY, SIZE) << "\n\n\n\n";//Calculates and displays the mode
						GO.SaveArray(ARRAY, SIZE);//Save the array
						system("pause");//Pauses the program
					}
					else//If the array has not been sorted
					{
						system("CLS");//Clears the screen
						cout << "\n         Please sort the array first\n\n";//Displays message
						system("pause");//Pauses the program
					}
					break;
				case 7://Average option
					if (BOOL02)//If the array has been sorted
					{
						GO.LodeArray(ARRAY, SIZE);
						system("CLS");//Clears the screen
						cout << "\n     The average is " << GO.AverageCal(ARRAY, SIZE) << "\n\n\n\n";//Calculates and displays the average
						GO.SaveArray(ARRAY, SIZE);//Save the array
						system("pause");//Pauses the program
					}
					else//If the array has not been sorted
					{
						system("CLS");//Clears the screen
						cout << "\n         Please sort the array first\n\n";//Displays message
						system("pause");//Pauses the program
					}
					break;
				case 8://Reset option
					flag = 0;//Sets loop flag to zero
					flagRED = 1;//Sets reset flg to one
					break;
				case 9://Quit option
					flag = 0;//Sets loop flag to zero
					break;
				default:
					break;
				}

			}
		}
	}
	return 0;//End of program
}


bool isPositive(string N)//This function takes a string input and checks if it is a positive number
{
	bool Y;//This is the return variable

	//This checks if the input is a number
	if (isDigit(N))
	{
		//This converts the input into integer
		int X = atoi(N.c_str());

		//If the input is bigger or equal to zero it returns true
		if (X >= 0)
		{
			Y = true;
		}
		//If the input is smaller than zero then the program returns false
		else
		{
			Y = false;
		}
	}
	//If the input is not a number it returns false
	else
	{
		Y = false;
	}
	//Ends the program and returns true or false
	return Y;
}

bool isDigit(string N)//This function takes a string input and checks if it is a number
{
	bool Y;//This is the variable for the return
	int X = N.length();//Sets x to the length of the string
	inputCHAR = new char[X];//Sets the input array to the size of x

	//For loop to add the individual characters of the string to the array
	for (int a = 0; a <= X; a++)
	{
		//Adds the character to the array
		inputCHAR[a] = N[a];
	}

	//For loop to check if the character is a number or not
	for (int i = 0; i < X; i++)
	{
		//If one character is not a number the function ends and return false
		if (!isdigit(inputCHAR[i]))
		{
			Y = false;
			return Y;
		}
	}
	//If the function didn't end yet then the input was only numbers and the function returns true
	Y = true;
	return Y;
}