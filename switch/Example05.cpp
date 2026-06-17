#include<iostream>

using namespace std;

int main(){
					
	char grade = 'B';
	
	switch (grade) {
	    case 'A': cout << "10.0\n"; break;
	    case 'B': cout << "8.0\n"; break;
	    case 'C': cout << "5.0\n"; break;
	    case 'D': cout << "3.0\n"; break;
	    case 'F': cout << "0.0 – Fail\n"; break;
	    default:  cout << "Invalid Grade\n";
	}

	return 0;

}