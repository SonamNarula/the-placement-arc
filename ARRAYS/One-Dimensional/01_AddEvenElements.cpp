#include <iostream>
using namespace std;

int main() {
    int arr[100], n, sum = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }

    cout << "Sum of even elements: " << sum << endl;
    return 0;
}
