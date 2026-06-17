#include <iostream>
using namespace std;

int main() {
	
    int rows;
    
    cout << "Enter the number of rows: ";
    cin >> rows;
    
    // Loop for each row
    for (int i = 1; i <= rows; i++) {
        // Print spaces for alignment (centered pyramid)
        for (int j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        // Print stars: odd number per row (2*i - 1)
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }
        // Move to the next line after each row
        cout << endl;
    }
    
    return 0;
}