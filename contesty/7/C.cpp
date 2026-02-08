#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int32_t n, x;

    cin >> n;

    int32_t counter;

    for (int i = 0; i < n; i++) {

        cin >> x;

        if (x == 1) {
            cout << 1 << endl;
            continue;
        }

        counter = 0;
        int j;

        for(j = 1; j < sqrt(x); j++) {
            if (x % j == 0) {
                counter += 2;
            }
        }
        //warunek dla liczb ktorych pierwiastek jest calkowity - wtedy bedzie nieparzysta liczba podzielnikow
        if (int(sqrt(x)) * int(sqrt(x)) == x) {
            counter++;
        }
        cout << counter << endl;
    }
}