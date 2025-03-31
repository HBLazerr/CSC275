// Smart Pointers Version 1.0
// Daniel Chavez

// Libraries
#include <iostream>
#include <memory>

using namespace std;

class Car {
	// Create string variables
	string year;
	string make;
	string model;
	string carName;

public:
	//constructor to create Car object
	Car(const string& name) : carName(name) {
		cout << "\nA car was created.\n\n\n";
		
		// Define values
		year = "2013";
		make = "Scion";
		model = "FR-S";

		// Assign carName 
		string carName = year + " " + make + " " + model;

		// Display carName
		cout << "** pointer is outside the scope **\n\n";
		cout << "The current car you are driving is:\n";
		cout << carName << endl;

	}

	// Function to display carName
	void CarsFullName() const {
		cout << "\n\n** pointer is inside the scope **";

		cout << "\n\nAfter swapping your vehicle from the garage, the car you are now driving is:\n";
		cout << carName << endl;
	}
};

int main()
{
	// display intro message
	cout << "\n\n\t*** Smart pointers ***\n\n";
	cout << "This is a program designed to demonstrate unique pointers by printing\n";
	cout << "prompts to tell the user what is happening, and names of cars.\n\n";

	// creates a smart pointer (unique_ptr) that points to a Car object carName
	unique_ptr<Car> car_ptr(new Car("2006 Nissan 350z"));
	// calls function to display the new carName
	car_ptr->CarsFullName();

	cout << "\n\nEnd of program scope." << endl;

	return 0;
}

