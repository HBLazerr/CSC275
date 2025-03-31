// Libraries
#include <iostream>
#include "Ninja.h"
#include "Character.cpp"

//Allows you to not type std:: every time
using namespace std;

//child class Ninja inherits from parent class Character
class Ninja : public Character
{
public: //Access type
	//constructor
	Ninja() {
		Name = "Ninja";
	}

	//method that displays throwing stars
	void ThrowStars() {
		cout << Name << ": ";
		cout << "I am throwing stars!\n\n";
	}

	//method prompts user with ninjas ability
	void Sneak() {
		cout << "*The " << Name << " is sneaking*\n\n";
	}

	int Attack() {
		//sets hit point value to 25
		int HitPoints = -25;

	// returns hit points value
		return HitPoints;
	}

	// prompts user with help for ninja
	void Help()
	{
		cout << "HELP: Ninja's can be used to throw stars!" << "\n\n";
	}
};