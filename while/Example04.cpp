#include<iostream>

using namespace std;

int main(){
	
	bool connected = false;
	int attempts = 0;
	int maxAttempts = 5;
	
	while (!connected && attempts < maxAttempts) {
	    attempts++;
	    cout << "Attempt " << attempts << " to connect...\n";

	    connected = (attempts == 3); // succeeds on 3rd try

	}

	if (connected) cout << "Connected.\n";
	else cout << "Failed after " << maxAttempts << " attempts.\n";

	return 0;

}