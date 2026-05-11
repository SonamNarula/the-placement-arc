#include <iostream>
using namespace std;

int main() {
    int arr[10][10], rows, cols;
    int even = 0, odd = 0;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];

            if (arr[i][j] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
    }

    cout << "Even numbers: " << even << endl;
    cout << "Odd numbers: " << odd << endl;
    return 0;
}
