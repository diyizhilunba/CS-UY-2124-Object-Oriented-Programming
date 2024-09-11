/*
Author: Yilun Ma
Assignment: HW4.1
Date due: 06-20
I pledge that I have completed this assignment without the use of AI tools or collaborating with anyone else,
in conformance with the NYU School of Engineering Policies and Procedures on Academic Misconduct.
*/
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
//Task 1: write the function to reverse string
void reverseString(char str[]);



int main() {
    char str1[] = "hello";
    char str2[] = "world!";
    char str3[] = "Hello World";

    cout << "Original: " << str1 << endl;
    reverseString(str1);
    cout << "Reversed: " << str1 << endl << endl;

    cout << "Original: " << str2 << endl;
    reverseString(str2);
    cout << "Reversed: " << str2 << endl << endl;

    cout << "Original: " << str3 << endl;
    reverseString(str3);
    cout << "Reversed: " << str3 << endl;
    return 0;
}

void reverseString(char str[]) {
    int left = 0;
    int right = strlen(str)-1;
    while(left <= right) {
        //reverse the characters
        char left_char = str[left];
        str[left] = str[right];
        str[right] = left_char;
        //move the pointer
        left += 1;
        right -= 1;
    }
}
