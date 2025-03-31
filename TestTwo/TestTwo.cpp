#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hero {
private:
    string name;
    int level;
    int health;

public:
    Hero(string n, int l, int h) : name(n), level(l), health(h) {}

    string getName() {
        return name;
    }

    int getLevel() {
        return level;
    }

    int getHealth() {
        return health;
    }

    void setName(string n) {
        name = n;
    }

    void setLevel(int l) {
        level = l;
    }

    void setHealth(int h) {
        health = h;
    }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << health << endl;
    }
};

class Warrior : public Hero {
private:
    int strength;

public:
    Warrior(string n, int l, int h, int s) : Hero(n, l, h), strength(s) {}

    int getStrength() {
        return strength;
    }

    void setStrength(int s) {
        strength = s;
    }

    void displayInfo() {
        Hero::displayInfo();
        cout << "Strength: " << strength << endl;
    }
};

class Mage : public Hero {
private:
    int intelligence;

public:
    Mage(string n, int l, int h, int i) : Hero(n, l, h), intelligence(i) {}

    int getIntelligence() {
        return intelligence;
    }

    void setIntelligence(int i) {
        intelligence = i;
    }

    void displayInfo() {
        Hero::displayInfo();
        cout << "Intelligence: " << intelligence << endl;
    }
};

class HeroCreator {
private:
    vector<Hero*> heroes;

public:
    void createWarrior() {
        string name;
        int level, health, strength;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter level: ";
        cin >> level;
        cout << "Enter health: ";
        cin >> health;
        cout << "Enter strength: ";
        cin >> strength;
        cin.ignore();
        heroes.push_back(new Warrior(name, level, health, strength));
        cout << "Warrior created" << endl;
    }

    void createMage() {
        string name;
        int level, health, intelligence;
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter level: ";
        cin >> level;
        cout << "Enter health: ";
        cin >> health;
        cout << "Enter intelligence: ";
        cin >> intelligence;
        cin.ignore();
        heroes.push_back(new Mage(name, level, health, intelligence));
        cout << "Mage created" << endl;
    }

    void displayHeroes() {
        if (heroes.empty()) {
            cout << "No heroes created yet." << endl;
            return;
        }

        for (const auto& hero : heroes) {
            hero->displayInfo();
            cout << endl;
        }
    }

    ~HeroCreator() {
        for (auto& hero : heroes) {
            delete hero;
            hero = nullptr;
        }
    }
};

int main() {
    HeroCreator creator;

    int choice;


    do {
        cout << "1. Create Warrior" << endl;
        cout << "2. Create Mage" << endl;
        cout << "3. Display Heroes" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            creator.createWarrior();
            break;
        case 2:
            creator.createMage();
            break;
        case 3:
            creator.displayHeroes();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}







//// Hero Creator version 1.0
//// Daniel Chavez
//// Demo video - 
//
//
//// TO DO
//// create rest of characters
//// create rest of options in menu
//// add file input output
//
//
//
//
//// Libraries
//#include <iostream>
//#include <string>
//#include <vector>
//#include "CreatorIntro.h" //for DisplayTitle function
//#include "ExitCreator.h" //for CreatorExit function
//
//using namespace std;
//
//
//// Base Class Hero
//class Hero {
//private:
//    // variables
//    string Name;
//    string Type;
//    int Level;
//
//public:
//    // constructor to initialize variables and assign values
//    Hero(string name, string type, int level) : Name(name), Type(type), Level(level) {}
//
//    //get functions
//    string getName() {
//        return Name;
//    }
//    string getType() {
//        return Type;
//    }
//    int getLevel() {
//        return Level;
//    }
//
//    //set functions
//    void setName(string name) {
//        Name = name;
//    }
//    void setType(string type) {
//        Type = type;
//    }
//    void setLevel(int level) {
//        Level = level;
//    }
//
//
//    void displayInfo() {
//        cout << "Name: " << Name << endl;
//        cout << "Type: " << Type << endl;
//        cout << "Level: " << Level << endl;
//    }
//};
//
////child class Hunter
//class Hunter : public Hero {
//private:
//    string Stealth;
//    string Type = "Hunter";
//
//public:
//    Hunter(string name, string type, int level, string stealth) : Hero(name, type, level), Stealth(stealth) {}
//
//    string getStealth() {
//        return Stealth;
//    }
//
//    void setStealth(string stealth) {
//        Stealth = stealth;
//    }
//
//    void displayInfo() {
//        Hero::displayInfo();
//        cout << "Special ability: " << Stealth << endl;
//    }
//
//};
//
//
//
//class HeroCreator {
//private:
//    //creates private vector of pointers to Hero class objects
//    //allows to create the hero types
//    vector<Hero*> heroes;
//
//public:
//    void createHunter() {
//        string Name;
//        string Type = "Hunter";
//        int Level;
//        string Stealth = "Stealth";
//
//
//        // Ask and get user input
//        cout << "\nExcellent choice! Hunters have a special stealth ability.\n";
//
//        cout << "Choose a name for your hero: ";
//        cin.ignore();
//        getline(cin, Name);
//
//        cout << "Set a level for " << Name << " (NOTE: their level is how old they are): ";
//        cin >> Level;
//
//        // adds new Hunter object with parameters to the end of the heroes vector.
//        //push.back puts it at end of heroes vector
//        heroes.push_back(new Hunter(Name, Type, Level, Stealth));
//        cout << "\nHero successfully created. ";
//        system("pause");
//    }
//
//    void displayHeroes() {
//        //check if heroes is empty
//        if (heroes.empty()) {
//            cout << "You have not created any heroes yet." << endl;
//            return;
//        }
//
//        system("pause");
//        cout << "\n\t*** All Created Heroes and Their Stats ***\n\n";
//
//
//        //add const if needed and add &reference if needed
//        //
//        for (auto currentHero : heroes) {
//            currentHero->displayInfo();
//            cout << endl;
//        }
//    }
//};
//
//
//int main()
//{
//    // Objects
//    //instance of CreatorIntro
//    CreatorIntro obj_creatorIntro;
//    //instance of CreatorExit
//    CreatorExit obj_exitCreator;
//    //instance of HeroCreator
//    HeroCreator obj_heroCreator;
//
//    //sets custom console app colors
//    system("Color 01");
//
//    //calls DisplayTitle method
//    obj_creatorIntro.DisplayTitle();
//
//    int choice;
//    do
//    {
//        // show menu options
//        cout << "\nOptions:\n";
//        cout << "1. Create Hunter\n";
//        cout << "2. Display Heroes\n";
//        cout << "6. Quit\n";
//        cout << "\nEnter your choice: ";
//        cin.clear();
//
//        //get & evaluate choice
//        cin >> choice;
//        cout << endl;
//        if (choice == 1)
//        {
//            obj_heroCreator.createHunter();
//        }
//        else if (choice == 2)
//        {
//            obj_heroCreator.displayHeroes();
//        }
//        else if (choice == 6)
//        {
//            //displays goodbye prompt
//            obj_exitCreator.ExitCreator();
//        }
//        else {
//            cout << "\nSorry, try entering a valid option.\n";
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        }
//
//    } while (choice != 6);
//
//    return 0;
//}
