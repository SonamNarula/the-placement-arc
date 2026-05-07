#include <iostream>
#include <cmath>

using namespace std;


int main() {
	
    int num;
    bool isPrime = true;
    
    cout << "Enter a Positive Integer: ";
    cin >> num;
    
    // 0 and 1 are not prime numbers
    if (num <= 1) {
        isPrime = false;
    } else {
        // Check divisibility from 2 to sqrt(num)
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    
    if (isPrime)
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is not a prime number." << endl;
    
    return 0;
    
}

/*

A prime number is a natural number greater than 1 that 
has no positive divisors other than 1 and itself.

*/