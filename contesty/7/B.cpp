#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int32_t n;
    int64_t x;
    int64_t x_sqrt;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;

        if (x == 1) {
            goto skip;
        }

        x_sqrt = sqrt(x);
        if (x_sqrt * x_sqrt != x) {
skip:       cout << "NO" << endl;
            continue;
        }
        for (int j = 2; j <= sqrt(x_sqrt); j++) {
            if (x_sqrt % j == 0) {
                goto skip;
            }
        }
        cout << "YES"<< endl;
        
    }
}