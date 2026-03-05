#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int32_t n;
    int64_t x;
    cin >> n >> x;

    vector <int64_t> vec(n);
    for (int64_t &element : vec) {
        cin >> element;
    }

    //sortujemy wektor malejąco, bo tak mi łatwiej myśleć
    sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        return a > b;
    });

    // 2 iteratory, jeden idzie od poczatku, drugi idzie od konca

    //4 10
    //9 7 3 2
    //i     j
    
    int32_t i;
    int32_t j = n - 1;

    int64_t local_gondola = 0;
    int32_t output = 0;

    for (i = 0; i <= j; i++) {
        local_gondola = vec[i];
        if (local_gondola + vec[j] > x) {
            local_gondola = 0;
            output++;
        }
        else {
            local_gondola += vec[j];
            for (j-1; local_gondola <= x; j--) {
                local_gondola += vec[j];
            }
            output++;
        }
    }

    cout << output;
}