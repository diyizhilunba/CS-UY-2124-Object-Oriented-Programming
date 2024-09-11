//
// Created by mayil on 6/25/2024.
//

#include <iostream>
#include <vector>
using namespace std;

class Flier {
public:
    virtual void fly() const {
        cout << "I can fly!" << endl;
    }

};

class Plane:public Flier {
public:
    void fly() const override {
        cout << "Plane->vroom" << endl;
    }



};

class Animal {
public:
    virtual void display() {
        cout << "I am an animal!" << endl;

    }


};

class Bat: public Animal, public Flier {

};

class  Insect: public Animal,public Flier {
public:
    void fly() const override {
        cout << "insect -> Bzzzz" << endl;
    }

};


class Instructor {
public:
    virtual void display() const {
        cout << "Instructor\n";

    }



};

class Student {
public:
    virtual void display() const {
        cout << "Student" << endl;
    }
};
class TA:public Instructor,public Student {

};

int main() {
    Bat bruce_wayn;
    Plane boeing_737_max;
    Insect flik;

    cout << "Bat: " << endl;
    bruce_wayn.display();
    bruce_wayn.fly();

    cout << "------" << endl;

    vector<Flier*> fliers;
    fliers.push_back(&bruce_wayn);
    fliers.push_back(&boeing_737_max);
    fliers.push_back(&flik);

    for(const Flier* flier:fliers) {
        flier->fly();
    }

    //This fails
    for(const Flier* flier: fliers) {
        //flier->display();
    }

    cout << "------" << endl;
    TA anna;
    TA oleg;
    TA vamshi;
    //anna.display();//This will cause ambiguous call and does not work
    anna.Student::display();

    vector<Instructor> v_list;
    v_list.push_back(anna);
    v_list.push_back(oleg);
    v_list.push_back(vamshi);
    for(const Instructor &i : v_list) {
        i.display();//This works as you spicify it is instructor
    }



    return 0;
}