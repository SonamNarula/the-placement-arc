#include<iostream>

using namespace std;

int main(){
		
	int temperature = 38; // Celsius
	
	if (temperature > 35) {
	    cout << "Heat wave warning! Stay indoors.\n";
	} else if (temperature > 25) {
	    cout << "Pleasant weather.\n";
	} else {
	    cout << "Cool, wear a jacket.\n";
	}
	
	return 0;

}