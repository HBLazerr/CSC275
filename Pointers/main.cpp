// Pointers

//include libraries
#include <iostream>

//main function
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
	std::cout << "Now the value the pointer pAge is holding: " << *pAge << std::endl;

	//Exit main function
	return 0;
}