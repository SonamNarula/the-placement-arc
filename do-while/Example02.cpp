#include<iostream>

using namespace std;

int main(){
	
	int dice;
	
	do {
	    dice = rand() % 6 + 1;
	    cout << "You rolled: " << dice << "\n";
	} while (dice != 6);
	
	cout << "You got a 6! Winner!\n";

	return 0;

}



/*


1. rand() – the random number generator
rand() is a function defined in <cstdlib> (or <stdlib.h> in C).

It returns a pseudo‑random integer between 0 and RAND_MAX (a implementation‑defined constant, typically at least 32767).

Important: The numbers are deterministic – they follow a sequence based on an initial seed. Without setting the seed, the same sequence is generated every time the program runs.


2. % 6 – modulo (remainder) operator
rand() % 6 computes the remainder when rand() is divided by 6.

Possible remainders: 0, 1, 2, 3, 4, 5 (six possible values).

This maps the large range of rand() into a small, uniform range of size 6.


3. + 1 – shifting the range
We want a die roll 1..6, not 0..5.

Adding 1 shifts the range: (0..5) + 1 = 1..6.


*/