#include <iostream>

void passAgeByValue(int myAge);
void passAgeByPointer(int* ptrMyAge);


int main()
{
	//print out title
	std::cout << "\n\n\t*** Pointer Wrld! ***\n\n" << std::endl;

	//create a variable
	int age = 21;

	//print out address of age
	std::cout << "The address of age is: " << &age << std::endl;


	//create a reference to the variable
	int& rAge = age;

	//print out the value of the reference rAge
	std::cout << "The value of rAge is: " << rAge << std::endl;
	std::cout << "The address of the reference rAge: " << &rAge << std::endl;


	//create a pointer to age
	// & is the address of operator
	// it gets the address of any variable
	int* pAge = &age;

	//print out the value of the pointer
	std::cout << "The value the pointer pAge is holding: " << pAge << std::endl;

	//print out the value of age using the pointer
	// the official name ot do this is dereferencing operator
	// While you learn it think of it as the "show me the value" operator
	std::cout << "The value of age passing through the pointer: " << *pAge << std::endl;

	//change the value of age by passing through the pointer
	//this is only possible by using the dereferencing operator(*)
	//without the * operator, it would have changed the value of the pointer and not the value of the variable
	//REMEMBER: The value of the pointer is the memory address of the variable
	*pAge = 30;

	std::cout << "Now the value of age is: " << age << std::endl;
	std::cout << "Now the value of rAge is: " << rAge << std::endl;
	std::cout << "Now the value of age passing through the pointer is: " << *pAge << std::endl;
	std::cout << "Now the value the pointer pAge is holding: " << pAge << std::endl;
	std::cout << "Now the address of the pointer pAge is: " << &pAge << std::endl;



	std::cout << "\n\nWe are in main and the value of the variable age is: " << age << std::endl;
	//
	//
	std::cout << "\n\nWe are going to call passAgeByValue function which makes a copy of the value it passes into a function.\n";
	//
	passAgeByValue(age);
	//
	std::cout << "\n\nWe are back in main and the value of the variable age is: " << age << std::endl;


	//
	//
	std::cout << "\n\nWe are going to call passAgeByPointer function which passes the address and does not make a copy of the value to pass into a function.\n";
	//
	passAgeByPointer(&age);
	//
	std::cout << "\n\nWe are back in main from passAgeByPointer and the value of the variable age is: " << age << std::endl;


	//Exit main function
	return 0;
}

void passAgeByValue(int myAge)
{
	//
	std::cout << "\n\n myAge from passAgeByValue comes into this function as " << myAge << std::endl;
	//
	myAge++;
	//
	std::cout << "\n\n myAge from passAgeByValue after we add 1 year to it is " << myAge << std::endl;
}

void passAgeByPointer(int* ptrMyAge)
{
	//
	std::cout << "\n\n ptrMyAge from passAgeByPointer comes into this function as " << *ptrMyAge << std::endl;
	//
	(*ptrMyAge)++;
	//
	std::cout << "\n\n ptrMyAge from passAgeByPointer after we add 1 year to it is " << *ptrMyAge << std::endl;
}