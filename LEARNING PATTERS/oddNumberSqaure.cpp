#include <iostream>
using namespace std;

int main() {
    
   
    for (int rows = 1; rows < 5; rows++) {

        int n = 1;
        for (int columns = 1; columns < 5; columns++) {
            n += 2;
            cout << " " << columns << " " ;
        }
        cout << endl;
    }
}