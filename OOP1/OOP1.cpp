// Libraries
#include <iostream>
#include "OOP1.h"
#include "Pirate.cpp"
#include "Ninja.cpp"

//Allows you to not type std:: every time
using namespace std;
int main()
{
    // Displays Intro
    GameIntro();
    
    // Objects
    Pirate pirate;
    Ninja ninja;

    //Displays game prompts from pirate and ninja class
    ninja.ThrowStars();
    pirate.UseSword();
    ninja.Sneak();
    pirate.BirdFind();

    //exits function
    return 0;
}

// Game introduction prompt
void GameIntro()
{
    cout << "\n\n\tWelcome to Pirate Vs Ninja!\n\n";
    cout << "A simulation fight between a pirate and a ninja.\n\n\n" << endl;
}
