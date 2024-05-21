#include <iostream>//Always have
//It is a directive, similar to import in py, but it is a base in C
//My Hello World Program
//Preprosed, early than this main.cpp file
//First be turned into an object, get linked with main
using namespace std;

void add(int x,int y);
int multiply(int x, int y);
double square(double x);
auto increment_byval(int y);
void increment_byref(int& y);//not the copy of y, but the actual address of y


int main() {//specify the return type as java
    std::cout << "Hello, World!\n"; //You have to use \n every line, also don't forget after every line use ';'
    //c-out is equivalent to print in python
    //stands for character output
    //std shorts for standard is a namespace where to find cout
    //conclusion: standart character output
    //<< mean "put into the console(named cout)"


    cout << "------------------------------" << endl;
    //datatypes: declare first as java
    int age;
    //age = 20.5 is wrong as 20.5 is not int
    age = 20;
    char x;//occupies 1 byte(8bits) of the comp memory
    x = 'a';//in binary, a = 10 = 1010 -> stored as 00001010



    cout << "------------------------------" << endl;
    int a = 0;
    auto b = a;
    //decltype(a) b;//declare the type of b with the same type of a
    const bool status = true;
    //status = false u cannot modify as it is const




    cout << "------------------------------" << endl;
    cout << "Hello\b\b\b\\";
    cout << "Wor\tld";



    cout << "------------------------------" << endl;
    int p = 0;
    int q = 5;

    cout << p++ << endl;
    cout << ++p << endl;

    p += q;
    cout << p << endl;


    cout << "---------------if-else statemnt---------------" << endl;
    int c = 0;
    if(c > 5) {
        cout << x << "is greater than 5"<< endl;//false so nothing happen

    }
    if(c > -5) {
        cout << x << "is greater than -5"<< endl;//true

    }
    if(c > -5)
        cout << x << "is greater than -5"<< endl;//if you don't have bracket, the if only runs for next line(this line) as java

    if(c > 5) {
        cout << x << "is greater than 5"<< endl;//false so nothing happen

    }
    else {
        cout << x << "is not greater than 5" << endl;
    }
    if(c > 5) {
        cout << x << "is greater than 5"<< endl;//false so nothing happen

    }
    else if(c == 5){
        cout << x << "is 5" << endl;
    }
    else {
        cout << x << "is smaller than 5" << endl;
    }



    cout << "---------------switch---------------" << endl;
    int d = 5;

    switch (d) {
        case 0:
            cout << d << "equals 0" << endl;
        case 1:
            cout << d << "equals 1" << endl;
        case 5:
            cout << d << " equals 5" << endl;
        default:
            cout << "None" << endl;

    }
    cout << "---------------loop---------------" << endl;
    //print from 0 to 9
    for (int it = 0; it < 10; it++) {
        cout << it << "," ;
    }
    //some playing
    cout << "\n" ;
    for (int it = 0; it < 10; ++it) {
        cout << it << "," ;
    }

    //cout << "\n" ;
    //for (int it = 0; it = 10; ++it) {
    //    cout << it << "," ;
    //}//infinite loop of 10

    cout << "\n" ;
    for (int it = 0; it < 10; it += 2) {
        cout << it << "," ;
    }//even number

    int secret = 5;
    int input;
    cout << "\nGuess my secret number\n";
    cin >> input;
    while(input != secret) {
        cout << "Try again\n";
        cin >> input;
    }
    cout <<"You are right! My sceret number is 5! \n";
    int n = 0;
    do {
        cout << n << endl;
        ++n;
    }while(n<10);
    cout << "Try sth fun like change the condition to n > 10, it still run once" << endl;
    n = 0;
    do {
        cout << n << endl;
        ++n;
    }while(n>10);

    cout << "---------------functions---------------" << endl;
    add(5,6);
    int result1 = multiply(5,6);
    cout << result1 << endl;
    //playing
    double result2 = multiply(5,6);
    cout << result2 << endl;//actually nothing changesin the output, but the reverse will be casted, if casting failed then compile error

    auto i = 0;
    increment_byval(i);
    cout << "i: " << i << endl;
    increment_byref(i);
    cout << "i: " << i << endl;




    return 0;//if return 0, it is error free, don't really need to type it as always have exit code 0(see console)
}//similar to java use bracket

//define functions
void add(int x, int y) {
    cout << x+y << endl;
}

int multiply(int x, int y) {
    return x * y;
}
double square(double x) {
    return (x * x);
}
auto increment_byval(int y) {//expect return sth, but not nothing
    ++y;
}

void increment_byref(int &y) {
    ++y;
}

