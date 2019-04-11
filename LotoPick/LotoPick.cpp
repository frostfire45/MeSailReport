// LotoPick.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

//const unsigned short NUM_MAX = 54;
#define NUM_OF_PICKS 6;
#define NUM_MAX 54;

 // Go to header file
short initialization();
unsigned short * weGenerate(unsigned short *);
unsigned short * userEntered(unsigned short *);
int generateRandNum();
bool isWinner(unsigned short *, int);
int main()
{
	//const unsigned short TOTALPICKS = NUM_OF_PICKS;
	//const unsigned short MAXVALUE = NUM_MAX;
	 // HardCode
	unsigned short numPicked[] = { 0,0,0,0,0,0,0 };
	unsigned short *p;
	p = numPicked;

	// Generate Lucky Number
	int luckyNum = generateRandNum();
	
	// Initialzation
	short choice = 0;
	choice = initialization();

	// Decision made, generate or get numbers
	if (choice == 1) {
		weGenerate(p);
	}
	else
		userEntered(p);

	// Determine Winner of Chicken Dinner
	if (isWinner) {
		cout << "We have a winner!!";
	}
	else
		cout << "Thanks for the cash chump!";
	// Play again
	cout << "Would you like to play again? 1: Yes, 2: No:   \n";	  	
	cin >> choice;
	if (choice == 1) {

	}

}
 /*
 ================================
	Function initialzation 
 ================================
	No Params
---------------------------------
 1) Initial splash / welcome display
 2) Can be used to reinitialize program for repeatability
 --------------------------------
 */

short initialization() {
	cout << "Welcome to your quick pick loto \n";
	cout << "You have a choice, either you pick your numbers or you let me pick\n";
	cout << "Remember fortune favors the bold: NOW PICK!!\n";
	cout << "1: We pick the 6 numbers\n";
	cout << "2: You pick the 6 numbers\n";
	int choice = 0;
	cin >> choice;

	switch (choice) {
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	default:
		cout << "THe number you entered is invalid";
		break;
	}			
}

/* ========================================================
   Function weGenerate
===========================================================
   Param1: unsigned short pointer to Array of stored values.
   Dependant Lib: ctime.h (standard compiler include)
-----------------------------------------------------------
 1) Seeds random number with NULL time value
 2) Generates random numbers based on User inputed number
 3) Returns modified refrenced address back to main
 ----------------------------------------------------------
 */
unsigned short * weGenerate(unsigned short *r) {

	// set the seed
	srand((unsigned)time(NULL));

	for (int i = 0; i < 6; ++i) {
		r[i] = rand();
		cout << r[i] << endl;
	}

	return r;
}
/* ========================================================
   Function userEntered
===========================================================
   Param1: unsigned short pointer to Array of stored values.
   Dependant Lib: None
-----------------------------------------------------------
 1) Present question to enter number to user
 2) Test Number entered with previous entries
 3) Test Number against out of bounds
 4) Stores number in Array
 5) Provides Error generation for out of bounds or same num
 ----------------------------------------------------------
 */
unsigned short * userEntered(unsigned short *r) {
	short tempstorage = 0;
	cout << "Enter your numbers: ";


	for (short i = 0; i < 6; i++) {
		cin >> tempstorage;
		// Does Number exsist

		for (short j = 0; j < i; j++) {
			if (tempstorage == r[j]) {
				i = i - 1;
				cout << "Number " << tempstorage << " Already Exsists";
			}
		}
		if (tempstorage < 55 && tempstorage >= 0) {
			r[i] = tempstorage;
		}
		else {
			if (tempstorage > 55) {
				cout << "Your values is to high \n";
				i = i - 1;
			}
			else {
				cout << "You cannot enter a negative number\n";
			}
		}
		
	}
	return r;
}
/* ========================================================
   Function generateRandNum
===========================================================
   Param: None
   Dependant Lib: ctime.h (standard compiler include)
-----------------------------------------------------------
 1) Seeds random number with NULL time value
 2) Generates random numbers based on bounds 1 - 56
 3) Returns int number back to main
 ----------------------------------------------------------
 */
int generateRandNum() {
	srand(time(NULL));
	int number = rand() % 100 + 1;
	return number;
}

bool isWinner(unsigned short *r, int winNum) {
	for (short i = 0; i < 6; i++) {
		if (r[i] == winNum) {
			return true;
		}
	}
	return false;
}
