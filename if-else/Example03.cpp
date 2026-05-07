#include<iostream>

using namespace std;

int main(){
			
	const string username = "alice";
	const string password = "1234";
	bool isAdmin = false;
	
	if (username == "admin" && password == "secret") {
	    cout << "Full system access.\n";
	} else if (username == "alice" && password == "1234") {
	    cout << "Welcome, Alice.\n";
	    
		if (isAdmin) {
	        cout << "You have admin rights.\n";
	    }
	    
	} else {
	    cout << "Invalid credentials.\n";
	}	

	return 0;

}