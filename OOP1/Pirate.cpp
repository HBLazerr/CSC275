// Libraries
#include <iostream>
#include "Pirate.h"
#include "Character.cpp"

// you wont have to put std:: everytime now
using namespace std;

//child class Pirate inherits from parent class Character
class Pirate : public Character
{
public: //Access type
	//constructor
	Pirate() {
		Name = "Pirate";
	}

	//method that displays swinging a sword
	void UseSword() {
		cout << Name << ": ";
		cout << "I am swinging my sword!\n\n";
	}

	// method that prints pirates ability
	void BirdFind() {
		cout << "*The " << Name << " sends his parrot to find and attack the ninja*\n\n";
	}

	int Attack() {
		//sets hit point value to 25
		int HitPoints = -25;

		// returns hit points value
		return HitPoints;
	}

	// prompts user with help for pirate
	void Help()
	{
		cout << "HELP: Pirate's can be used to swing swords!" << "\n\n";
	}
};