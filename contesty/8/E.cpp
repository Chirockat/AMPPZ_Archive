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
        }

        if (local_sum >= p) {
            b = middle;
        }
        else {
            a = middle;
        }
    }

    // wynik przy naszej opcji bedzie w b (troche to zagmatwane...)
    cout << b;

}