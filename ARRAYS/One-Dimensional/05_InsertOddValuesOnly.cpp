#include <iostream>
using namespace std;

int main() {
    int arr[100], n, value, count = 0;

    cout << "How many values do you want to enter: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;

        if (value % 2 != 0) {
            arr[count] = value;
            count++;
        }
    }

    cout << "Odd values in array: ";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
