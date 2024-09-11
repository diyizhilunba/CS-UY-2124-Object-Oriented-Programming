/*
 *
 */
#include <iostream>

using namespace std;

class Shape {
public:
    Shape(int x, int y):x(x),y(y){}
    void move(int x_offset, int y_offset) {
        this -> x += x_offset;
        this ->y += y_offset;
    }
    virtual void draw() = 0;// pure virtual function, aka, abstract function
    //Also, we make the whole class abstract, the shape class cannot be instantiated

private:
    int x,y;
};

class Triangle:public Shape {
public:
    Triangle(int x, int y):Shape(x,y){}

    void draw() override {
        cout << "Traingle is drawn" << endl;
    }
};

class Isosceles:public Shape {
public:
    Isosceles(int x, int y):Shape(x,y){}

    void draw() override
    {
        cout << "Isosceles is drawn" << endl;
    }
};

class Circle:public Shape {
public:
    Circle(int x, int y):Shape(x,y){}

    void draw() override
    {
        cout << "Circle is drawn" << endl;
    }
};



int main() {
    //Shape basic(4,5); It is abstract and not work
    //have to create child class
    Triangle triangle(2,2);
    triangle.draw();
    Isosceles iso(3,3);
    iso.draw();

    Circle circle(4,4);
    circle.draw();
    return 0;
}
