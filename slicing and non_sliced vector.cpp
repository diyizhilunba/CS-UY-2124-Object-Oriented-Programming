/*
 *vector object can be slicing too.
 *Don't forget virtual!
 */

#include <iostream>

#include <vector>

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

class Ewok:public Pet {

};

class WompRat:public Pet {

};

int main() {

     Blurrg creature;
     Ewok fluffy;
     WompRat ratFace;

     //vector<Pet&> vector_of_pets;//Won't compile just as you cannot declare int& var ->
     //a reference must be initialized when it it created. Pointers can be initialized at any time

     vector<Pet> vector_of_pets;
     vector_of_pets.push_back(creature);
     vector_of_pets.push_back(fluffy);
     vector_of_pets.push_back(ratFace);
     for(Pet& p: vector_of_pets) {
      p.method_a();
      p.method_b();
      p.method_c();
      cout << "------" << endl;
      vector<Pet*> vector_of_new_pets;
      vector_of_new_pets.push_back(&creature);
      vector_of_new_pets.push_back(&fluffy);
      vector_of_new_pets.push_back(&ratFace);

      for(Pet* p: vector_of_new_pets) {
       p->method_a();
       p->method_b();
       p->method_c();
       cout << "---------" << endl;
      }
     }


}