/*
  rec10_start.cpp
  Starting code 23S
 */

#include <iostream>
#include <vector>
using namespace std;

// 
// Musician class as provided to the students. Requires an Instrument class.
// 
class Instrument {
    friend ostream& operator<<(ostream& os, const Instrument& ins) {
        ins.display(os);
        return os;
    }
public:
    Instrument() {

    }
    virtual void makeSound() const = 0;
        // cout << endl; Can't add anything inside
    virtual void display(ostream& os) const {
        os << "Instrument";
    }
    virtual void play() const = 0;
};

class Brass:public Instrument{

public:

    Brass(int size):Instrument(),size(size) {

    }
    Brass():Instrument() {

    }
    void makeSound() const override{
        cout << "To make a sound... blow on a mouthpiece of size " << size << endl;
    }
    void display(ostream &os) const override {
        os << "Brass: " << size;
    }
    void play() const override {
    }
protected:
    unsigned int size;

};

class Trumpet:public Brass{

public:
    Trumpet(int size):Brass(size){}
    void display(ostream &os) const override {
        os << "Trumpet: " << size;
    }
    void play() const override {
        cout << "Toot" << endl;
    }
protected:

};
class Trombone: public Brass {

public:
    Trombone(int size):Brass(size){}
    void display(ostream &os) const override {
        os << "Trombone: " << size;
    }
    void play() const override {
        cout << "Blat" << endl;
    }
};

class String :public Instrument{

public:
    String(int pitch):Instrument(),pitch(pitch) {

    }
    String() :Instrument(){

    }
    void display(ostream &os) const override {
        os << "String: " << pitch;
    }
    void makeSound() const override {
        cout << "To make a sound... bow a string with pitch " << pitch << endl;
    }
    void play() const override {
        cout  << endl;
    }
protected:
    unsigned int pitch;
};

//violins and cellos
class Violin: public String {

public:

    Violin(int pitch):String(pitch){}
    Violin():String(){}
    void display(ostream &os) const override {
        os << "Violin: " << pitch;
    }
    void play() const override {
        cout << "Screech" << endl;
    }
};

class Cello: public String {

public:
    void display(ostream &os) const override {
        os << "Callo: " << pitch;
    }
    void play() const override {
        cout << "Squawk" << endl;
    }
    Cello(int pitch):String(pitch){}
    Cello():String(){}
};


class Percurssion:public Instrument{

public:
    void display(ostream &os) const override {
        os << "Percurssion";
    }
    void play() const override {
        cout <<  endl;
    }
    Percurssion():Instrument(){}
    void makeSound() const override{
        cout << "To make a sound... hit me! "<< endl;
    }
};

// drums and cymbals
class Drum: public Percurssion {

public:
    void display(ostream &os) const override {
        os << "Drum";
    }
    void play() const override {
        cout << "Boom" << endl;
    }
    Drum():Percurssion(){}
};

class Cymbal: public Percurssion {

public:
    void play() const override {
        cout << "Crash" << endl;
    }
    void display(ostream &os) const override {
        os << "Cymbal";
    }
    Cymbal():Percurssion(){}
};

class MILL {
    friend ostream& operator<<(ostream& os, MILL& mill) {
        bool contain_item = false;
        for(Instrument* ins: mill.inventory) {
            if(ins != nullptr) {
                contain_item = true;
            }
        }
        if(contain_item) {
            os << "| ";
            for(Instrument* ins: mill.inventory) {
                if(ins != nullptr) {
                    os << *ins << " | ";
                }
                else {
                    os << "(empty)" << " | ";
                }

            }
            os << endl;
        }
        else {
            os << "None" << endl;
        }
        return os;
    }
public:
    MILL(){

    }
    void receiveInstr(Instrument& ins) {
        ins.makeSound();
        int first = check_first_empty();
        if(first >= 0) {
            inventory[first] = &ins;
        }
        else {
            inventory.push_back(&ins);
        }



    }
    int check_first_empty() {
        for(size_t ind = 0; ind < inventory.size(); ++ind) {
            if(inventory[ind] == nullptr) {
                return ind;
            }

        }
        return -1;
    }
    int check_first_not_empty() {
        for(size_t ind = 0; ind < inventory.size(); ++ind) {
            if(inventory[ind] != nullptr) {
                return ind;
            }

        }
        return -1;
    }

