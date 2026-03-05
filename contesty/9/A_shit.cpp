
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdint>

using namespace std;

struct Element {
    int32_t a;
    int32_t b;
    int32_t len;
};



int main()
{
    int32_t n;
    cin >> n;

    vector <Element> vec(n);

    // od razu szukamy najwiekszego b, przyda nam sie do dynamicznego zdefiniowania rozmiaru struktury
    int32_t max_b = 0;

    for (int i = 0; i < n; i++) {
        cin >> vec[i].a;
        cin >> vec[i].b;
        vec[i].len = vec[i].b - vec[i].a;

        if (vec[i].b > max_b) {
            max_b = vec[i].b;
        }

    }

    // sortowanie po dlugosciach filmu
    sort(vec.begin(), vec.end(), [](const Element& left, const Element& right) {
        return left.len < right.len;
    });

    // tera se tablice zrobimy, która będzie opisywać zapełnienie poszczególnych godzin.
    // true - godzina wolna; false - godzina zapelniona
    // jej size to godzina zakonczenia ostatniego filmu

    

    std::vector<bool> filling_tab(max_b, false);
    
    // indeks 0 jest poza zakresem to zapełniamy go recznie
    filling_tab[0] = true;;

    // wyglad tablicy dla przykladowych danych ze strony:
    // 1, 0, 0, 1, 1, 1, 1, 1, 1,

    int32_t output = 0;

    bool movie_viable;

    for (int32_t i = 0; i < n; i++) {
        movie_viable = true;
        for (int64_t j = vec[i].a + 1; j < vec[i].b; j++) {
            if (filling_tab[j] == true) {
                movie_viable = false;
                break;
            }
        }
        if (movie_viable) {
            for (int64_t j = vec[i].a; j <= vec[i].b; j++) {
                filling_tab[j] = true;
                
            }
            output++;
        }

    }
    
    cout << endl << output;

    
}