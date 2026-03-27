#include<iostream>

using namespace std;

int function(int64_t number, int32_t output) {
    if (number < 10) {
        return output + 1;
    }
    if (number == 10) {
        return output + 2;
    }
    
    // podejscie zachlanne - odejmujemy najwieksza mozliwa cyfre od naszej liczby
    string s = to_string(number);
    int16_t maxc = 0;
    for (char c : s) {
        int16_t cyfra = c - '0';
        if (cyfra > maxc)
            maxc = cyfra;
    }
    return function (number - maxc, output + 1);

}

int main() {
    int64_t n;
    cin >> n;
    cout << function (n, 0);
}