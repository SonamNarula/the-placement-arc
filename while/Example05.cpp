#include<iostream>

using namespace std;

int main(){
	
	char command;
	double temperature;

	cout << "Monitoring. Enter 'q' to quit.\n";
	
	while (true) {  // infinite loop, break inside
	    cout << "Read temperature: ";
	    cin >> temperature;
	    if (temperature > 80.0) {
	        cout << "Overheat! Shutting down.\n";
	        break;
	    }
	    cout << "Temp OK. Continue? (y/n): ";
	    cin >> command;
	    if (command == 'n') break;
	}

	return 0;

}