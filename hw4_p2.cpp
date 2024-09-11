/*
Author: Yilun Ma
Assignment: HW4.2
Date due: 06-20
I pledge that I have completed this assignment without the use of AI tools or collaborating with anyone else,
in conformance with the NYU School of Engineering Policies and Procedures on Academic Misconduct.
*/
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

//Task 2: enlarge the sorted int array on the heap
//and place the new item in the appropriate position in the array so that it remains sorted
void insertAndSort(int*& arr, int& size,int newInt);


int main(){
    // Sample execution
    int size = 5;
    int* arr = new int[size]{1, 3, 5, 7, 9};

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int newInt = 6;
    insertAndSort(arr, size, newInt);

    cout << "Array after insertion: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Clean up
    // add you cleaning up code here;
    delete[] arr;

    return 0;
}

void insertAndSort(int*& arr, int& size, int newInt) {
    size += 1;
    //copy the old data
    int* old_arr = arr;
    arr = new int[size];
    //variables
    bool insertion = false;
    //loop through
    for(size_t ind = 0; ind < size; ++ind) {
        if(old_arr[ind] < newInt) {
            arr[ind] = old_arr[ind];
                   }
        else {
            //if have not inserted before, insert
            if(!insertion) {
                //cout <<'d';
                insertion = true;
                arr[ind] = newInt;
            }
            else {
                //if have inserted, the i+1th should be the original ith
                arr[ind] = old_arr[ind - 1];

            }
        }
        //cout << arr[ind] << "\t";

    }
    delete[] old_arr;

}
