#include<iostream>

using namespace std;

int main(){
	
	double balance = 500.0;
	char seeAgain;
	do {
	    cout << "Your balance is: INR " << balance << "\n";
		cout << "See again? (y/n): ";
	    cin >> seeAgain;
	} while (seeAgain == 'y' || seeAgain == 'Y');

	return 0;

}