#include <string>
#include <iostream>

int main ()
{
	std::string stringSTR = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringSTR;
	std::string &stringREF = stringSTR;

	std::cout 
			<< "Address : "   << &stringSTR
			<< "\nAddress : " << stringPTR
			<< "\nAddress : " << &stringREF
			<< "\nValue   : " << stringSTR
			<< "\nValue   : " << *stringPTR
			<< "\nValuee  : " << stringREF << std::endl;
	return (0);
}

/* OUTPUT:
Address of the string: 0x16bd8b1c0
Address of the pointer: 0x16bd8b1b8
Address of the reference: 0x16bd8b1c0
Value of the String: HI THIS IS BRAIN
Value of the Pointer: HI THIS IS BRAIN
Value of the Reference: HI THIS IS BRAIN
*/