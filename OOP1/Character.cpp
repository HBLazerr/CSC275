#pragma once
#include "Character.h"
#include <string>
#include <iostream>


using namespace std;
class Character
{
	//define private variable
private:
	int Health = 100;

	//define public variables
public:
	string Name = "";

	// Setter
	void setHealth(int hp) {
		Health = hp;

		//evaluates health
		if (hp < 0)
		{
			//sets health to 0 and prompts user
			Health = 0;
			cout << "Character has Expired...\n\n";
		}
	}

	// Getter
	int getHealth() {
		return Health;
	}

	// Displays name and dialog
	void Talk() {
		cout << Name << ": ";
		cout << "something here to say!\n\n";
	}

	// Overloading polymorphism method which displays name and dialog
	void Talk(string name, string dialog) {
		cout << name << ": " << dialog << "\n\n";
	}

	// 10 hit points
	virtual int Attack() {
		int HitPoints = -10;

		return HitPoints;
	}

	// Overridden method
	void Help() {
	}
};
