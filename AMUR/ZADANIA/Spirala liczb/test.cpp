#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int32_t t;
    
    if (!(cin >> t)) return 0;

    while (t--) {
        int64_t n;
        cin >> n;

        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }

        // Znajdujemy warstwę (pierścień 'k'), na której leży liczba n.
        int64_t r = sqrt(n - 1);
        int64_t k = (r + 1) / 2;

        // Obliczamy przesunięcie liczby na danym boku pierścienia.
        // Długość "krawędzi" na warstwie k wynosi dokładnie 2*k.
        int64_t offset = (n - 1) % (2 * k);
        
        // Całkowita odległość manhattańska to dystans wyjścia do pierścienia (k)
        // plus odległość liczby od środka danej krawędzi.
        int64_t dist = k + abs(offset - k);

        cout << dist << "\n";
    }

    return 0;
}