#include<iostream>

using namespace std;

int main(){
		
	int health = 30;
	int maxHealth = 100;
	
	while (health < maxHealth) {
	    health += 10;
	    if (health > maxHealth) health = maxHealth;
	    cout << "Regenerating... Health Power: " << health << "\n";
	}

	return 0;

}