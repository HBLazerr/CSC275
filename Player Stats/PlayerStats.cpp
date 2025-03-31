// PlayerStats Version 1.0
// Daniel Chavez

#include <iostream>

using namespace std;
int main()
{
    //Intro prompt
    cout << "\n\n\t *** Player Stats *** \n";
    cout << "A short program to demonstrate memory allocation and deallocation.\n\n";

    // Create 5 objects on the heap
    // 
    // Allocate memory for a character
    char* pointChar = new char[2] {'H', 'B'};
    cout << "Allocated memory on the heap for a character using the new keyword." << endl;

    // Allocate memory for an integer
    int* pointInt = new int(10);
    cout << "Allocated memory on the heap for an integer using the new keyword." << endl;

    // Allocate memory for a float
    float* pointFloat = new float(2.69f);
    cout << "Allocated memory on the heap for a float using the new keyword." << endl;

    // Allocate memory for a double
    double* pointDouble = new double(3.24084);
    cout << "Allocated memory on the heap for a double using the new keyword." << endl;

    // Allocate memory for an int array
    int* pointIntArray = new int[4] {1, 7, 3, 8};
    cout << "Allocated memory on the heap for an array of integers using the new keyword." << endl;


    //Print values of the variables
    cout << "pointChar points to " << *pointChar << endl;
    cout << "pointInt points to " << *pointInt << endl;
    cout << "pointFloat points to " << *pointFloat << endl;
    cout << "pointDouble points to " << *pointDouble << endl;
    cout << "pointIntArray points to an array of integers: ";
    for (int i = 0; i < 4; i++) {
        cout << pointIntArray[i] << " ";
    }


    // Deallocate each heap memory
    delete[] pointChar;
    cout << "Deallocated memory on the heap for the character using the delete keyword." << endl;

    delete pointInt;
    cout << "Deallocated memory on the heap for the integer using the delete keyword." << endl;

    delete pointFloat;
    cout << "Deallocated memory on the heap for the float using the delete keyword." << endl;

    delete pointDouble;
    cout << "Deallocated memory on the heap for the double using the delete keyword." << endl;

    delete[] pointIntArray;
    cout << "Deallocated memory on the heap for the integer array using the delete keyword." << endl;


    // Display memory deallocated prompt
    cout << "\n\nAll of the memory has now been allocated.\n";

    return 0;
}
