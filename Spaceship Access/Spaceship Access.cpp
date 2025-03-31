// Spaceship Access v1

// Libraries
#include <iostream>
#include <string>
#include <stdlib.h>
#include "GameIntro.h"
#include "Spaceship Access.h"

// Main Function
using namespace std;
int main()
{
	//instance of GameIntro class
	GameIntro obj_gameIntro;

	/* Changes console BG to black(0)
	and FG to purple () */
	system("Color 05");

	//Displays introduction
	obj_gameIntro.DisplayTitle();

	//gets the users input/name
	string userName = obj_gameIntro.GetUserName();


	// first code to crack into
	CodeOne(userName);

	// second code to crack into
	CodeTwo(userName);

	return 0;
}

void CodeTwo(string& userName)
{
	try {
		//code #2
		string symbolCode = "@$%^";

		//second prompt
		cout << "*" << userName << " goes to door #2 but this time with a different persons access card* \n The card you found has a different code this time. The code is a symbol pattern: " << symbolCode << "\n\n";
		cout << "*" << userName << " walks to the private quarters* \n Theres a door but the keycard won't scan so you have to type it manually. What's the code?\n\n";

		//created variable string userChoice
		string userChoice;

		//gets user choice
		getline(cin, userChoice);

		if (userChoice == "@$%^")
		{
			cout << "That is correct! Now go in and take everything" << endl;

			try {
			cout << "There is a locked box, guess the 4 digit code. 1 2 * 4\n";
			cout << "Type with no spaces.\n\n";

				string lockBoxGuess;
				getline(cin, lockBoxGuess);
			
				if (lockBoxGuess == "1234")
				{
					cout << "Nice you unlocked it and got two diamonds!\n\n";
				}
				else {
					throw 101;
				}
			}
			catch (int FailedLockBox) {
				if (FailedLockBox == 101) {
					cout <<"It was not the right pin.. \n\n";
				cout << "Didn't get in!\n\n";
				}
				else {
					cout << "A problem has occurred.\n\n";
				}
			}
		}
		else {
			throw 101;
		}
	}
	catch (int FailedEntry) {
		if (FailedEntry == 101) {
		cout << "Access denied - You cannot get in private room #2.\n";
		cout << "Leave before you get caught. Mission failed, incorrect symbol code.\n\n";
		}
		else {
			cout << "A problem has occurred.\n\n";
		}
	}
}

void CodeOne(string& userName)
{
	try {
		// code #1
		string codeNumber = "1091108";

		// displays first prompt with users name
		cout << "*" << userName << " gets in through the security entrance* \n You look for a person with an access card and find one with code number #" << codeNumber << "\n\n";
		cout << "*" << userName << " walks to the private quarters* \n You see a door to try and loot by unlocking it with the access card. What's the code number?\n\n";

		//created variable string userChoice
		string userChoice;

		//gets user choice
		getline(cin, userChoice);

		// evaluates userChoice
		if (userChoice == "1091108") {
			cout << "Access granted - you managed to get in to the private room #1 and loot it.\n";

			try {
				cout << "There is a locked box, guess the 4 digit code. 4 * 2 1\n";
				cout << "Type with no spaces.\n\n";

				string safeCodeGuess;
				getline(cin, safeCodeGuess);
				
				if (safeCodeGuess == "4321")
				{
					cout << "Nice you unlocked it and got a weapon!\n\n";
				}
				else {
					throw 101;
					cout << safeCodeGuess << " was not the right code.. \n";
				}
			} 
			catch (int FailedSafeCrack) {
				if (FailedSafeCrack == 101) {
				cout << "you didn't crack the safe!\n";
				}
				else {
					cout << "A problem has occurred.\n\n";
				}
			}
			cout << "Onto the next room.\n\n";
		}
		else {
			throw 101;
		}
	}
	catch (int incorrectCode) {
		if (incorrectCode == 101) {
		cout << "Access denied - You cannot get in private room #1 on time.\n";
		} 
		else {
			cout << "A problem has occurred.\n\n";
		}
	}
}
