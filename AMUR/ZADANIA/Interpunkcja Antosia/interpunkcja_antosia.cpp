#include <iostream>
#include <string>

using namespace std;

int main() {
    int16_t n;
    cin >> n;

    string str;

    for (int16_t i = 0; i < n; i++) {
        getline(cin, str);

        int16_t len =  str.length();
        str.insert(str.end(), 'G');
    }
    cout << str;
}