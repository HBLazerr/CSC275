#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Hero {
protected:
	string name;
	int level;
	int health;

public:
	virtual void displayInfo() = 0;
	virtual void saveInfo(ofstream& outfile) = 0;
	virtual void loadInfo(ifstream& infile) = 0;
};

class Warrior : public Hero {
private:
	int strength;
public:
	Warrior() {}
	Warrior(string n, int l, int h, int s) {
		name = n;
		level = l;
		health = h;
		strength = s;
	}
	void displayInfo() {
		cout << "Name: " << name << endl;
		cout << "Level: " << level << endl;
		cout << "Health: " << health << endl;
		cout << "Strength: " << strength << endl;
	}
	void saveInfo(ofstream& outfile) {
		outfile << "Warrior\n";
		outfile << name << endl;
		outfile << level << endl;
		outfile << health << endl;
		outfile << strength << endl;
	}
	void loadInfo(ifstream& infile) {
		getline(infile, name);
		infile >> level;
		infile >> health;
		infile >> strength;
		infile.ignore();
	}
};

class Mage : public Hero {
private:
	int intelligence;
public:
	Mage() {}
	Mage(string n, int l, int h, int i) {
		name = n;
		level = l;
		health = h;
		intelligence = i;
	}
	void displayInfo() {
		cout << "Name: " << name << endl;
		cout << "Level: " << level << endl;
		cout << "Health: " << health << endl;
		cout << "Intelligence: " << intelligence << endl;
	}
	void saveInfo(ofstream& outfile) {
		outfile << "Mage\n";
		outfile << name << endl;
		outfile << level << endl;
		outfile << health << endl;
		outfile << intelligence << endl;
	}
	void loadInfo(ifstream& infile) {
		getline(infile, name);
		infile >> level;
		infile >> health;
		infile >> intelligence;
		infile.ignore();
	}
};

class HeroCreator {
private:
	Hero** heroes;
	int numHeroes;
public:
	HeroCreator() {
		heroes = new Hero * [10];
		numHeroes = 0;
	}
	~HeroCreator() {
		for (int i = 0; i < numHeroes; i++) {
			delete heroes[i];
		}
		delete[] heroes;
	}
	void createWarrior() {
		string name;
		int level, health, strength;
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter level: ";
		cin >> level;
		cout << "Enter health: ";
		cin >> health;
		cout << "Enter strength: ";
		cin >> strength;
		cin.ignore();
		heroes[numHeroes++] = new Warrior(name, level, health, strength);
		cout << "Warrior created!" << endl;
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
		heroes[numHeroes++] = new Mage(name, level, health, intelligence);
		cout << "Mage created!" << endl;
	}
	void displayHeroes() {
		if (numHeroes == 0) {
			cout << "No heroes created yet." << endl;
			return;
		}
		for (int i = 0; i < numHeroes; i++) {
			heroes[i]->displayInfo();
			cout << endl;
		}
	}
	void saveHeroesToFile() {
		if (numHeroes == 0) {
			cout << "No heroes created yet." << endl;
			return;
		}
		ofstream outfile("heroes.txt");
		if (!outfile.is_open()) {
			cout << "Error: Unable to open file." << endl;
			return;
		}
		for (int i = 0; i < numHeroes; i++) {
			heroes[i]->saveInfo(outfile);
		}
		outfile.close();
		cout << "Heroes saved to file." << endl;
	}
	void loadHeroesFromFile() {
		ifstream infile("heroes.txt");
		if (!infile.is_open()) {
			cout << "Error: Unable to open file." << endl;
			return;
		}
		while (!infile.eof()) {
			string heroType;
			getline(infile, heroType);
			if (heroType == "Warrior") {
				string name;
				int level, health, strength;
				getline(infile, name);
				infile >> level;
				infile >> health;
				infile >> strength;
				infile.ignore();
				heroes[numHeroes++] = new Warrior(name, level, health, strength);
			}
			else if (heroType == "Mage") {
				string name;
				int level, health, intelligence;
				getline(infile, name);
				infile >> level;
				infile >> health;
				infile >> intelligence;
				infile.ignore();
				heroes[numHeroes++] = new Mage(name, level, health, intelligence);
			}
		}
		infile.close();
		cout << "Heroes loaded from file." << endl;
	}
};

int main() {
	HeroCreator heroCreator;
	int choice;
	do {
		cout << "Menu\n";
		cout << "1. Create Warrior\n";
		cout << "2. Create Mage\n";
		cout << "3. Display Heroes\n";
		cout << "4. Save Heroes to File\n";
		cout << "5. Load Heroes from File\n";
		cout << "6. Quit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:
			heroCreator.createWarrior();
			break;
		case 2:
			heroCreator.createMage();
			break;
		case 3:
			heroCreator.displayHeroes();
			break;
		case 4:
			heroCreator.saveHeroesToFile();
			break;
		case 5:
			heroCreator.loadHeroesFromFile();
			break;
		case 6:
			cout << "Goodbye!" << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 6);
	return 0;
}