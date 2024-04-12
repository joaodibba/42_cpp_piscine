#include <string>
#include <iostream>

int main ()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPtr = &brain;
	std::string &brainRef = brain;

	std::cout 
			<< "Address of the string: " << &brain
			<< "\nAddress of the pointer: " << &brainPtr
			<< "\nAddress of the reference: " << &brain
			<< "\nValue of the String: " << brain
			<< "\nValue of the Pointer: " << *brainPtr
			<< "\nValue of the Reference: " << brainRef << std::endl;
	return (0);
}
