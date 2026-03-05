
#include<iostream>
#include<vector>
#include<numeric> 
#include<cstdint>

using namespace std;

#define print(var) cout << #var <<": " << var << endl;


int main() {

    int32_t n, p;
    cin >> n >> p;

    int32_t arr [n];

    // nowoczesne wczytywanie wartosci, bo czemu nie
    for (int32_t &i : arr) {
        cin >> i;
    }

<<<<<<< HEAD
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
=======
    int64_t max = INT64_MAX;



    // iloraz, poprzedni iloraz
    int64_t quotient = max;
    int64_t prev_quotient;

    int64_t local_sum;

    // szukamy, idąc od góry zakresy, największego dla ktorego nie uda sie wyrobic targetu
    do {
        local_sum = 0;
        prev_quotient = quotient;
        quotient = quotient/2;

        for (int i = 0; i < n; i++) {
            local_sum += quotient / arr[i];
            if (local_sum >= p) {
                break;
            }
        }
    } while (local_sum >= p);

    int64_t middle;

    //przerabiamy nazwy zmniennych tak na prawde, bo teraz maja wiekszy sens a i b
    int64_t a = quotient;
    int64_t b = prev_quotient;

    //wchodzimy z zakresem [a,b] i go zmniejszamy ciagle
    while (b - a > 1) {
        local_sum = 0;

        middle = (a + b) / 2;

        for (int i = 0; i < n; i++) {
            local_sum += middle / arr[i];
            if (local_sum >= p) {
                break;
            }
>>>>>>> ce4b854fdd2e3e0d2b23159b5c168581c000d64e
        }

        if (local_sum >= p) {
            b = middle;
        }
        else {
<<<<<<< HEAD
            break;
        }
=======
            a = middle;
        }
    }

    // wynik przy naszej opcji bedzie w b (troche to zagmatwane...)
    cout << b;

}
>>>>>>> ce4b854fdd2e3e0d2b23159b5c168581c000d64e
