#include<iostream>

using namespace std;

#define print(var) cout << #var <<": " << var << endl;

int main() {
    int n;
    cin >> n;

    int count_1s = 0;
    int count_2s = 0;
    int count_3s = 0;
    int count_4s = 0;

    int output = 0;

    int number;

    for (int i = 1; i<= n; i++) {
        cin >> number;
        switch (number) {
        case 1:
            count_1s++;
            break;
        case 2:
            count_2s++;
            break;
        case 3:
            count_3s++;
            break;
        case 4:
            count_4s++;
            break;
        }
    }
    
    // czworki
    output = output + count_4s;
    count_4s = 0;

    // trojki + jedynki
    while (count_3s > 0 && count_1s > 0) {
        output++;
        count_3s--;
        count_1s--;
    }

    // pozostale, niepelne trojki
    while (count_3s > 0) {
        output++;
        count_3s--;
    }

    // pary dwojek
    while (count_2s / 2 > 0) {
        output++;
        count_2s -= 2;
    }

    // ewentualna dwojka + dwie jedynki
    if (count_2s == 1 && count_1s >= 2) {
        output++;
        count_2s--;
        count_1s -= 2;
    }

    // ewentualna dwojka + jedynka
    if (count_2s == 1 && count_1s >= 1) {
        output++;
        count_2s--;
        count_1s -= 1;
    }

    // ewentualna niepelna dwojka
    if (count_2s == 1) {
        output++;
        count_2s--;
    }

    // kwartety jedynek
    while (count_1s / 4 > 0) {
        output++;
        count_1s -= 4;
    }

    // ewentualne pozostale jedynki
    if (count_1s > 0) {
        output++;
        count_1s = 0;
    }

    cout << output;

    // print(count_4s);
    // print(count_3s);
    // print(count_2s);
    // print(count_1s);
}