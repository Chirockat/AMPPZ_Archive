#include <iostream>
#include <queue>

using namespace std;
/*

idea - zeby obliczyc n = 15, zapamietujemy jaki bylby wynik dla 6 poprzednich, i dodajemy je
czyli, w poprzednich niewazne ilu rzutach:
    - rzucilem 14, to teraz musze rzucic 1
    - rzucilem 13, to teraz musze rzucic 2
    ...
*/

int main() {


    int32_t n;
    cin >> n;

    const int32_t MOD = 1000000007;

    queue<int32_t> last_six_values;

    for (int i = 0; i < 5; ++i) {
        last_six_values.push(0);
    }
    
    last_six_values.push(1);

    int32_t output = 0;
    
    // Zmienna trzymająca bieżącą sumę wszystkich 6 elementów w kolejce
    int32_t sum_of_window = 1; 

    for (int32_t i = 1; i <= n; ++i) {

        // Wynik dla obecnego pola to suma 6 poprzednich
        output = sum_of_window;

        // wyrzucamy ostatnia liczbe z kolejki
        int32_t oldest_value = last_six_values.front();
        last_six_values.pop();

        // Wrzuć nasz nowo obliczony wynik na koniec kolejki
        last_six_values.push(output);

        
        sum_of_window = (sum_of_window + output - oldest_value) % MOD;

        // Tutaj przez to ze jest to modulo, to ponoc sie moze zdarzyc ze ta suma bedzie ujemna. Takze to naprawiamy.
        if (sum_of_window < 0) {
            sum_of_window += MOD;
        }
    }
 
    cout << output << "\n";
    

    return 0;
}


/*

Moj pierwszy pomysl to byly sumy newtona, bo np zeby obliczyc n = 5 to liczymy sumy newtona (5-1 po 4-1) + (5-1 po 3-1) + (5-1 po 2-1) + 2
Ale po n = 6 to sie psuje wszystko bo mamy 6 oczek.
Niby by sie dalo (Zasada włączeń i wyłączeń?) ale zlozonosc by byla za duza.

*/