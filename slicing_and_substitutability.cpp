/*
 *If S is a subtype of T, then objects of type T in a program may be replaced with objects of type S
 *without altering anything else
 *
 *BLurrg has 3 member function, 2 self-defined(a,b), 3rd(c) is inhereted
 *When we call method a, c++ looks at the derived class first to see whether that class defines the funcion
 *When we call method b, same thing happens
 *does not matter whether the base class defines method_a,b or not
 *
 *The derived class does not contain a member function named method_c,
 *When we call method c on thhe derived class, C++ tries to find the function in the derived class, and fails
 *THen it tries to find the member function in the base class(Pet), it finds it there
 *None of these deals with virtual
 *
 *Then we introduce polymorphism and the do_base function
 *it tells C++ that the search rules are CHANGED!
 *C++ first check the derived class for member method_b, and then
 *base class
 *As it is in derived class, it executes method_b from the derived class(Blurrg)
 *Member function method_c is also virtual, therefore, C++ starts by looking in the derived class.
 *It is not defined there, so C++then looks in the base class
 */

#include <iostream>
using namespace std;

class Pet {
public:
    void method_a() {
        cout << "PEt::method_a was called\n";

    }
    virtual void method_b(){cout <<"Pet::method_b was called." << endl;}
    virtual void method_c(){cout << "Pet::method_c was called" << endl;}
};

class Blurrg:public Pet {
public:
    void method_a(){cout << "Blurrg::method_a " << endl;}

    void method_b(){cout << "Blurrg::method_b " << endl;}


};

void do_base(Pet pet_obj) {
    cout << "Calling functions in the Pet base class: " << endl;

    pet_obj.method_a();

    pet_obj.method_b();

    pet_obj.method_c();
}

void do_base_reference(Pet pet_obj) {
    cout << "Calling functions in the Pet base class by reference: " << endl;
    /*
     *Pet_obj demonstrates polymorphism here, can be either a pet or a blurrg, outputs "Pets::method_a was called"
     */

    pet_obj.method_a();

    pet_obj.method_b();

    pet_obj.method_c();
}

int main() {
    Pet grogv;
    Blurrg grrulb;

    cout << "Calling functions" << endl;
    grrulb.method_a();//blurrg
    grrulb.method_b();//blurrg
    grrulb.method_c();//pet
    cout << endl;

    do_base(grrulb);//Principle of substitutability
    do_base_reference(grrulb);//Different from last one

    return 0;
}