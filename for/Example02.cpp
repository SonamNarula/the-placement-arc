#include<iostream>
#include<vector>


using namespace std;

int main(){
	
	vector<string> products = {"Laptop", "Mouse", "Keyboard", "Monitor"};
	
	for (int i = 0; i < products.size(); ++i) {
	    cout << i+1 << ". " << products[i] << "\n";
	}

	return 0;

}