#include<iostream>

using namespace std;
int main() {
    int n;

    cin >> n;
    cin.ignore();

    int output = 0;

    for (int i = 0; i < n; i++) {
        int number;
        int sum = 0;
        
        cin >> number;
        sum += number;

        cin >> number;
        sum += number;

        cin >> number;
        sum += number;

        if (sum > 1) {
            output++;
        }

    }
    cout << output;
}