    void dailyTestPlay() {
        bool contain_item = false;
        for(Instrument* ins: inventory) {
            if(ins != nullptr) {
                contain_item = true;
            }
        }
        if(contain_item) {
            for(Instrument* ins: inventory) {
                if(ins != nullptr) {
                    ins->makeSound();
                }
                else {
                    cout << "empty" << endl;
                }
            }
        }
        else {
            cout << "No instrument" << endl;
        }
    }
    Instrument* loanOut() {
        int first = check_first_not_empty();
        if(first >= 0) {
            Instrument* instru = inventory[first];
            inventory[first] = nullptr;
            return instru;
        }
        else {
            return nullptr;
        }
    }
private:
    vector<Instrument*> inventory;
};

class Musician {
public:
    Musician(const string& name) : instr(nullptr), name(name) {}

    // acceptInstr takes in an instrument for the Musician to later play.
    //  "loses" any instrument that it used to have.
    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    // giveBackInstr: gives the instrument that the Musicial was holding "back"
    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }

    // testPlay: testing out my instrument
    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << name << " has no instr\n";
    }

    // play: play the instrument

    //   Not making it const so that Instrument::play method does not
    //   need to be const. Allows the instrument to be modifed in the
    //   process of being played.
    void play() {
        if (instr) instr->play();
        // Don't do anything if we don't have an instrument.
    }
private:
    Instrument* instr;
    string name;
};

class Orch {
public:
    
    void addPlayer(Musician& member) {
        //cout << "A member is joined: " << endl;
        members.push_back(&member);
    }
    void play() const {
        for (Musician* member : members) {
            member->play();
        }
        cout << endl;
    }

private:
    vector<Musician*> members;
};

int main() {
    //
    // PART ONE
    //
    cout << "P A R T  O N E\n";

    cout << "Define some instruments ---------------------------------------\n";
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12) ;
    trpt.makeSound();
    Violin violin(567) ;
    drum.makeSound();
  
    cout << "Define the MILL -----------------------------------------------\n";
    MILL mill;
    cout << "The MILL before adding instruments:\n" << mill << "\n\n";

    cout << "Put the instruments into the MILL -----------------------------\n";
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    cout << "\nThe MILL after adding some instruments:\n" << mill << "\n\n";

    cout << "Daily test ----------------------------------------------------\n"
     << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;

    cout << "Define some Musicians------------------------------------------\n";
    Musician harpo("Harpo");
    Musician groucho("Groucho");

    cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
    //groucho.testPlay();	 // Groucho doesn't have an instrument yet.

    groucho.acceptInstr(mill.loanOut());
    groucho.testPlay();

    cout << "\ndailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;

     groucho.testPlay();
     mill.receiveInstr(*groucho.giveBackInstr());
     harpo.acceptInstr(mill.loanOut());
     groucho.acceptInstr(mill.loanOut());
     groucho.testPlay();
     harpo.testPlay();

    cout << "\ndailyTestPlay()" << endl;
    mill.dailyTestPlay();

    cout << "\nThe MILL after giving out some instruments:\n";
    cout << mill << "\n\n";

    cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
    mill.receiveInstr(*groucho.giveBackInstr());

    cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
    mill.receiveInstr(*harpo.giveBackInstr());
    cout << endl;

    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();

    cout << "\nThe MILL at the end of Part One:\n";
    cout << mill << endl;

    //
   // PART TWO

    cout << "\nP A R T  T W O\n";

    Musician bob("Bob");
    Musician sue("Sue");
    Musician mary("Mary");
    Musician ralph("Ralph");
    Musician jody("Judy");
    Musician morgan("Morgan");

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    // //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    // //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    // //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    //     // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    cout << endl << mill << endl;

}
