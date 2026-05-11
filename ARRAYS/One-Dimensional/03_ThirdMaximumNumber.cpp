#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[100], n;
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] != first && arr[i] != second) {
            third = arr[i];
        }
    }

    if (third == INT_MIN) {
        cout << "Third maximum does not exist" << endl;
    } else {
        cout << "Third maximum number: " << third << endl;
    }

    return 0;
}
