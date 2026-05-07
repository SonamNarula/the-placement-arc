#include<iostream>

using namespace std;

int main(){
	
	int score;
	
	do {
	
	    cout << "Enter a score between 0 and 100: ";
	    cin >> score;
	
	} while (score < 0 || score > 100);
	
	cout << "Valid score: " << score << "\n";

	return 0;

}