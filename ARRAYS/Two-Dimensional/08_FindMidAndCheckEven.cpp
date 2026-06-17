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

    int midRow = rows / 2;
    int midCol = cols / 2;
    int midValue = arr[midRow][midCol];

    cout << "Middle element: " << midValue << endl;

    if (midValue % 2 == 0) {
        cout << "Middle element is even" << endl;
    } else {
        cout << "Middle element is not even" << endl;
    }

    return 0;
}
