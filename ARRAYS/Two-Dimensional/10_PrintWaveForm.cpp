#include <iostream>
using namespace std;

int main() {
    int arr[10][10], rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Wave form: ";
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << " ";
            }
        } else {
            for (int j = cols - 1; j >= 0; j--) {
                cout << arr[i][j] << " ";
            }
        }
    }

    return 0;
}
