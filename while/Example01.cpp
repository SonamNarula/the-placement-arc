#include<iostream>
using namespace std;

int main(){
	int pin;
	int correctPin = 1234;

	cout << "Enter PIN: ";
	cin >> pin;

	while (pin != correctPin) {
	    cout << "Wrong PIN. Try again: ";
	    cin >> pin;
	}
	cout << "Access granted.\n";

	return 0;

}