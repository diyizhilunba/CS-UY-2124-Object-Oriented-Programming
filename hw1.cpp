/*
Author: Yilun Ma
Assignment: HW1
Date due: May 30
I pledge that I have completed this assignment without the use of AI tools or collaborating with anyone else,
in conformance with the NYU School of Engineering Policies and Procedures on Academic Misconduct.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//function declaration:

bool isinVector(const vector<int>& nums, int aim);

void makeUnique(const vector<int>& original, vector<int>& result);

vector<int> fillVectFromFile();

void outputFile(const vector<int>& read_nums);

int main() {
    //variables:
    vector<int> read_nums;
    vector<int> unique_nums;

    read_nums = fillVectFromFile();
    makeUnique(read_nums,unique_nums);
    /*for(size_t it = 0; it < unique_nums.size(); it++) {
        cout << unique_nums[it] << endl;
    }*/
    outputFile(unique_nums);
    return 0;
}

//function definition:
/*Task 1:
 *a function determines whether a given integer exists within a provided vector or array of integers
 *parameters: a vector of ints to search for, an integer as the number the user want to search
 *use reference here for smaller space
 *reaturn: boolean, true for in vector, false for not in
 */
bool isinVector(const vector<int>& read_nums, int aim) {
    for(int elem: read_nums) {
        if(elem == aim) {
            return true;
        }
    }
    return false;
}

/*Task 2:
 *creates a new vector containing unique elements from a given vector or array of integers
 *parameter: the original int vector that need to delete replicates, a result empty vector that get modified for
 *all unique ints
 *return: no return, direct change
 */
void makeUnique(const vector<int>& original, vector<int>& unique) {
    for(int input_nums : original) {
        if(!isinVector(unique, input_nums)) {
            unique.push_back(input_nums);
        }
    }

}

/*Task 3:
 *populate a vector or array of integers with data retrieved from a user-selected input file
 *Parameter: none, directly ask the user for file name
 *return: an int vector for all the ints read from the file
 */
vector<int> fillVectFromFile() {
    ifstream ifs;
    string input;
    int readint;
    vector<int> file_nums;

    cout << "Enter the file name: " << endl;
    cin >> input;
    ifs.open(input);
    if(!ifs) {
        cerr << "Cannot find file: " << input;
        exit(1);
    }

    while(ifs >> readint) {
        //cout << readint <<endl;
        file_nums.push_back(readint);
    }
    ifs.close();

    return file_nums;

}
/*Task 4:
 *It doesn't need a function but I choose to do so
 *this function should read an int vector and write all those ints into a file named "unique_nums.txt"
 *parameters: an int vectors that need to be written to the file
 *return: none, directly change the file
 */
void outputFile(const vector<int>& read_nums) {
    ofstream ofs;
    ofs.open("../unique_ints.txt");
    if(!ofs) {
        cerr << "cannot open file" << endl;
        exit(1);
    }
    for(int read_num: read_nums) {
        ofs << read_num;
        ofs << " ";
    }
    ofs.close();

}




