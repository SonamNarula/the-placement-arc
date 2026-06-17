#include<iostream>

using namespace std;

int main(){
	
	bool stopRequested = false;
	int cycle = 0;
	do {
	    cycle++;
	    cout << "Running test cycle " << cycle << "\n";
	
	    stopRequested = (cycle >= 3);  // stops after 3 cycles
	
	} while (!stopRequested);
	cout << "Stopped.\n";
	
	return 0;

}