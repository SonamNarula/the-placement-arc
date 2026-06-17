#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "n = ";
    cin >> n;

    cout << "m= ";
    cin >> m;

    for (int rows = 0; rows < n; rows++) {
        for (int columns = 0; columns < m; columns++) {
            cout << " * ";
        }
        cout << endl;
    }
}