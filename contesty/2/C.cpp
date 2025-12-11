#include<iostream>

using namespace std;

int main() {
    int k, n, w, output;
    
    int price = 0;

    cin >> k; // 1st banan
    cin >> n; // budget
    cin >> w; // banana count

    for (int i = 1; i <=w ; i++) {
        price += k * i;
    }

    output = n - price;
    if (output >= 0) {
        cout << 0;
    }
    else {
        cout << abs(output);
    }
}
