#include <iostream>
using namespace std;

int main() {
 
    int num, reversed = 0, remainder;
    
    cout << "Enter an integer: ";
    cin >> num;
    
    int original = num;  // store for later display
    
    // Reverse the number
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    
    cout << "Reversed number of " << original << " is: " << reversed << endl;
    
    return 0;
}