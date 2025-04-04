// Hero Creator version 1.0
// Daniel Chavez
// Demo video - 


// Libraries
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //for sorting feature
#include <unordered_map> //for hash table
#include <queue> //for Breadth First Search (BFS) graph
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
    string Faction; //stores faction/group that the hero belongs to

public:
    //constructor to initialize variables and assign values
    Hero(string name, string type, int level, string origin, string weapon, int eliminations, string colors, string faction) : Name(name), Type(type), Level(level), Origin(origin), Weapon(weapon), Eliminations(eliminations), Colors(colors), Faction(faction) {}

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
	string getFaction() {
		return Faction;
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
	void setFaction(string faction) {
		Faction = faction;
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
		cout << "Faction: " << Faction << endl;
    }
    void saveInfo(ofstream& outfile) {
        outfile << Name << endl;
        outfile << Type << endl;
        outfile << Level << endl;
        outfile << Origin << endl;
        outfile << Weapon << endl;
        outfile << Eliminations << endl;
        outfile << Colors << endl;
		outfile << Faction << endl;
    }
    void loadInfo(ifstream& infile) {
        getline(infile, Name);
        getline(infile, Type);
        infile >> Level;
        getline(infile, Origin);
        getline(infile, Weapon);
        infile >> Eliminations;
        getline(infile, Colors);
		getline(infile, Faction);
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
    Hunter(string name, string type, int level, string origin, string weapon, int eliminations, string colors, string faction, bool stealth) : Hero(name, type, level, origin, weapon, eliminations, colors, faction), Stealth(stealth) {}
    
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
    Warlock(string name, string type, int level, string origin, string weapon, int eliminations, string colors, string faction, bool spellcast) : Hero(name, type, level, origin, weapon, eliminations, colors, faction), Spellcast(spellcast) {}

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

    //map used to quickly look up heroes by name
    unordered_map<string, Hero*> heroMap;

    //maps faction name to list of hero names
    unordered_map<string, vector<string>> factionGraph;

    //assigns aka maps their hero name to faction 
    // this is so it can reverse lookup
    unordered_map<string, string> heroFactions;

    // hero graph
    //each hero is a node connected to others in same faction
    unordered_map<string, vector<string>> heroGraph;


	//made some default factions to start with
    HeroCreator() {
        //no heroes assigned yet
        factionGraph["New Reign"];
        factionGraph["Hearts Break"];
        factionGraph["Assassins Syndicate"];
        factionGraph["Emptic Clan"];
    }


    void createHunter() {
        string Name;
        string Type = "Hunter";
        int Level;
        string Origin;
        string Weapon;
        int Eliminations;
        string Colors;
        string Faction;
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

        cout << "Choose their two suit colors (One, Two): ";
        cin.ignore();
        getline(cin, Colors);

		cout << "\nAvailable factions: New Reign, Hearts Break, Assassins Syndicate, Emptic Clan\n";
        cout << "Which faction does " << Name << " belong to? ";
        getline(cin, Faction);



        // adds new Hunter object with parameters to end of heroes vector
        //push.back puts it at end of heroes vector
        heroes.push_back(new Hunter(Name, Type, Level, Origin, Weapon, Eliminations, Colors, Faction, Stealth));
        heroMap[Name] = heroes.back(); //also add to map for fast lookup

        factionGraph[Faction].push_back(Name); //track faction
        heroFactions[Name] = Faction;

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
        string Faction;
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

        cout << "Which faction does " << Name << " belong to? ";
        getline(cin, Faction);


        // adds new Warlock object with parameters to end of heroes vector
        //push.back puts it at end of heroes vector
        heroes.push_back(new Warlock(Name, Type, Level, Origin, Weapon, Eliminations, Colors, Faction, Spellcast));
        heroMap[Name] = heroes.back(); //also add to map for fast lookup

		factionGraph[Faction].push_back(Name); //track faction
        heroFactions[Name] = Faction;

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

            //ask user how they want the list sorted
            int sortChoice;
            cout << "\nHow would you like to sort the heroes?\n";
            cout << "1. Name (A-Z)\n";
            cout << "2. Level (Lowest to Highest)\n";
            cout << "3. Eliminations (Lowest to Highest)\n";
            cout << "Enter your choice: ";
            cin >> sortChoice;

            //create a copy of the hero list so we don't affect the original
            vector<Hero*> sortedHeroes = heroes;

            //define sort options
            switch (sortChoice) {
            case 1:
                sort(sortedHeroes.begin(), sortedHeroes.end(), [](Hero* a, Hero* b) {
                    return a->getName() < b->getName();
                    });
                break;
            case 2:
                sort(sortedHeroes.begin(), sortedHeroes.end(), [](Hero* a, Hero* b) {
                    return a->getLevel() < b->getLevel();
                    });
                break;
            case 3:
                sort(sortedHeroes.begin(), sortedHeroes.end(), [](Hero* a, Hero* b) {
                    return a->getEliminations() < b->getEliminations();
                    });
                break;
            default:
                cout << "Invalid choice. Showing unsorted list.\n";
            }

            cout << "\n\t*** All Created Heroes and Features ***\n\n";

            //display each hero from the sorted list
            for (int i = 0; i < sortedHeroes.size(); i++) {
                sortedHeroes[i]->displayInfo();
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
			string faction; 


            //read in each heros information from the file and create new hero objects
            while (getline(infile, name)) {
                getline(infile, type);
                infile >> level;
                infile.ignore();

                getline(infile, origin);
                getline(infile, weapon);
                infile >> eliminations;
                infile.ignore();

                getline(infile, colors);
                getline(infile, faction);

                if (type == "Hunter") {
                    bool stealth;
                    infile >> stealth;
                    heroes.push_back(new Hunter(name, "Hunter", level, origin, weapon, eliminations, colors, faction, true));
					heroMap[name] = heroes.back(); //add to hash table

                    factionGraph[faction].push_back(name); //rebuild faction graph
                    heroFactions[name] = faction; //rebuild reverse map

                    //reconnect heroes in same faction after loading
                    for (const auto& pair : heroFactions) {
                        if (pair.first != name && pair.second == faction) {
                            heroGraph[name].push_back(pair.first);
                            heroGraph[pair.first].push_back(name);
                        }
                    }

                }
                else if (type == "Warlock") {
                    bool spellcast;
                    infile >> spellcast;
                    heroes.push_back(new Warlock(name, "Warlock", level, origin, weapon, eliminations, colors, faction, true));
					heroMap[name] = heroes.back(); //add to hash table

                    factionGraph[faction].push_back(name); //rebuild faction graph
                    heroFactions[name] = faction; //rebuild reverse map

                    //reconnect heroes in the same faction after loading
                    for (const auto& pair : heroFactions) {
                        if (pair.first != name && pair.second == faction) {
                            heroGraph[name].push_back(pair.first);
                            heroGraph[pair.first].push_back(name);
                        }
                    }

                }
            }

            infile.close();
            cout << "All heroes have been loaded from file." << endl;
        }
        else {
            cout << "Error: Unable to open file. Please try again.\n";
        }
    }

    // Allows user to search and view hero info by name
    void findHeroByName() {
        string searchName;
        cout << "Enter name of the hero your looking for: ";
        cin.ignore();
        getline(cin, searchName);

        if (heroMap.find(searchName) != heroMap.end()) {
            cout << "\nHero Found:\n\n";
            heroMap[searchName]->displayInfo();
        }
        else {
            cout << "\nNo hero named \"" << searchName << "\" was found.\n";
        }

        system("pause");
    }

    // Shows all factions and their member heroes
    void showFactions() {
        if (factionGraph.empty()) {
            cout << "No factions are formed right now.\n";
            return;
        }

        cout << "\n\t*** Factions and Their Members ***\n\n";
        for (const auto& pair : factionGraph) {
            cout << "Faction: " << pair.first << endl;
            cout << "Members: ";
            for (const string& heroName : pair.second) {
                cout << heroName << ", ";
            }
            cout << "\n\n";
        }

        system("pause");
    }

    // Explores connected heroes aka clan allies starting from a selected hero
	// uses BFS to find all connected heroes in same faction
	// BFS is used to explore the graph of heroes
    void exploreHeroConnections() {
        if (heroGraph.empty()) {
            cout << "There are no hero connections yet.\n";
            return;
        }

        string start;
        cout << "Enter the name of a hero to find their allies: ";
        cin.ignore();
        getline(cin, start);

        if (heroGraph.find(start) == heroGraph.end()) {
            cout << "That hero does not exist or has no allies.\n";
            return;
        }

        unordered_map<string, bool> visited;
        queue<string> q;

        q.push(start);
        visited[start] = true;

        cout << "\nAllied heroes starting from: " << start << "\n\n";

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            cout << "- " << current << endl;

            for (const string& neighbor : heroGraph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        system("pause");
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
        cout << "3. Search for Hero by Name\n"; //hash table search
        cout << "4. Save Current Heroes\n";
        cout << "5. Load Previous Heroes\n";
        cout << "6. Show Factions and Members\n";
        cout << "7. View Hero Alliances (BFS)\n";
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
            // Searches for hero using hash table
            obj_heroCreator.findHeroByName(); 
        }

        else if (choice == 4)
        {
            //Saves all current heroes to .txt file
            obj_heroCreator.saveHeroes();
        }
        else if (choice == 5)
        {
            //Loads all heroes from .txt file
            obj_heroCreator.loadHeroes();
        }
        else if (choice == 6)
        {
            obj_heroCreator.showFactions();
        }
        else if (choice == 7)
        {
            obj_heroCreator.exploreHeroConnections();
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