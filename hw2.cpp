/*
Author: Yilun Ma
Assignment: HW2
Date due: 06-06
I pledge that I have completed this assignment without the use of AI tools or collaborating with anyone else,
in conformance with the NYU School of Engineering Policies and Procedures on Academic Misconduct.
*/
#include <iostream>
using namespace std;

class Measurement {
public:

    Measurement();
    Measurement(int t);
    void setFeet(int f);
    void setInches(int i);
    int getFeet();
    int getInches();
    ~Measurement();
    void display();
private:
    int feet;
    int inch;
};
int main() {
    Measurement m1;
    m1.display();

    Measurement m2(25);
    m2.display(); // Output: 2 feet, 1 inch

    Measurement m3(130);
    m3.display(); // Output: 10 feet, 10 inches

    m2.setFeet(-2);
    m2.display(); // Output: -2 feet, 1 inch

    m3.setInches(30);
    m3.display(); // Output: 12 feet, 6 inches

    m3.setInches(-25);
    m3.display(); // Output: 9 feet, 11 inches

    return 0;
}
Measurement::Measurement():feet(0),inch(0) {

}
Measurement::Measurement(int t):feet(t >= 0 ? t/12:t/12 - 1),inch(t >= 0 ? t%12:t%12 + 12) {

}
void Measurement::setFeet(int f){
    feet = f;
}
void Measurement::setInches(int i) {
    if(i >= 0 && 12 > i) {
        inch = i;
    }
    else if(i >= 12){
        feet += i/12;
        inch = i%12;

    }
    else {
        feet += i/12 - 1;
        inch = i%12 + 12;
    }
}

int Measurement::getFeet() {
    return feet;
}

int Measurement::getInches() {
    return  inch;
}

Measurement::~Measurement() {
    cout << "The object has been closed" <<endl;
}

void Measurement::display() {
    if(inch == 1) {
        if(feet == 1 || feet == -1) {
            cout << feet << " foot\t" << inch << " inch" << endl;
        }
        else {
            cout << feet << " feet\t" << inch << " inch" << endl;
        }
    }
    else {
        if(feet == 1 || feet == -1) {
            cout << feet << " foot\t" << inch << " inches" << endl;
        }
        else {
            cout << feet << " feet\t" << inch << " inches" << endl;
        }
    }
}













