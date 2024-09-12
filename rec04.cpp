#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Package{
    int id;
    double weight;
};
class DeliveryTruck {
public:
    DeliveryTruck(int id);
    void setAdv(const string& str);
    string getAdv();
    void loadPackage(const string& file);
    void changeAdvertise();
    void display();
    double getCarWeight();
    double getTotalWeight();
    bool searchPackage(const int package_id);
    int getTruckId();
    string getThePackage();

private:
    int truckid;
    string adv;
    vector<Package> thePackages;
    double weight;
};
class DeliveryCompany {
public:
    void getTruck(const vector<int> id_list);
    bool searchAll(const int package_id);
private:
    vector<DeliveryTruck> trucks;
};

void menu();
void openStream(ifstream& ifs, const string& file);

int main() {
    int decision = 0;
    DeliveryCompany delivery_company;
    DeliveryTruck default_truck(1);

    do {
        menu();
        cin >> decision;
        if(decision == 1) {
            cout << "Truck:" << endl;
            cout << "id: " << default_truck.getTruckId() << endl;
            cout << "advertisement: " << default_truck.getAdv() << endl;
            cout << "packages: " << default_truck.getThePackage() << endl;
        }
        else if(decision == 2) {
            default_truck.changeAdvertise();

        }
        else if(decision == 3) {
            default_truck.loadPackage("../truck1.txt");
        }
        else if(decision == 4) {
            cout << default_truck.getCarWeight() << endl;
        }
        else if(decision == 5) {
            cout << default_truck.getTotalWeight() << endl;
        }
        else if (decision == 6) {
            int input_id;
            cout << "Enter your package id" << endl;
            cin >> input_id;
            cout << "Whether your package is on the truck: " << default_truck.searchPackage(input_id) << endl;
        }
        else if (decision == 7) {
            vector<int> ids;
            int input_id;
            do {
                cout << "Enter your id" << endl;
                cin >> input_id;
                ids.push_back(input_id);
            }while(input_id >= 0);
            delivery_company.getTruck(ids);
        }else if (decision == 8) {
            int input_id;
            cout << "Enter your package id" << endl;
            cin >> input_id;
            cout << "Whether your package is on the truck: " << delivery_company.searchAll(input_id) << endl;
        }
    }while(decision != -1);


    return 0;
}

void menu(DeliveryTruck truck) {
    int decision = 0;
    cout << "1: Display Default Truck Sample" << endl;
    cout << "2: Change Advertisement" << endl;
    cout << "3: Load Truck from the list" << endl;
    cout << "4: Show car weight" << endl;
    cout << "5: Show total weight" << endl;
    cout << "6: Search if your package is on this truck" << endl;

    cout << "8: Search your package in all package" << endl;

    cout << "Enter -1 to exit" << endl;

    cin >> decision;

}


DeliveryTruck::DeliveryTruck(int id):truckid(id) {

}

void DeliveryTruck::setAdv(const string& str) {
    adv = str;
}

string DeliveryTruck::getAdv() {
    return adv;
}
void openStream(ifstream& ifs, const string& file){
    ifs.open(file);
    if(!ifs) {
        cerr << "cannot open file";
    }

}

void DeliveryTruck::loadPackage(const string& file) {
    ifstream ifs;
    openStream(ifs, file);
    int package_id;
    double package_weight;
    while(ifs >> package_id >> package_weight) {
        thePackages.push_back(Package{package_id,package_weight});
    }
    ifs.close();
}

void DeliveryTruck::changeAdvertise() {
    string input;
    cout << "Enter what you want to advertise" << endl;
    cin >> input;
    adv = input;
    cout << "Your advertisement has been changed into" << adv << endl;
}

void DeliveryTruck::display() {
    cout << "Truck:" << endl;
    cout << "id: " << truckid << endl;
    cout << "advertisement: " << adv << endl;
    cout << "package: " << endl;
}

double DeliveryTruck::getCarWeight() {
    return weight;
}

double DeliveryTruck::getTotalWeight() {
    double total= weight;
    for(size_t it = 0;it < thePackages.size(); it++) {
        total += thePackages[it].weight;
    }
    return total;
}

bool DeliveryTruck::searchPackage(const int package_id) {
    for(size_t it = 0; it < thePackages.size(); it++) {
        if(thePackages[it].id == package_id) {
            return true;
        }
    }
    return  false;
}

int DeliveryTruck::getTruckId() {
    return truckid;
}

void DeliveryCompany::getTruck(const vector<int> id_list) {
    string filename;
    ifstream ifs;

    for(size_t it = 0; it < id_list.size(); it++) {
        filename = "../truck" + to_string(id_list[it]) + ".txt";
        DeliveryTruck trk(it);
        trk.loadPackage(filename);
        trucks.push_back(trk);
    }
}
string DeliveryTruck::getThePackage() {
    string str;
    if(thePackages.size() == 0) {
        return "No package now";
    }
    for(size_t it = 0; it < thePackages.size(); it++) {
        str += to_string(thePackages[it].id);
        str += " ";
        str += to_string(thePackages[it].weight);
        str += "\n";
    }
    return str;
}
bool DeliveryCompany::searchAll(const int package_id) {
    for(DeliveryTruck trk: trucks) {
        if(trk.searchPackage(package_id)){
            return true;
        }

    }
    return false;
}


