#include<iostream>

using namespace std;

int main(){
		
	for (int enemy = 1; enemy <= 5; ++enemy) {
	    int x = enemy * 50;  // spacing 50 units
	    int y = 100;
	    cout << "Spawn enemy " << enemy << " at (" << x << "," << y << ")\n";
	}

	return 0;

}