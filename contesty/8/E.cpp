
#include<iostream>
#include<vector>
#include<numeric> 

using namespace std;




int main() {

    int32_t n, t;
    cin >> n >> t;

    int32_t arr [n];

    // nowoczesne wczytywanie wartosci, bo czemu nie
    for (int32_t &i : arr) {
        cin >> i;
    }

    int64_t a = 1;
    int64_t b = n * t;

    int64_t sum_a = 0;
    int64_t sum_b;
    int64_t previous_a;

    int64_t best_sum = INT64_MAX;

    // ta petla zmniejsza rozwiazanie az bedzie mniejsze od t
    while(true) {
        previous_a = sum_a;
        for (int i = 0; i < n; i++) {
            sum_a += a / arr[i];
        }
        if (sum_a >= t) {
            a = a/2;
        }
        else {
            break;
        }
        
    }
    
    // ta petla zwieksza rozwiazanie az bedzie rowne lub wieksze t
    while (true) {
        for (int i = 0; i < n; i++) {
            sum_a += a / arr[i];
            sum_b += a / arr[i];
        }
        

    }


    cout << best_sum;

}





        // mniejszy prog nie spelnia targetu - biezemy gorny zakres
        if (sum_a < t) {
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