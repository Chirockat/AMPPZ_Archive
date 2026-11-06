#include<iostream>
#include<cmath>

#define print(var) cout << #var <<": " << var << endl;

using namespace std;

// Jest zrobione tylko zamienianie liczby binarnej na dziesiatna bo mi sie nie chcialo wiecej

int main() {
    int l;
    cin >> l;

    char c;
    int digit;
    int power = l - 1;
    int sum = 0;

    for (int i = 0; i < l; i++) {
        cin >> c;

        digit = c - '0';
        sum += digit * (1 << power);

        power--;
        print(sum);
    }
    cout << sum << endl;
}


/*ALTERNATYWNE ZAMIENIANIE STRINGA DOWOLNEGO SYSTEMU NA LICZBE

#include <iostream>
#include <string>

using namespace std;

int main() {
    int l;
    string binary;
    cin >> l >> binary;

    // Zamiana tekstu w systemie dwójkowym (2) bezpośrednio na int
    int sum = stoi(binary, nullptr, 2);

    cout << sum << endl;
    return 0;
}

*/