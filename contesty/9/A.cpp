
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
};



int main()
{
    int32_t n;
    cin >> n;

    vector <Element> vec(n);



    for (int i = 0; i < n; i++) {
        cin >> vec[i].a;
        cin >> vec[i].b;

    }

    // sortowanie po dlugosciach filmu
    sort(vec.begin(), vec.end(), [](const Element& left, const Element& right) {
        return left.b < right.b;
    });


    int32_t output = 0;
    int32_t last_movie_end = 0;

    // ZMIANA 3: Iterujemy tylko raz. Jeśli film zaczyna się po (lub w momencie) zakończenia 
    // poprzedniego, to go bierzemy i aktualizujemy czas.
    for (int32_t i = 0; i < n; i++) {
        if (vec[i].a >= last_movie_end) {
            output++;
            last_movie_end = vec[i].b;
        }
    }
    
    cout << endl << output;

    
}