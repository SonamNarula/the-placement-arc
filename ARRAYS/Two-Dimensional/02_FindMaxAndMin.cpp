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

    int maxValue = arr[0][0];
    int minValue = arr[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > maxValue) {
                maxValue = arr[i][j];
            }
            if (arr[i][j] < minValue) {
                minValue = arr[i][j];
            }
        }
    }

    cout << "Maximum: " << maxValue << endl;
    cout << "Minimum: " << minValue << endl;
    return 0;
}
