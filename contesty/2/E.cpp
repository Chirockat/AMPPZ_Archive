#include<iostream>

using namespace std;

int main() {
    int n, k;

    cin >> n;
    cin >> k;

    for (k; k >= 1; k--) {
        if (n%10 == 0) {
            n = n / 10;
        }
        else {
            n--;
        }
    }
    cout << n;
}