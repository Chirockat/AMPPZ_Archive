#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

    // w celu przyspieszenia programu (zaś ten test 25...)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t n;
    cin >> n;

    int64_t x;
    cin >> x;

    // pierwszy element to liczba, drugi to jej indeks
    unordered_map <int64_t, int> map;
    int64_t a;

    // ma niby przyspieszyc program
    map.reserve(n);

    // wypelniamy mape liczb i sprawdzamy od razu czy jakas pasuje do pary
    for (int i = 1; i <= n; i++) {
        cin >> a;
        
        if (map.count(x - a) != 0) {
            cout << map[x - a] << " ";
            cout << i;
            exit(0);
                
        }
        map[a] = i;
    }

    cout << "IMPOSSIBLE";;;

}