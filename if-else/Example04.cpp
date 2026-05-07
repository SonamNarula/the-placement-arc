#include<iostream>

using namespace std;

int main(){
			
	double cartTotal = 150.0;	
	bool isMember = true;
	
	if (cartTotal >= 100 && isMember) {

	    double discount = cartTotal * 0.2;
	    cout << "You save $" << discount << "\n";

	} else if (cartTotal >= 100) {

	    cout << "Join membership to get 20% off.\n";

	} else {

	    cout << "Add items for $100 to get discount.\n";

	}

	return 0;

}