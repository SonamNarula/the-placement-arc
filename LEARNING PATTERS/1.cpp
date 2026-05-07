#include<iostream>
using namespace std;

int main()
{
    for(int rows = 0; rows<5; rows++)
    {
        for(int columns = 0; columns < rows; columns++){
            cout << " * ";
        }
        cout << endl;
    }
}