#include <iostream>
#include <cstring>
#include <cmath>

#define print(var) cout << #var <<": " << var << endl;

using namespace std;

int main() {
    int16_t n;
    cin >> n;

    string str;
    char ch;
    int16_t digit;
    

    for(int i = 0; i < n; i++) {

        int64_t number = 0;

        cin >> str;
        int16_t l = str.length();
        int16_t power = l - 1;
        for (int j = 0; j < l; j++) {
            ch = str[j];
            if (ch == 'A') {
                digit = 10;
            }
            else {
                digit = ch - '0';
            }
            
            number += digit * pow(11,power);
            power--;
        }

        cout << number << endl;
    }
}