#include<iostream>
#include<vector>
#include<numeric> 

using namespace std;




int main() {

    int32_t n, p;
    cin >> n >> p;

    int32_t arr [n];

    // nowoczesne wczytywanie wartosci, bo czemu nie
    for (int32_t &i : arr) {
        cin >> i;
    }

    int64_t a = 1;
    int64_t b = n * p;

    int64_t sum_a;
    int64_t sum_b;
    int64_t local_best;

    int64_t best_sum = INT64_MAX;


    while(true) {
        sum_a = 0;
        sum_b = 0;
        local_best = 0;


        for (int i = 0; i < n; i++) {
            sum_a += a / arr[i];
            sum_b += b / arr[i];
        }
        // mniejszy prog nie spelnia targetu - biezemy gorny zakres
        if (sum_a < p) {
            a = b/2;
            local_best = sum_b;
        }
        // jesli spelnia - biezemy dolny zakres nastepny
        else {
            b = b/2;
            local_best = sum_b;
        }

        if (best_sum - t > local_best - t) {
            best_sum = local_best;
        }
        else {
            break;
        }
    }

    cout << best_sum;

}