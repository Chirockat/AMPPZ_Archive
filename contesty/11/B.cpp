#include<iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;

// Ciekawostka dnia - wczesniej ta funkcja byla rekurencyjna, ale byl stack 
// overflow gdzieś przy gornym zakresie zmiennej (dla n = 100000 bylo jeszcze ok).

int function(int64_t number, int32_t output) {
    while (true){
        if (number < 10) {
            return output + 1;
        }
        if (number == 10) {
            return output + 2;
        }
        
        // podejscie zachlanne - odejmujemy najwieksza mozliwa cyfre od naszej liczby
        string s = to_string(number);
        int16_t maxc = 0;
        for (char c : s) {
            int16_t cyfra = c - '0';
            if (cyfra > maxc)
                maxc = cyfra;
        }
        number = number - maxc;
        output++;
    }
}

int main() {
    int64_t n;
    cin >> n;

    auto start = high_resolution_clock::now();
    cout << function (n, 0) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time: " << duration.count() << " ms" << endl;
}

