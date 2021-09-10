

#include <iostream>

int main()
{
    // Declare a varaible and give it a value
    int num = 5;
    // Create an "Old-style" pointer
    int* numPointer = &num;
    // Create a "New-Style" pointer from the standard library
    // inside the angle brackets, you put the name of the type you want to point to.
    // Inside of the parentheses, you put something which gives you a "location". 
    std::unique_ptr<int> numUniquePointer(&num);
    // Print out the number itself
    std::cout << "Number: " << num << std::endl;
    // Print out the address value. 
    //std::hex(std::cout); // Sets output to base 16 (hex), typically used when talking about memory addresses
    std::cout << "Address of number: " << (void *)&num << std::endl;
    // De-reference the old-style pointer. 
    //std::dec(std::cout);
    std::cout << "Value of numPointer: " << *numPointer << std::endl;
    // De-reference the new-style pointer. 
    std::cout << "Value of numUniquePointer: " << *numUniquePointer << std::endl;
    // When done with new-style pointers, they need to be released. 
    numUniquePointer.release();

    return EXIT_SUCCESS;
}


