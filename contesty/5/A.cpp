#include<iostream>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    int w = n;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        if  (a > h) {
            w++;
        }
    }
    cout << w;
}