#include <iostream>
#include <string>

using namespace std;
// Task 1: Creating a Base Class
// Create a base class named Pokemon.
// Add protected data members: name (type string) and level (type int).
// Implement a no-argument constructor that initializes name to "Unknown" and level to 1.
// Implement a parameterized constructor to initialize name and level with given values.
// Add a public member function display() to print the name and level.
class Pokemon{
public:

protected:
    string name;
    int level;
};
// Task 2: Deriving a Class from the Base Class
// Create a derived class named FireType that inherits from Pokemon.
// Add a private data member firePower of type int.
// Implement a no-argument constructor and a parameterized constructor.
// Add a public member function display() that overrides the base class display function and also prints the firePower.

// Task 3: Adding More Derived Classes
// Create another derived class named WaterType that inherits from Pokemon.
// Add a private data member waterPower of type int.
// Implement a no-argument constructor and a parameterized constructor.
// Add a public member function display() that overrides the base class display function and also prints the waterPower.

// Task 4: Using Base Class Pointers
// Declare a Pokemon pointer.
// Create a FireType object and a WaterType object using the parameterized constructors.
// Assign the address of the FireType object to the Pokemon pointer and call the display() function.
// Assign the address of the WaterType object to the Pokemon pointer and call the display() function.

// Task 5: Introducing Virtual Functions
// Modify the display() function in the Pokemon class to be virtual.
// Rerun the code from Task 4 and observe the changes in output.

// Task 6: Creating an Array of Pointers
// Create an array of pointers to Pokemon with a size of 4.
// Initialize the array with two FireType objects and two WaterType objects.
// Use a loop to iterate through the array and call the display() function for each object.


int main() {
    // Task 4: Using Base Class Pointers
    // Create Pokemon pointers and objects of FireType and WaterType.
    // Assign the objects to the pointers and call the display() function.

    // Task 5: Introducing Virtual Functions
    // Modify the display() function in the Pokemon class to be virtual.
    // Repeat Task 4 after making this change and observe the polymorphic behavior.

    // Task 6: Creating an Array of Pointers
    // Create an array of Pokemon pointers.
    // Initialize the array with FireType and WaterType objects.
    // Use a loop to call the display() function for each object in the array.

    // Task 7: Adding Another Derived Class
    // Create a GrassType class derived from Pokemon.
    // Implement necessary constructors and display() function for GrassType.
    // Create GrassType objects and call their display() function.

    //Task 8: Extending Polymorphic Behavior with New Derived Classes
    //Extend the array of pointers to Pokemon created in Task 6 to include two Charizard objects.
    //Use a loop to iterate through the extended array and call the display() function for each object, demonstrating polymorphic behavior with multiple levels of inheritance.
    //Observe and document the output, showing how each derived class's display() function is called correctly.

    return 0;
}
