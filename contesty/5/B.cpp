#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a;

    for (int i = 1; i <= n; i++) {
        cin >> a;

        if(a != 0) {
            cout << "HARD";
            exit(0);
        }
    }
    cout << "EASY";
}