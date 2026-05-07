// TEMPERATURE MONITORING SYSTEM
#include <iostream>
using namespace std;

int main() {
    float temperature;

    cout << "Real-time Temperature Monitoring Started...\n";
    cout << "Enter negative value to shutdown.\n\n";

    while (true) {
        cout << "Enter temperature: ";
        cin >> temperature;

        // shutdown condition
        if (temperature < 0) {
            cout << "System Shutdown Initiated ❄️\n";
            break;
        }

        // processing
        if (temperature > 50) {
            cout << "⚠️ High Temperature Alert!\n";
        } 
        else if (temperature < 10) {
            cout << "🥶 Low Temperature Alert!\n";
        } 
        else {
            cout << "✅ Temperature Normal\n";
        }
    }

    cout << "Monitoring Stopped.\n";
    return 0;
}