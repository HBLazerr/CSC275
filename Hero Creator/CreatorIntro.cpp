// Libraries
#include <string>
#include <iostream>
#include "CreatorIntro.h"

using namespace std;

// Define DisplayTitle() function.
void CreatorIntro::DisplayTitle()
{

	//displays the title
	cout << "\n\n\t\t *** Custom Hero Creator ***\n";
	cout << "An interactive simulation where you can create your own custom superheroes\n";
	cout << "by choosing many of their characteristics and abilities. You are tasked with \n";
	cout << "setting your hero's type, weapon, level, and more!\n\n";
	cout << "To access the menu, ";
	system("pause");
}