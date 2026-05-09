#include <iostream>

using namespace std;

int main() {
    char gear = 'R';

    switch (gear) {
        case 'P':
            cout << "Park – Car Locked\n";
            break;
        case 'R':
            cout << "Reverse – Moving Backward\n";
            break;
        case 'N':
            cout << "Neutral – No Power to Wheels\n";
            break;
        case 'D':
            cout << "Drive – Moving Forward\n";
            break;
        default:
            cout << "Unknown Gear ??? \n";
    }

    return 0;
}