#include<iostream>

using namespace std;

#define print(var) cout << #var <<": " << var << endl;

int main() {

    int i,j, temp;
    for (i = 1; i <= 5 ; i++) {
        for(j = 1; j <= 5 ; j++) {
            cin >> temp;
            if (temp == 1) {
                goto end;
            }
        }
    }

    end:
    cout << abs(3 - i) + abs(3 - j);
}
