//
// Created by mayil on 6/25/2024.
//
/*
 *final keyword:
 *You can put it behind the class Name or function name
 *1. on a method you are overriding that you don't want anyone to further override
 *2. On a class to prevent it from being used as a base clss
 */
#include <iostream>
using namespace std;

class BaseClass {
public:
    virtual void foo() {
        cout << "BaseClass::foo()" << endl;
    }

    //However, we can do sth interesting
    virtual void bar() final = 0;//抽象

};

class ChildClass:public BaseClass {
public:
    ChildClass():BaseClass() {

    }
    void foo() override {
        cout << "ChildClass::foo()" << endl;
    }
};