#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// sam bym tego za chiny nie zrobił
// to trzeba zapamiętać po prostu

int main () {
    int32_t n, x;
    cin >> n >> x;


    // wyjatkowo zaczynamy od 1 indeksowanie
    vector <int32_t> price (n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    vector <int32_t> page_count (n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> page_count[i];
    }

    // Tworze macierz dla Programowania Dynamicznego (wektor wektorów)
    // ilosc wierszy to n (ilosc przedmiotow); ilosc kolumn to x (maksymalna cena)
    vector <vector <int32_t>> dp (n + 1, vector <int32_t> (x + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            // sprawdzamy czy da sie wziac sam przedmiot na ktorym jestesmy
            if (price[i] > j) {
                dp [i][j] = dp [i-1][j];
            }
            // [j - price[i]], czemu?
            // j to mój aktualny budzet, wiec odejmujemy cene za te ksiazke, dodajemy ilosc stron. 
            // Sprawdzamy czy to lepsze rozwiazanie niz nie wziecie ksiazki.
            else {
                dp [i][j] = max(dp [i-1][j], dp[i-1][j - price[i]] + page_count[i]);
            }
        }
    }

    // wypełnienie tej macierzy to jedyne co potrzebujemy zrobić. Nasz wynik jest w jej prawym dolnym rogu.

    cout << dp[n][x] << "\n";

    // wypisanie tej macierzy:

    // cout << endl;
    // for (int j = 1; j <= x; j++) {
    //     cout << j << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= x; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

}