#include <iostream>
using namespace std;

int main() {
    int arr[10][10], rows, cols, sum = 0;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    cout << "Sum of all elements: " << sum << endl;
    return 0;
}
