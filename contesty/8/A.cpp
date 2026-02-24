#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
    int32_t n;
    cin >> n;

    vector <int32_t> x;
    int32_t x_i;

    for (int i = 0; i < n; i++) {
        cin >> x_i;
        x.push_back(x_i);
    }

    //mozemy sobie posortowac te ceny sklepow, ich kolejnosc nie ma znaczenia
    sort(x.begin(), x.end(), [](auto &a, auto &b) {
         return a < b;
    });

    int32_t q;
    cin >> q;

    int64_t m_i;
    int32_t k;

    for (int j = 0; j < q; j++) {
        cin >> m_i;  
        
        // k nam bedzie zliczac ilosc dostepnych sklepow w danym dniu j
        for (k = 0; k < n; k++) {
            if (m_i >= x[k]) {
                continue;
            }
            else {
                break;
            }
        }
        cout << k << endl;
    }
}