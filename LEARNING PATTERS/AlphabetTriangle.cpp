#include <iostream>
using namespace std;

int main() {
    int n = 4;

    for (int rows = 1; rows <= n; rows++) {
        char ch = 'A';  // 🔥 har row me reset

        for (int columns = 1; columns <= n; columns++) {
            cout << ch << " ";
            ch++;  // next alphabet
        }

        cout << endl;
    }

    return 0;
}