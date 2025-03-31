// Hero Creator version 1.0
// Daniel Chavez
// Demo video - 


// Libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "CreatorIntro.h" //for DisplayTitle function
#include "ExitCreator.h" //for CreatorExit function

using namespace std;


// Base Class Hero
class Hero {
private:
    // Variables
    string Name;
    string Type;
    int Level;
    string Origin;
    string Weapon;
    int Eliminations;
    string Colors;

public:
    //constructor to initialize variables and assign values
    Hero(string name, string type, int level, string origin, string weapon, int eliminations, string colors) : Name(name), Type(type), Level(level), Origin(origin), Weapon(weapon), Eliminations(eliminations), Colors(colors) {}

    // Get functions
    string getName() {
        return Name;
    }
    string getType() {
        return Type;
    }
    int getLevel() {
        return Level;
    }
    string getOrigin() {
        return Origin;
    }
    string getWeapon() {
        return Weapon;
    }
    int getEliminations() {
        return Eliminations;
    }
    string getColors() {
        return Colors;
    }


    // Set functions
    void setName(string name) {
        Name = name;
    }
    void setType(string type) {
        Type = type;
    }
    void setLevel(int level) {
        Level = level;
    }
    void setOrigin(string origin) {
        Origin = origin;
    }
    void setWeapon(string weapon) {
        Weapon = weapon;
    }
    void setEliminations(int eliminations) {
        Eliminations = eliminations;
    }
    void setColors(string colors) {
        Colors = colors;
    }


    // Data handling functions
    void displayInfo() {
        cout << "Name: " << Name << endl;
        cout << "Type: " << Type << endl;
        cout << "Level: " << Level << endl;
        cout << "Origin: " << Origin << endl;
        cout << "Weapon: " << Weapon << endl;
        cout << "Eliminations: " << Eliminations << endl;
        cout << "Suit Colors: " << Colors << endl;
    }
    void saveInfo(ofstream& outfile) {
        outfile << Name << endl;
        outfile << Type << endl;
        outfile << Level << endl;
        outfile << Origin << endl;
        outfile << Weapon << endl;
        outfile << Eliminations << endl;
        outfile << Colors << endl;
    }
    void loadInfo(ifstream& infile) {
        getline(infile, Name);
        getline(infile, Type);
        infile >> Level;
        getline(infile, Origin);
        getline(infile, Weapon);
        infile >> Eliminations;
        getline(infile, Colors);
        infile.ignore();
    }
};


//child class Hunter
class Hunter : public Hero {
private:
    bool Stealth;

public:
    string Type = "Hunter";

    // constructor for hunter class
    Hunter(string name, string type, int level, string origin, string weapon, int eliminations, string colors, bool stealth) : Hero(name, type, level, origin, weapon, eliminations, colors), Stealth(stealth) {}
    
    //displays info of Hunter object
    void displayInfo() {
        Hero::displayInfo();
        cout << "Stealth Mode: " << (Stealth ? "On" : "Off") << endl;
    }
    //saves the info of Hunter object to .txt file
    void saveInfo(ofstream& outfile) {
        Hero::saveInfo(outfile);
        outfile << Stealth << endl;
    }
    //loads the info of Hunter object to .txt file
    void loadInfo(ifstream& infile) {
        Hero::loadInfo(infile);
        infile >> Stealth;
        infile.ignore();
    }
};

//child class Warlock
class Warlock : public Hero {
private:
    bool Spellcast;

public:
    string Type = "Warlock";

    // constructor for Warlock class
    Warlock(string name, string type, int level, string origin, string weapon, int eliminations, string colors, bool spellcast) : Hero(name, type, level, origin, weapon, eliminations, colors), Spellcast(spellcast) {}

    //displays info of Warlock object
    void displayInfo() {
        Hero::displayInfo();
        cout << "Spell Casting: " << (Spellcast ? "On" : "Off") << endl;
    }
    //saves the info of Warlock object to .txt file
    void saveInfo(ofstream& outfile) {
        Hero::saveInfo(outfile);
        outfile << Spellcast << endl;
    }
    //loads the info of Warlock object from file
    void loadInfo(ifstream& infile) {
        Hero::loadInfo(infile);
        infile >> Spellcast;
        infile.ignore();
    }
};


class HeroCreator {
public:
    //creates vector of pointers to Hero class objects
    //allows to create the hero types
    vector<Hero*> heroes;

    void createHunter() {
        string Name;
        string Type = "Hunter";
        int Level;
        string Origin;
        string Weapon;
        int Eliminations;
        string Colors;
        bool Stealth = true;


        //// Ask and get user input
        cout << "\nExcellent choice! Hunters have a special stealth ability.\n\n";

        cout << "Stealth Mode: " << (Stealth ? "On" : "Off") << endl;
        cout << "Choose a name for your hero: ";
        getline(cin, Name);

        cout << "Set a level for " << Name << " (NOTE: their level is how old they are): ";
        cin >> Level; 
        cin.ignore();

        cout << "Create " << Name << "'s origin: ";
        getline(cin, Origin);

        cout << "Assign a special weapon for your Hunter: ";
        getline(cin, Weapon);

        cout << "How many lives has " << Name << " taken? ";
        cin >> Eliminations;

        cout << "Lastly, choose their two suit colors: ";
        cin.ignore();
        getline(cin, Colors);


        // adds new Hunter object with parameters to the end of the heroes vector.
        //push.back puts it at end of heroes vector
        heroes.push_back(new Hunter(Name, Type, Level, Origin, Weapon, Eliminations, Colors, Stealth));
        cout << "\nHero successfully created. ";
        system("pause");
    }
    
