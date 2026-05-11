#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mid = n / 2;
    int midValue = arr[mid];

    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * midValue;
    }

    cout << "Array after multiplication: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
