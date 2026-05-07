#include <iostream>
#include <string>
using namespace std;

class Employee {
    unsigned int id;
    string name;
    double salary;

public:
    // Constructor (default values set kar raha hai)
    Employee() {
        id = 0;
        name = "";
        salary = 0.0;
    }

    void addEmployeeRecords(unsigned int i, string n, double s) {
        id = i;
        name = n;
        salary = s;
    }

    void showEmployeeRecords() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    ~Employee() {
        cout << "Hi, I am a destructor..!" << endl;
    }
};

int main() {

    Employee objJOHN;
    objJOHN.addEmployeeRecords(101, "Sonam", 4800.00);
    objJOHN.showEmployeeRecords();

    cout << endl;

    Employee objMIKE;
    objMIKE.addEmployeeRecords(102, "ABC", 5500.00);
    objMIKE.showEmployeeRecords();

    cout << endl;

    Employee objDAVID;
    objDAVID.addEmployeeRecords(103, "XYZ", 6200.00);
    objDAVID.showEmployeeRecords();

    return 0;
}