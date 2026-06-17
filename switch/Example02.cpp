#include<iostream>

using namespace std;

int main(){
			
	int statusCode = 404;
	
	switch (statusCode) {
	    case 200:	cout << "OK – proceed\n"; break;
	    case 201:	cout << "Created\n"; break;
	    case 400:	cout << "Bad request – check input\n"; break;
	    case 401:	cout << "Unauthorized – login required\n"; break;
	    case 404:	cout << "Not found – resource missing\n"; break;
	    case 500:	cout << "Server error – try again later\n"; break;
	    default:	cout << "Unhandled status\n";
	}
	
	return 0;

}