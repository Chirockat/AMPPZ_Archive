#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
    int32_t n;
    cin >> n;

    vector <int32_t> x;
    int32_t x_i;


    for (int32_t i = 0; i < n; i++) {
        cin >> x_i;
        x.push_back(x_i);
    }

    //mozemy sobie posortowac te ceny sklepow, ich kolejnosc nie ma znaczenia
    sort(x.begin(), x.end(), [](auto &a, auto &b) {
         return a < b;
    });

    // teraz zamieniamy wektor powyzej na wektor kolejnych liczb, wskazujacych
    // na ile butelek nas stac. np:
    // 3, 6, 8  zmieniamy na:
    // 0, 0, 0, 1, 1, 1, 2, 2, 3

    // wektor od razu robimy duzego rozmiaru, czyli  
    // ostatniego elementu orginalnego wektora
    vector <int32_t> y;
    y.reserve(x.back());
  
    // zera wstawiamy recznie na poczatku
    x_i = x[0];
    for (int j = 0; j < x_i; j++) {
        y.push_back(0);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < x[i] - x[i - 1]; j++) {
            y.push_back(i);
        }
    }

    // na sam koniec wstawiamy n - powyzej indeksu tego elementu juz na wszystkie sklepy starczy
    y.push_back(n);


    int32_t q;
    cin >> q;

    int64_t m_i;

    for (int k = 0; k < q; k++) {
        cin >> m_i;
        if (m_i >= y.size()) {
            cout << n << endl;
        }
        else {
            cout << y[m_i] << endl;
        }
    }

    
}