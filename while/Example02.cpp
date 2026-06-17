#include<iostream>

using namespace std;

int main(){
	
	int age = -1;
	while (age < 0) {
	    cout << "Enter your age (>=0): ";
	    cin >> age;
	}
	cout << "Age recorded: " << age << "\n";

	return 0;

}