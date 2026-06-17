#include <iostream>
using namespace std;

int main() {
    for (int rows = 1; rows < 5; rows++) {
        for (int columns = rows; columns < 5; columns++) {
            cout << " * ";
        }
        cout << endl;
    }
}