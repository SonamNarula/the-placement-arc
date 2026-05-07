#include<iostream>

using namespace std;

int main(){
	
	double monthlyDeposit = 100.0;
	double total = 0.0;
	
	for (int month = 1; month <= 12; month++) {
	    
		total += monthlyDeposit;
	    cout << "Month " << month << " balance: INR " << total << "\n";
	
	
	}
	
	cout<< "\nTotal: " << total;

	return 0;

}