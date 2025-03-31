// Libraries
#include <string>
#include <iostream>
#include <fstream>
#include "GameIntro.h"

using namespace std;
// function definition for DisplayTitle()
void GameIntro::DisplayTitle()
{
	//displays the title
	cout << "\n\n *** Spaceship Access ***\n";

	// Variables
	string line;
	ifstream infile("Game_Instructions.txt");
	ofstream outfile("output.txt");

    //if statement for input file
    if (infile.is_open())
    {
        if (outfile.is_open())
        {
            while (getline(infile, line))
            {
                //Display input file contents
                cout << line << endl;
                //write input file contents to output file
                outfile << line << "\n";
            }

            //close files
            infile.close();
            outfile.close();
        } //end of if outfile
        else cout << "Unable to open output file." << endl;

    } //end of if infile
    else cout << "Unable to open input file." << endl;

    cout << "\nTo proceed to game: ";
    system("pause");
}

//this function gets the username and returns it.
string GameIntro::GetUserName() {

	string userName;

	cout << "For a personalized experience, please enter your player's name: ";

	//gets the users name and stores it in the vaiable userName
	getline(cin, userName);

	cout << "\n The Spaceship Access Mission. Stow-away: " << userName << "\n\n\n" << endl;

	return userName;
}