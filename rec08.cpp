/*
  rec06_begin.cpp
  CS2124
  Yilun Ma
  Focus: Dynamic arrays and copy control
 */

#include <string>
#include <iostream>
using namespace std;

// 
// Position class
// 
class Position {
    friend ostream& operator<<(ostream& os, const Position& rhs)
    {
        os << '[' << rhs.title << ',' << rhs.salary << ']';
        return os;
    } // Position op<<
public:
    Position(const string& aTitle, double aSalary)
        : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
private:
    string title;
    double salary;
}; // class Position


// 
// Directory class
// 
class Directory {
    // 
    // nested Entry class
    // 
    class Entry {
	friend ostream& operator<<(ostream& os, const Entry& rhs)
        {
	    os << rhs.name << ' ' << rhs.room
	       << ' ' << rhs.phone << ", " << *rhs.pos;
	    return os;
	} // Entry op<<
    public:
	Entry(const string& name, unsigned room, unsigned phone, Position& position)
	    : name(name), room(room), phone(phone), pos(&position) {
	}
	const string& getName() const { return name; }
	unsigned getPhone() const { return phone; }
    private:
	string name;
	unsigned room;
	unsigned phone;
	Position* pos;
    }; // class Entry


    // Overload Directory's output operator
    // ...
    friend ostream& operator<<(ostream& os, Directory& rhs) {
        os << rhs.company << endl;
        for(size_t ind = 0; ind < rhs.size ; ++ind) {
            os << *(*(rhs.entries + ind)) << endl;
        }
        return os;
    }

public:
    unsigned operator[](const string& name) {
        for(size_t ind = 0; ind < size ; ++ind) {
            if(entries[ind]->getName() == name) {
                return entries[ind]->getPhone();
            }
        }
        return -1;
    }
    // Of course the first function you need to write for this (or
    // any) class is...
    // ???
    // ...
    Directory() {

    }
    Directory(const string& company):company(company),size(0),capacity(1){
        entries = new Entry *[capacity];
    }


    
    
    // We'll get you started with the add method, but obviously you
    // have a lot of work to do here.
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (size == capacity)	{
            // something is missing!!!  Add it!
            //cout << "if" << endl;
            Entry** old_enries = entries;

            entries = new Entry *[2 * capacity];
            for(size_t ind = 0; ind < size; ++ind) {
                entries[ind] = old_enries[ind];
            }
            capacity *= 2;
            //cout << "capacity " << capacity << endl;
            delete[] old_enries;
        } // if
        entries[size] = new Entry(name, room, ph, pos);
        //cout <<"size " << size << "\t" <<"entries[size] " << *entries[size] << endl;
        ++size;
        //cout << *this;
    } // add

    //
    // === Copy Control ===
    //
    // (get checked out on everything else before starting this)
    Directory(const Directory& rhs):company((rhs.company)),size(rhs.size),capacity(rhs.capacity) {
        cout << "Initializing Directory with another Directory" << endl;
        entries = new Entry *[capacity];

        for(size_t ind = 0; ind < size; ++ind) {
            entries[ind] = new Entry(*rhs.entries[ind]);
        }

    }
    ~Directory() {
        cout << "All memory has released" << endl;
        for(size_t ind = 0; ind < size; ++ind) {
            delete entries[ind];

        }
        delete[] entries;

    }
    Directory& operator=(const Directory& rhs) {
        cout << "Copying the Directory with the Directory at the right hand side" << endl;
        if(this != & rhs) {
            capacity = rhs.capacity;
            size = rhs.size;
            company = rhs.company;
            for(size_t ind = 0; ind < size; ++ind) {
                delete entries[ind];
            }
            delete[] entries;
            entries = new Entry *[capacity];
            for(size_t ind = 0; ind < size; ++ind) {
                entries[ind] = new Entry(*rhs.entries[ind]);
            }

        }
        return *this;
    }


private:	
    Entry** entries; // Notice the type!!! Pointer to Entry pointers.
    size_t size;
    size_t capacity;
    string company;
}; // class Directory

void doNothing(Directory dir)
{ 
    // You need to overload the Directory output operator before
    // uncommenting the next line.

    cout << dir << endl;
} // doNothing

int main()
{
	
    // Note that the Postion objects are NOT on the heap.
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
	

    // Create a Directory
    Directory d("HAL");

    // Add someone
    d.add("Marilyn", 123, 4567, boss);

    // print the directory
    cout << d << endl;

    // Use the square bracket operator, aka the Index operator,
    // to access someone's phone extension.
    cout << "d[\"Marilyn\"]: " << d["Marilyn"] << endl;
    cout << "======\n\n";

    // Everything working so far? Get checked out!!!

    Directory d2 = d;	// What function is being used??
    d2.add("Gallagher", 111, 2222, techie);
    cout << d2["Gallagher"] << endl;
    d2.add("Carmack", 314, 1592, techie);

    cout << "Directory d:\n" << d << endl;
    cout << "Directory d2:\n" << d2 << endl;

    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";

    // Should display 1592
    cout << d2["Carmack"] << endl;

    Directory d3("IBM");
    d3.add("Torvalds", 628, 3185, techie);
    d3.add("Ritchie", 123, 5813, techie);
    

    d2 = d3;
    // Should display 5813
    cout << d2["Ritchie"] << endl;

    cout << d2 << endl;

} // main
