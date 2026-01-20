#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int p,q;
    int output = 0;

    for (int i = 1; i <= n; i++ ) {
        cin >> p >> q;

        if (q - p >= 2) {
            output++;
        }
    }

    cout << output;
}