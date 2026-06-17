#include<iostream>

using namespace std;

int main(){
	
	double withdrawalAmount = 2500.0;
	double balance = 1500.0;
	
	if (withdrawalAmount <= balance) {
	    balance -= withdrawalAmount;
	    cout << "Please take your cash.\n";
	} else {
	    cout << "Insufficient funds.\n";
	}

	return 0;

}