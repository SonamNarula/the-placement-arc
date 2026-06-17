#include <iostream>
using namespace std;

int main() {
    int arr[100], n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value to remove: ";
    cin >> value;

    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            arr[i] = -1;
        }
    }

    cout << "Array after removing value: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
