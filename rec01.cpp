/*
  rec01_start.cpp
  spring 2024
  Yilun Aaron Ma
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stl_algo.h>
using namespace std;

//
// Function prototypes for tasks 15-17
//

// Task 15. Function to display a vector of ints
void display_vector(vector<int>& ints);


// Task 16. Function to modify the vector, using indices
void double_vector(vector<int>& ints);


// Task 17. Function to modify the vector, using a ranged for
void range_for_double_vector(vector<int>& ints);




//
// main
//
int main() { // Yes, it has to have an int for the return type
    //
    // Output
    //

    // Task 1. Printing hello ...  No use of "using namespace"
    std::cout << "hello ... " << std::endl;//does not return anything

    // Task 2  Printing hello ...  Using "using namespace"
    cout << "hello ... " << endl;//easier as you don't need to write std:: every time you need


    //
    // Types and variables
    //

    // Task 3  Displaying uninitialized variable
    int x;
    cout << "x: " << x << endl;//shows 0
    
    // Task 4 Use the sizeof function to see the size in bytes of
    //        different types on your machine.
    int y = 17;
    int z = 2000000017;
    double pie = 3.14159;
    // display sizeof(x), sizeof(y), sizeof(z) and sizeof(pie)
    cout << "size of x: " << sizeof(x) << endl;
    cout << "size of y: " << sizeof(y) << endl;
    cout << "size of z: " << sizeof(z) << endl;
    cout << "size of pie: " << sizeof(pie) << endl;
    //pie takes the most memory

    // Task 5  Attempt to assign the wrong type of thing to a variable
    //x = "felix";//compile error


    //
    // Conditions
    //

    // Task 6  Testing for a range
    if(y >= 10 && y <= 20) {
        cout << "y is between 10 and 20(inclusive)." << endl;
    }
    else {
        cout << "y is not between 10 and 20." << endl;
    }
    

    //
    // Loops and files
    //

    // Task 7  Looping, printing values 10 to 20 inclusive

    // First with a for loop
    for(int it = 10; it <= 20; it++) {
        cout << "for loop iterator: " << it << endl;
    }
    // Then with a while loop
    int it = 10;
    while( it <= 20) {
        cout << "while loop iterator: " << it << endl;
        it++;
    }
    // Finally with a do-while loop
    it = 10;
    do {
        cout << "do while iterator: " << it << endl;
        it++;
    }while (it <= 20);


    // Task 8  Looping to successfully open a file, asking user for the name
    cout << "--------Task 8--------" << endl;

    bool success = true;
    //ifstream file("name");
    string input;
    ifstream ifs;
    do {
        cout << "Enter the file name to open the file:" << endl;
        cin >> input;
        ifs.open(input);
    }while (!ifs);
    cout << "The file has been successfully open." << endl;
    // Task 9  Looping, reading file word by "word".
    cout << "--------Task 9--------" << endl;

    string line;
    it = 1;
    while(ifs >> line) {
        cout << line << endl;
    }
    ifs.close();

    // Task 10 Open a file of integers, read it in, and display the sum.
    cout << "--------Task 10--------" << endl;

    ifstream ints;
    int num;
    int sum = 0;
    ints.open("..\\integers.txt");
    if(! ints) {
        cerr << "The file cannot be open";
        exit(1);
    }
    else {
        while(ints >> num) {
            //cout << "num: " << num << endl;
            sum += num;
        }
        cout << "sum: " << sum << endl;
    }
    ints.close();

    // Taks 11 Open and read a file of integers and words. Display the sum.
    cout << "--------Task 11--------" << endl;
    sum = 0;
    ints.open("..\\mixed.txt");
    if(!ints) {
        cerr << "The file cannot be open";
        exit(1);
    }
    else {
        while(ints >> num) {
            sum += num;
        }
        cout << "sum: " << sum << endl;
    }
    ints.close();

    //
    // Vectors
    //

    // Task 12 Filling a vector of ints
    cout << "--------Task 12--------" << endl;

    vector<int> evens;
    for(it = 10; it <=100; it += 2) {
        evens.push_back(it);
    }
    for (int i = 0; i < evens.size(); ++i)
        {        cout << evens[i] << endl;    }
    
    // Task 13 Displaying the vector THREE times
    cout << "--------Task 13--------" << endl;

    //         a) using the indices,
    for (size_t i = 0; i < evens.size(); ++i) {
        cout << "Using indices, The " << i << "th even number in the vector is " <<evens[i] << endl;
    }
    //         b) using a "ranged for"
    for(int even : evens) {
        cout << "Using ranged for: "<< even << endl;
    }
    //         c) using indices again but backwards
    for(size_t i = evens.size(); i > 0; --i) {
        cout << "Using indices, The last " << (i-1 ) << "th even number in the vector is " <<evens[i-1] << endl;
    }

    // Task 14. Initialize a vector with the primes less than 20. 
    cout << "--------Task 14--------" << endl;
    vector<int> primes{2,3,5,7,11,13,17,19};
    for(int prime : primes) {
        cout << "number in vector primes: " << prime << endl;
    }

    //
    // Function calls
    //
    
    // Task 15  Function to print a vector
    cout << "--------Task 15--------" << endl;

    display_vector(primes);

    // Task 16  Function to double the values in a vector
    cout << "--------Task 16--------" << endl;

    double_vector(primes);
    display_vector(primes);

    // Task 17  Function to double the values in a vector, using a ranged for 
    cout << "--------Task 17--------" << endl;

    range_for_double_vector(primes);
    display_vector(primes);
    
}

//
// Function definitions for tasks 15-17
//

// Task 15. Function to display a vector of ints
void display_vector(vector<int>& ints) {
    for(int num : ints) {
        cout << "number in the vector: " << num << endl;
    }
}



// Task 16. Function to modify the vector, using indices
void double_vector(vector<int>& ints) {
    for(size_t it = 0; it <= ints.size(); it++) {
        ints[it] *= 2;
    }
}



// Task 17. Function to modify the vector, using a ranged for
void range_for_double_vector(vector<int>& ints) {
    for(int& num: ints) {
        num *= 2;
    }
}
