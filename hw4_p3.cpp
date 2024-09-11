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

//Task 3: input each student’s grade as an integer and store the grade in a vector.
//Grades should be entered until the user enters a -1 for a grade.
//The program should then scan through the vector and compute the histogram
struct Grade {
    int grade;
    int times;
};

int main(){
    //variables:
    int input;
    int size = 1;
    int repeat = -1;
    //Grade temp;
    Grade* grd = new Grade[size];
    cout << "Enter student grades (-1 to stop): \n";
    do {
        cin >> input;
        if(input != -1) {
            for(size_t ind = 0; ind < size; ++ind) {
                if(grd[ind].grade == input) {
                    repeat = ind;
                }
            }
            if(repeat != -1) {
                grd[repeat].times += 1;
                //cout << "grade has repeated," << grd[repeat].grade << grd[repeat].times;
            }
            else {
                Grade* old_grd = grd;

                grd = new Grade[size+1];
                for(size_t ind = 0; ind < size; ++ ind) {
                    grd[ind] = old_grd[ind];
                }
                size += 1;
                grd[size-1] = Grade{input, 1};
                delete[] old_grd;

            }
            repeat = -1;
        }
    }while(input != -1);
    for (size_t ind = 1 ; ind < size; ++ind) {
        cout << "Number of " << grd[ind].grade << " ' s:" << "\t" << grd[ind].times << endl;
    }

    delete[] grd;


    return 0;
}

