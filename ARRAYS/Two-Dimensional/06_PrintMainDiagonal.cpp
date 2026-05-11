#include <iostream>
using namespace std;

int main() {
    int arr[10][10], n;

    cout << "Enter size of square matrix: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Main diagonal elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i][i] << " ";
    }

    return 0;
}
