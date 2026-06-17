#include <iostream>
using namespace std;

int main() {
    int arr[10][10], rows, cols;
    bool found = false;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        int minCol = 0;

        for (int j = 1; j < cols; j++) {
            if (arr[i][j] < arr[i][minCol]) {
                minCol = j;
            }
        }

        bool isMaxInColumn = true;
        for (int r = 0; r < rows; r++) {
            if (arr[r][minCol] > arr[i][minCol]) {
                isMaxInColumn = false;
                break;
            }
        }

        if (isMaxInColumn) {
            cout << "Element is " << arr[i][minCol] << " at row " << i << " and column " << minCol << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No such element found" << endl;
    }

    return 0;
}
