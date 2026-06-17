#include <iostream>
using namespace std;
 
int main(){
  
	int _totalValue;
	int _row, _column;
 
	cout<<"Enter Number of Rows : ";
  	cin>>_totalValue;
 
	 
  	for (_row = 1; _row <= _totalValue; _row++){
	    for (_column = 1;  _column<= _totalValue ; _column++){		
	      cout<<" *";
		}
		cout<<endl;
	}

    
  return 0;
}
