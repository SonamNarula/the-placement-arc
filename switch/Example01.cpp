#include<iostream>
using namespace std;

int main(){

	char operation = '+';
	int a = 10, b = 5;

	switch (operation) {
	    case '+':	cout << a + b << "\n"; break;
	    case '-':	cout << a - b << "\n"; break;
	    case '*':	cout << a * b << "\n"; break;
	    case '/':
			        if (b != 0){
						cout << a / b << "\n";
					}else{
						cout << "Div by zero\n";
					}
			    	break;
	    default:	cout << "Invalid operation\n";
	}	
	
	return 0;

}