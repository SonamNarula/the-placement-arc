#include<iostream>

using namespace std;

int main(){
				
	int day = 2; // Tuesday
	
	switch (day) {
	    case 1: cout << "Monday – Back to Work\n"; break;
	    case 2: cout << "Tuesday\n"; break;
	    case 3: cout << "Wednesday – Mid of the Week\n"; break;
	    case 4: cout << "Thursday\n"; break;
	    case 5: cout << "Friday – TGIF\n"; break;
	    
		case 6: cout << "Weekend – RELAX\n"; break;
	    case 7: cout << "Weekend – RELAX\n"; break;
	    
		default: std::cout << "Invalid day\n";
	}
	
	return 0;

}