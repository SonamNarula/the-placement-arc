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

    int sum = arr[0][0] + arr[0][cols - 1] + arr[rows - 1][0] + arr[rows - 1][cols - 1];

    cout << "Sum of corners: " << sum << endl;
    return 0;
}
