#include<iostream>

using namespace std;

int main(){
		
	int readings[] = {45, 52, 48, 49, 47, 53};
	int sum = 0;
	int count = sizeof(readings)/sizeof(readings[0]);
	
	for (int i = 0; i < count; ++i) {
	    sum += readings[i];
	}
	
	double avg = static_cast<double>(sum) / count;
	cout << "Average: " << avg << "\n";

	return 0;

}