    void createWarlock() {
        string Name;
        string Type = "Warlock";
        int Level;
        string Origin;
        string Weapon;
        int Eliminations;
        string Colors;
        bool Spellcast = true;


        //// Ask and get user input
        cout << "\nWise selection. Warlocks have a spellcasting ability!\n\n";

        cout << "Spell Casting: " << (Spellcast ? "On" : "Off") << endl;
        cout << "Choose a name for this hero: ";
        getline(cin, Name);

        cout << "Set a level for " << Name << " (NOTE: their level is how old they are): ";
        cin >> Level; 
        cin.ignore();

        cout << "Create " << Name << "'s origin: ";
        getline(cin, Origin);

        cout << "Assign a unique weapon for this Warlock: ";
        getline(cin, Weapon);

        cout << "How many lives has " << Name << " taken? ";
        cin >> Eliminations;

        cout << "Lastly, choose two suit colors: ";
        cin.ignore();
        getline(cin, Colors);


        // adds new Warlock object with parameters to the end of the heroes vector.
        //push.back puts it at end of heroes vector
        heroes.push_back(new Warlock(Name, Type, Level, Origin, Weapon, Eliminations, Colors, Spellcast));
        cout << "\nHero successfully created. ";
        system("pause");
    }


    // Prints list of heroes to console
    void displayHeroes() {
        //checks if heroes is empty
        if (heroes.empty()) {
            cout << "You have not created any heroes yet.\n";
            return;
        }
        else {
            system("pause");

            cout << "\n\t*** All Created Heroes and Features ***\n\n";
            // loops through all heroes and calls their display function
            for (int i = 0; i < heroes.size(); i++) {
                heroes[i]->displayInfo();
                cout << endl;
             }
        }
    }

    // Saves list of heroes to file
    void saveHeroes() {
        //checks if heroes is empty
        if (heroes.empty()) {
            cout << "You have not created any heroes yet.\n";
        }
        else {
            ofstream outfile("heroes.txt");
            if (outfile.is_open()) {
                //write each hero's information to the file
                for (int i = 0; i < heroes.size(); i++) {
                    heroes[i]->saveInfo(outfile);
                }
                outfile.close();
                cout << "All Heroes have been saved to file.\n";
            }
            else {
                cout << "Error: Unable to open file. Please try again.\n";
            }
        }
    }

    // Loads list of heroes from file
    void loadHeroes() {
        ifstream infile("heroes.txt");
        if (infile.is_open()) {
            string name;
            string type;
            int level;
            string origin;
            string weapon;
            int eliminations;
            string colors;


            //read in each heros information from the file and create new hero objects
            while (getline(infile, name)) {
                getline(infile, type);
                infile >> level;
                getline(infile, origin);
                getline(infile, weapon);
                infile >> eliminations;
                getline(infile, colors);
                infile.ignore();

                if (type == "Hunter") {
                    bool stealth;
                    infile >> stealth;
                    heroes.push_back(new Hunter(name, "Hunter", level, origin, weapon, eliminations, colors, true));
                }
                else if (type == "Warlock") {
                    bool spellcast;
                    infile >> spellcast;
                    heroes.push_back(new Warlock(name, "Warlock", level, origin, weapon, eliminations, colors, true));
                }
            }

            infile.close();
            cout << "All heroes have been loaded from file." << endl;
        }
        else {
            cout << "Error: Unable to open file. Please try again.\n";
        }
    }

};


int main()
{
    // Objects
    //instance of CreatorIntro
    CreatorIntro obj_creatorIntro;
    //instance of CreatorExit
    CreatorExit obj_exitCreator;
    //instance of HeroCreator
    HeroCreator obj_heroCreator;

    //sets custom console app colors
    system("Color 01");

    //calls DisplayTitle method
    obj_creatorIntro.DisplayTitle();
    
    int choice;
    do
    {
        // show menu options
        cout << "\nOptions:\n";
        cout << "1. Create a Hero\n";
        cout << "2. Display Heroes\n";
        cout << "3. Save Current Heroes\n";
        cout << "4. Load Previous Heroes\n";
        cout << "0. Quit\n";
        cout << "\nEnter your choice: ";
        cin.clear();
        
        //get & evaluate choice
        cin >> choice;
        cout << endl;
        if (choice == 1)
        {
            //variable to store users second choice
            string choiceHero;

            //hero menu
            cout << "\nOptions:\n";
            cout << "A) Create a Hunter\n";
            cout << "B) Create a Warlock\n";
            cout << "\nEnter your choice: ";
            cin.ignore();

            //get & evaluate users hero choice
            getline(cin, choiceHero);
            cout << endl;
            if (choiceHero == "A" || choiceHero == "a") {
                obj_heroCreator.createHunter();
            }
            else if (choiceHero == "B" || choiceHero == "b") {
                obj_heroCreator.createWarlock();
            }
            else {
                //this just chooses hunter for them
                obj_heroCreator.createHunter();
            }

        }
        else if (choice == 2)
        {
            //Shows created heroes and/or loaded heroes from heroes.txt file
            obj_heroCreator.displayHeroes(); 
        }
        else if (choice == 3)
        {
            //Saves all current heroes to .txt file
            obj_heroCreator.saveHeroes();
        }
        else if (choice == 4)
        {
            //Loads all heroes from .txt file
            obj_heroCreator.loadHeroes();
        }
        else if (choice == 0)
        {
            //Displays goodbye prompt
            obj_exitCreator.ExitCreator();
        }
        else {
            cout << "\nSorry, try entering a valid option.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } 

    } while (choice != 0);

    return 0;
} 