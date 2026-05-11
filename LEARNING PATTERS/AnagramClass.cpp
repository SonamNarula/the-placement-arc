#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Anagram {
private:
    string first;
    string second;

public:
    void getInput() {
        cout << "Enter first string: ";
        cin >> first;

        cout << "Enter second string: ";
        cin >> second;
    }

    void checkAnagram() {
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());

        if (first == second) {
            cout << "Strings are anagram" << endl;
        } else {
            cout << "Strings are not anagram" << endl;
        }
    }
};

int main() {
    Anagram obj;

    obj.getInput();
    obj.checkAnagram();

    return 0;
}
