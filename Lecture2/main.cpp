#include <iostream>
#include <vector>
using namespace std;


struct Student {//see row around 130
    string name;
    int age;
    double gpa;
};
class ClassName //User-defined name
{
    //Access specifier: private, public, protected
    //data members: variables
    //member functions: functions adn methods to access data members
};
class Car {
    //access specifier:
    /*there are three types of data
     *public, private, and protected
     *without saying, it is private by default in a class
     */
    //here all are private
    //Data members:
    string make;
    string model;
    //member functions:
public://remind this for setting it public

    void printInfo() {
        cout << "Car Info" << endl;
        cout << "Make is: " << make << endl;
        cout << "Model is: " << model << endl;
    }
    //access methods:
    void setmake(string m) {
        make = m;
    }
    string getmake() {
        return make;
    }
    void setmodel(string m) {
        model = m;
    }
    string getmodel() {
        return model;
    }
    //highly recommend to creat your own constructors
    //set a default constructor
    //usually it is created by computer itself by default, but not the datas assigned inside just an empty one
    Car() {
        //initialize: we can use private data members as we are in the class
        make = "BMW";
        model = "X6";
        cout << make << " " << model << " is created" << endl;
    }
    //define parametrized constructor
    Car(string ma, string mo) {
        make = ma;
        model = mo;
        cout << "Parameterized Car is created" << endl;
        printInfo();
    }
};
//put the functions below the struct as the functions may need them
void printInfo(Student s);
Student getInfo(Student s);
int main() {
    //intialize a struct(see row around 130)
    cout << "--------Struct--------" << endl;

    struct Student s1 = {"Tom",18,3.8};
    //initialize, then assign seperately
    struct Student s2;
    s2.name = "Ana";
    s2.age = 20;
    s2.gpa = 3.8;
    //access the values in the variables
    cout << "s1.name: " << s1.name << endl;
    cout << "s1.age: " << s1.age << endl;
    cout << "s1.gpa: " << s1.gpa << endl;

    //We can also pass the struct into a function
    cout << "--------Pass Struct to Function--------" << endl;

    printInfo(s2);

    //similarly, we can return a struct in a function
    cout << "--------Function Returning Struct--------" << endl;
    printInfo(getInfo(s1));
    //we don't usually put functions in structs, we will just use classes as they are private while structs are public by default
    cout << "--------Class and Object--------" << endl;

    //for objects, we can break large problems into smaller ones
    //then we put them together to solve the problem
    //it is more efficient than just writing one line after another
    /*
     *Some history:
     *C++ was named as C with classes
     *classes are blueprints of a thing
     *and object is one instance of the class
     *For example: if we want to build a car
     *to make it easier, we don't directly build a car
     *We need a list of properties
     *like color, make, model, year, # of window
     *WE also allow it to have a lot of actions
     *start, stop, accelerate,..
     *Then we have the class Car
     *and we can use this class to create different objects Car1, Car2, Car3
     */
    //See above the main for the syntax to create a class
    //initialize an object
    Car car;
    //car1.make = "Alfa Romeo"; I set it private so u cannot do this
    //car1.model = "Stelvio";
    car.printInfo();
    Car car1;
    Car car2;
    Car car3("Alfa Romeo","Stelvio");



    //initialize vectors
    cout << "--------Vectors--------" << endl;

    vector<char> first_chars = {'x','y','z'};
    //create an empty vector
    vector<int> nums(5);//initialize with 5 0s, 5 is len, 0 by default
    //vector of string
    //vector <string>  words1("Hello");//We want to initialize the vector with "Hello" -> not working
    vector <string> words(4, "Hello");//initialize with 4 "Hello"s


    for(char c: first_chars) {
        cout << c;
    }//for each loop


    for(string word: words) {
        cout << word << endl;
    }

    //vector operations:
    //push elements into vectos: add at the end
    first_chars.push_back('v');//this means arrays can be dynamically resized
    first_chars.push_back('y');//this means arrays can be dynamically resized
    first_chars.push_back('w');//this means arrays can be dynamically resized
    first_chars.push_back('f');//this means arrays can be dynamically resized

    for(char c: first_chars) {
        cout << c << endl;
    }

    //direct insert
    cout << "--------Direct Insert--------" << endl;
    first_chars.at(0) = 'R';//actually modifying the elements inside but not inserting one
    first_chars[2] = '3';

    for(char c: first_chars) {
        cout << c << endl;
    }

    //delete
    //pop: LIFO delete
    cout << "--------Delete--------" << endl;

    first_chars.pop_back();//pop f
    for(char c: first_chars) {
        cout << c << endl;
    }



    //Arrays: stored in continuos memory, while vectors may be discrete memory
    cout << "--------Arrays--------" << endl;

    //good thing: efficiency, fast response
    //bad thing/restriction: it is static and cannot resize
    //intuition: static list v.s. chain list

    //declaration: as stated above, you need to declare the size()
    int numbers[10];//an array with length of 10 ints/40 bytes
    //assign values:
    numbers[0] = 15;
    numbers[3] = 35;

    //declare and assign at the same time
    //datatype arrayName [size] = {val1,val2,...}
    double gpas[5] = {3.9,3.7,2.0,4.0,3.99};//remind the type inside the array should be uniform with the datatype you declare

    //2d arrays
    cout << "--------2D Arrays--------" << endl;


    //Syntax: dataType arrayName [rows][columns]:
    int matrix [3][2];//3 rows and 2 columns

    //assign values: arrayName[row][col] = val
    matrix[1][1] = 15;

    //Create and assign at the same time:
    //dataType arrayName [rows][cols] = {{row1},{row2}...}
    int grid[3][4] = {
        {4,5,6,7},
        {11,12,13,14},
        {22,23,24,25}
    };

    //iterate through the arrays is similar
    //for 2d, we need 2 iterations

    //access rows of the array
    for(int row = 0; row < 3; row++) {
        //access columns of the array
        for(int col = 0; col < 4; col++) {
            cout << grid[row][col] << "|";
        }
        cout << endl;//change line after finishing each row
    }

    //we can also use sizeof to find the number of row and col
    int rows = sizeof(grid) / sizeof(grid[0]);
    int cols = sizeof(grid[0]);

    //2d vector
    vector<vector<int>> mat;
    mat.push_back(vector<int>{1,2,3});

    //you can find more functions is prof a's nots
    //size_t is a type that is big enough to hold the biggest size
    //it garuntees it can hold the biggest size in your struct, while a int object may be too small


    //struct: you define a new type with different datatypes stored inside
    //intuition: public classes but different syntax
    /*syntax:
     *struct struct_name{
     *  datatype1 var1
     *  datatype2 var2
     *  ...
     * }
     */
    //usually we want to create it before main
    //and we initialize it at the beginning of the main




    return 0;
}

void printInfo(Student s) {
    cout << "name: " << s.name << endl;
    cout << "age: " << s.age << endl;
    cout << "gpa: " << s.gpa << endl;
}
Student getInfo(Student s) {
    return s;
}
