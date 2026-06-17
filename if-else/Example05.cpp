#include<iostream>

using namespace std;

int main(){
			
	int playerHealth = 100;
	
	if (playerHealth <= 0) {
	    
		cout << "Game Over.\n";
	
	} else if (playerHealth > 50) {
	
	    cout << "Keep Fighting... \n";
	
	} else if (playerHealth <= 50  && playerHealth > 25) {
	
	    cout << "You are Hit.\n";
	
	} else if (playerHealth <= 25) {
		
	    cout << "Low health – find a medkit.\n";
	
 	} else if (playerHealth <= 5) {
		
	    cout << "God can't save you.\n";
	
	} else {
	
	    cout << "Health is fine.\n";
	
	}

	return 0;

}