#include <iostream>
#include <vector>
#include <string>
/*
 *Yilun Ma
 *ym2932@nyu.edu
 *Recitation 5
 */
using namespace std;
// Helper function to find the length of a C-string
int getStringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to check if a C-string is a palindrome
bool isPalindrome(const char* str) {
    int length = getStringLength(str);
    int left = 0;
    int right = length - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    cout << "-----------------Task 2,3------------------" << endl;
    int* p1, *p2;// add an asterik before p2
    p1 = new int;
    *p1 = 42;
    p2 = p1;
    cout << "*p1 = " << *p1 << endl;//42
    cout << "*p2 = " << *p2 << endl;//42
    *p2 = 53;
    cout << "*p1 = " << *p1 << endl;//53
    cout << "*p2 = " << *p2 << endl;//53
    p1 = new int;
    *p1 = 88;
    cout << "*p1 = " << *p1 << endl;//88
    cout << "*p2 = " << *p2 << endl;//53
    cout << "Hope you got the point of this example!\n";
    cout << "-----------------Task 4------------------" << endl;
    int a(10);
    cout << "Value: " << a << "\tLocation: " << &a << endl;//10,stack
    int b = 20;
    cout << "Value: " << b << "\tLocation: " << &b << endl;//20,stack

    int* c;
    c = new int(30);
    cout << "Value: " << *c << "\tLocation: " << c << endl;//30,heap,stack

    int* d, e;
    d = new int(40);
    e = 50;
    cout << "Value: " << *d << "\tLocation: " << d << endl;//40,heap,stack
    cout << "Value: " << e << "\tLocation: " << &e << endl;//50,stack

    int* f;
    f = d;
    cout << "Value: " << *f << "\tLocation: " << f << endl;//40,heap

    cout << "-----------------Task 5------------------" << endl;
    int* A;
    A = new int(100);
    int * B;
    B = A;
    cout << "The value of A is " << *A << endl;//100
    cout << "A is pointing to the location " << A << endl;//heap
    cout << "The value of B is " << *B << endl;//100
    cout << "B is pointing to the location " << B << endl;//heap,same as A
    cout << "Returning the memory for A to the heap: " << endl;
    delete A;
    //A = nullptr;
    //B = nullptr;
    cout << "The value of A is " << *A << endl;//gibberish, modified not working
    cout << "A is pointing to the location " << A << endl;//heap, same as before, modified not working
    cout << "The value of B is " << *B << endl;//gibberish,modified not working
    cout << "B is pointing to the location " << B << endl;//heap, same as A, modified not working


    cout << "-----------------Task 6------------------" << endl;
    int vals[5];
    for(size_t it = 0; it < sizeof(vals); it++) {
        vals[it] = (it * it);
    }
    cout << "-----------------Task 7,8------------------" << endl;
    for(size_t it = 0; it < 9;it++) {
        int input;
        cout << "Enter the number you want to put in the array" << endl;
        cin >> input;

        vals[it] = input;
        cout << &vals[it] << endl;
    }
    for(int val : vals) {
        cout << val << endl;
    }
    cout << "-----------------Task 9------------------" << endl;
    int input = 0;
    int len = 0;
    int capacity = 1;
    int* arr = new int[capacity];
    do {
        cout << "Enter the number you want to input, enter -100086 to quit: " << endl;
        cin >> input;
        arr[len] = input;
        len++;
        if(len == capacity) {
            capacity *= 2;
            int* arr_temp = new int[capacity];
            for(int it = 0; it <= len; it++) {
                arr_temp[it] = arr[it];
            }
            delete[] arr;
            arr = arr_temp;
            //cout << arr[len] << endl;
            arr_temp = nullptr;
        }

    }while(input != -100086);
    cout << "Array contents: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    cout << "-----------------Task 10------------------" << endl;
    const char* testStr1 = "radar";
    const char* testStr2 = "hello";

    cout << "Is '" << testStr1 << "' a palindrome? " << (isPalindrome(testStr1) ? "Yes" : "No") << endl;
    cout << "Is '" << testStr2 << "' a palindrome? " << (isPalindrome(testStr2) ? "Yes" : "No") << endl;

    return 0;
}
