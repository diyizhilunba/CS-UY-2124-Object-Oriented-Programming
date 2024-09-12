#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

/*
Define variables for the stream and vector. No, don't open the stream here.
Call a function to open the stream.
The stream object will be passed into the function.
The function will ask the user for a filename.
If opening the filename fails, then ask for a new one, repeatedly, until you succeed.
By the time this function is done, the stream should be open.
It does not need to return anything, so the return type would be void.
Call a function to fill the vector from the stream.
Pass in the vector and the stream.
Do not return anything.
Call a function to display the vector
Call a function to sort the vector, in place.
Call a function to display the vector.
A function to insert the information for a name, carbon count and hydrogen count into the vector.
This would be called by the function called from main that fills the vector.
A function to find the location of a formula object that matches the number of hydrogen and carbons for a new entry.
*/
//Define Structs:
struct molecule{
    string name;
    int carb;
    int hydro;
};
//Define functions:
void open_file(ifstream& file);
void pass_stream(vector<molecule>& moles, ifstream& file);//pass all molecule
void display_vector(vector<molecule> moles);//merge
void sort_vector(vector<molecule>& moles);
void fill_vector_helper(vector<molecule>& moles, string str1, string str2);//
int find_formula(vector<molecule> moles, molecule new_mole);//
void print_mole(molecule mole);

int main() {
    //variables:
    ifstream file;

    open_file(file);
    vector<molecule> moles;
    pass_stream(moles, file);
    cout << "Unsorted: " << endl;
    display_vector(moles);
    sort_vector(moles);
    cout <<"\nSorted: " << endl;
    display_vector(moles);
    file.close();
}
//Construct functions:
void open_file(ifstream& file) {
    string input;
    do{
        cout << "Enter the file name to open:" << endl;
        cin >> input;
        file.open(input);
    }while(! file);
    cout << "file opened" << endl;
}

void pass_stream(vector<molecule>& moles, ifstream& file) {
    string line1;
    string line2;
    while(file >> line1 >> line2) {
        fill_vector_helper(moles, line1, line2);
    }
}

void fill_vector_helper(vector<molecule> &moles, string str1, string str2) {
    molecule mole;
    mole.name = str1;
    int c_loc = 0;
    int h_loc = 0;
    int carb_num;
    int hydro_num;
    int vector_loc;
    for(int it = 0; it < str2.size();++it) {
        if(str2[it] == 'C') {
            c_loc = it + 1;
        }
        else if(str2[it] == 'H') {
            h_loc = it + 1;
        }
    }
    carb_num = stoi(str2.substr(c_loc,h_loc-1));
    hydro_num = stoi(str2.substr(h_loc));
    mole.carb = carb_num;
    mole.hydro = hydro_num;

    vector_loc = find_formula(moles,mole);
    if(vector_loc == moles.size()) {
        moles.push_back(mole);
    }
    else {
        moles.at(vector_loc).name += " ";
        moles.at(vector_loc).name += mole.name;
    }





}


int find_formula(vector<molecule> moles, molecule new_mole) {
    for(size_t it = 0; it < moles.size(); it++) {
        int std_carb = moles[it].carb;
        int std_hydro = moles[it].hydro;
        if(std_carb == new_mole.carb && std_hydro == new_mole.hydro) {
            return it;
        }
    }

    return moles.size();
}

void display_vector(vector<molecule> moles) {
    for(molecule mole: moles) {
        print_mole(mole);
    }
}

void print_mole(molecule mole) {
    cout << "C" << mole.carb << "H" << mole.hydro << " " << mole.name << endl;
}

void sort_vector(vector<molecule> &moles) {
    bool swapped;
    int n = moles.size();
    for (int it1 = 0; it1 < n-1; ++it1) {
        swapped = false;
        for (int it2 = 0; it2 < n-it1-1; ++it2) {
            if (moles[it2].carb > moles[it2 + 1].carb ||
                (moles[it2].carb == moles[it2 + 1].carb && moles[it2].hydro > moles[it2 + 1].hydro)) {
                swap(moles[it2], moles[it2 + 1]);
                swapped = true;
                }
        }

        if (!swapped)
            break;
    }
}


