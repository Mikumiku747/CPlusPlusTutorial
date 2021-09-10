#include <iostream>

// This one increments the number, but doesn't matter because it's a local
// copy of the number (this is why understanding scope is important).
// This is referrred to as "pass-by-value", it makes a copy of the argument.
void incrementLocally(int valueToIncrement)
{
	std::cout << "Incrementing the value from " << valueToIncrement;
	valueToIncrement += 1;
	std::cout << " to " << valueToIncrement << std::endl;
}

// This function increments the integer at the given location using a pointer.
// Typically you don't really do it like this in C++ any more, because:
// - What happens if something other than a valid pointer is passed in?
// - What happens if the thing you're trying to modify is supposed to be 
//   a constant?
// This is referred to as "pass-by-pointer", you give the location and it makes
// changes to that location. 
void incrementWithPointer(int* locationToIncrement)
{
	std::cout << "Incrementing the pointed to value from " << *locationToIncrement;
	*locationToIncrement += 1;
	std::cout << " to " << *locationToIncrement << std::endl;
}

// This function increments the given variable using a reference. It has a 
// couple advantages over using pointers:
// - No need to use the dereference operator (the *) before the variable name
// - There are type protections to stop you from making mistakes with it
// - References are guaranteed to not be NULL. 
// This is "pass-by-reference", and it works directly on an external variable instead
// of a location or a copy of the value. 
void incrementWithReference(int& variableToIncrement)
{
	std::cout << "Incrementing the value in the variable from " << variableToIncrement;
	variableToIncrement += 1;
	std::cout << " to " << variableToIncrement << std::endl;
}