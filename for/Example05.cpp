#include<iostream>

using namespace std;

int main(){
			
	int percentCompleted = 50;
	int barWidth = 50;
	int filled = (percentCompleted * barWidth) / 100;
	
	cout << "[";

	for (int i = 0; i < barWidth; ++i) {
	    if (i < filled){
	    	cout << "=";
	    } else {
			cout << " ";
		}
	}

	cout << "] " << percentCompleted << "%\n";

	return 0;

}