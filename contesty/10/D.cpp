#include <iostream>

using namespace std;

int main () {
    int32_t n, m;
    cin >> n >> m;

    int32_t output = 0;

    while (1) {
        if (m == n) {
            cout << output << endl;
            break;
        }
        if (n > m) {
            cout << n - m + output << endl;
            break;
        }
        if (m % 2 == 0) {
            m = m/2;
            output++;
        }
        else {
            m++;
            output++;
        }

    }

}

/*
dla n = 4

6:
6 / 2 = 3
3 + 1 = 4 git

9:
9/2 = nie da sie/nie ma sensu
9 + 1 = 10
10 / 2 = 5
5 / 2 nie da sie
5 + 1 = 6
6 / 2 = 3
3 + 1 = 4

5 krokow
da sie szybciej?

--
4 i 9 generalnie

4 - 1
3 - 1
2 * 2
4 * 2


*/

