#include<iostream>

using namespace std;

int main(){
	
	int choice;

	do {
	    
		cout << "\nMenu:\n1. Withdraw\n2. Deposit\n3. Balance\n4. Exit\n";
	    cout << "Choose: ";
	    cin >> choice;
	    
	} while (choice != 4);

	return 0;

}