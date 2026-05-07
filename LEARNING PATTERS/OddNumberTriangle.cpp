#include <iostream>
using namespace std;

int main() {
    for (int rows = 1; rows <= 5; rows++) {
        int num = 1;  // har row me reset hoga

        for (int columns = 1; columns <= rows; columns++) {
            cout << num << " ";
            num += 2;  // next odd number
        }

        cout << endl;
    }
}