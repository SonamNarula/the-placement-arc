#include <iostream>
using namespace std;

int main() {
    int arr[100], n, num, count = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number to count: ";
    cin >> num;

    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            count++;
        }
    }

    cout << num << " occurs " << count << " times" << endl;
    return 0;
}
