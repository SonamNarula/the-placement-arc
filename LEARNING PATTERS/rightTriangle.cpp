#include <iostream>
using namespace std;

int main() {
    for (int rows = 1; rows < 5; rows++) {
        for (int columns = 1; columns < rows; columns++) {
            cout << " * ";
        }
        cout << endl;
    }
}