#include <string>
#include <iostream>

int main ()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPtr = &brain;
	std::string &brainRef = brain;

	std::cout 
			<< "Address of the string: " << &brain << std::endl
			<< "Address of the pointer: " << &brainPtr << std::endl
			<< "Address of the reference: " << &brain << std::endl
			<< "Value of the String: " << brain << std::endl
			<< "Value of the Pointer: " << *brainPtr << std::endl
			<< "Value of the Reference: " << brainRef << std::endl;
	return (0);
}
