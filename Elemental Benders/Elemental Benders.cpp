// Elemental Benders Version 1.0
//Daniel Chavez

// Libraries
#include <iostream>
#include <string>

using namespace std;

// Prototype functions

//Water benders
void discoverNewWaterTribe(int* newWaterBenderCode, string* newWaterTribeName);
void updateWaterBenders(int* newWaterBenderCount);

//Fire benders
void discoverNewFireTribe(int* newFireBenderCode, string* newFireTribeName);
void updateFireBenders(int* newFireBenderCount);


int main()
{
	// Title
	cout << "\n\n\t*** The Last Elemental Benders ***\n\n" << endl;

	// Variables below
	int ElementalBenders = 103;
	
	//Water Benders
	string WaterTribe = "Northern Water Tribe";
	string newWaterTribe = "Undiscovered Water Tribe";

	//Fire Benders
	string FireTribe = "Eastern Fire Tribe";
	string newFireTribe = "Undiscovered Fire Tribe";


	// Pointers below
	// * is used to create pointers
	// & is the address of operator

	//Water Benders
	int* WaterBendersCode = &ElementalBenders;
	string* newTribe_Water = &newWaterTribe;

	//Fire Benders
	int* FireBendersCode = &ElementalBenders;
	string* newTribe_Fire = &newFireTribe;


	cout << "Current " << WaterTribe << " water benders left: " << ElementalBenders << endl;

	// WATER Tribe
	//function changes the value is was pointing to
	updateWaterBenders(WaterBendersCode);
	cout << "\nNow, the water bender population is: " << ElementalBenders << endl;

	cout << "\nAll of the current known water benders live in world code: " << WaterBendersCode << endl;
	cout << "NOTE: world code is like a zip code\n";

	cout << "\nJust below the " << WaterTribe << ", water tribe members have found '" << newWaterTribe << "'.\n";
	cout << "The " << newWaterTribe << " village is located in world code: " << newTribe_Water << "\n";

	//FIRE Tribe
	//function changes the value is was pointing to
	updateFireBenders(FireBendersCode);
	cout << "\nNow, the fire bender population is: " << ElementalBenders << endl;

	cout << "\nAll of the current known fire benders live in world code: " << FireBendersCode << endl;
	cout << "NOTE: world code is like a zip code\n";

	cout << "\nJust below the " << FireTribe << ", fire tribe members have found '" << newFireTribe << "'.\n";
	cout << "The " << newFireTribe << " village is located in world code: " << newTribe_Fire << "\n";

	// WATER Tribe
	//function changes 
	discoverNewWaterTribe(WaterBendersCode, newTribe_Water);

	cout << "\nThe " << newWaterTribe << " village is still located in world code: " << newTribe_Water << endl;
	cout << "\nAfter Combining the " << WaterTribe << " with the " << newWaterTribe << ", the world code for all known water benders is " << &WaterBendersCode << ".\n";
	
	//Fire Tribe
	//function changes 
	discoverNewFireTribe(FireBendersCode, newTribe_Fire);

	cout << "\nThe " << newFireTribe << " village is still located in world code: " << newTribe_Fire << endl;
	cout << "\nAfter Combining the " << FireTribe << " with the " << newFireTribe << ", the world code for all known fire benders is " << &FireBendersCode << ".\n";
}


//changes the known water benders world code and the newWaterTribe name
void discoverNewWaterTribe(int* newWaterBenderCode, string* newTribeName)
{
	//displays newTribeName value before changing it
	cout << "\nBefore discovering the unknown tribe we called it '" << *newTribeName << "'.";
	(*newTribeName) = "Southern Water Tribe";
	//displays newTribeName value after changing it
	cout << "\nAfter meeting the fellow people of this tribe, we have decided to refer to them as the '" << *newTribeName << "'.\n";

	(newWaterBenderCode) += 1;
	//displays newWaterBenderCode value after changing it
	cout << "The world code for the highest ranking water bender is " << &newWaterBenderCode << endl;
}

//changes the WaterBender Variable to a new value
void updateWaterBenders(int* newWaterBenderCount)
{
	//display newWaterBenderCount value before changing it
	cout << "\nBefore adding the new benders to the total known water benders in the world, the number of water benders was: " << *newWaterBenderCount << endl;
	//adds 213 to newWaterBenderCount pointer
	(*newWaterBenderCount) += 213;
	//displays newWaterBenderCount value after changing it
	cout << "After counting the new tribe water benders, the new known water bender's population is: " << *newWaterBenderCount << endl;
}

void discoverNewFireTribe(int* newFireBenderCode, string* newTribeName)
{
	//displays newTribeName value before changing it
	cout << "\nBefore discovering the unknown tribe we called it '" << *newTribeName << "'.";
	(*newTribeName) = "Western Fire Tribe";
	//displays newTribeName value after changing it
	cout << "\nAfter meeting the fellow people of this tribe, we have decided to refer to them as the '" << *newTribeName << "'.\n";

	(newFireBenderCode) += 1;
	//displays newFireBenderCode value after changing it
	cout << "The world code for the highest ranking fire bender is " << &newFireBenderCode << endl;
}

void updateFireBenders(int* newFireBenderCount)
{
	//display newFireBenderCount value before changing it
	cout << "\nBefore adding the new benders to the total known fire benders in the world, the number of fire benders was: " << *newFireBenderCount << endl;
	//adds 213 to newFireBenderCount pointer
	(*newFireBenderCount) += 213;
	//displays newFireBenderCount value after changing it
	cout << "After counting the new tribe fire benders, the new known fire bender's population is: " << *newFireBenderCount << endl;
}