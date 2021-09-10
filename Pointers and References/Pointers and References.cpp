
#include <iostream>
#include "incrementers.hpp"

/*
Notes:
Note the difference between the & operator ('address-of' operator) we were 
using previously, and the reference marker when declaring an argument of a 
function. 

Some things to try:
 - Try making num a constant:
        const int num = 5;
   What happens? If you comment out the incrementWithReference function call, 
   what happens then?
 - Try changing the pointer function call to the following:
        incrementWithPointer(NULL);
   What happens? What happens if you try this with the reference function 
   instead?
*/

int main()
{
    // Declare a varaible
    int num = 5;
    std::cout << "Num before incrementing: " << num << std::endl;
    // Increment it with the value function. 
    incrementLocally(num); 
    std::cout << "Num is still " << num << std::endl;
    // Now, increment it using the pointer function
    incrementWithPointer(&num);// We use & here to get the address of num.
    std::cout << "After incrementing with a pointer, num is now " << num << std::endl;
    // Now, increment it using the reference function
    incrementWithReference(num); // Notice how we didn't need to use the & operator. 
    std::cout << "After incrementing with a reference, num is now " << num << std::endl;

    return EXIT_SUCCESS;
}