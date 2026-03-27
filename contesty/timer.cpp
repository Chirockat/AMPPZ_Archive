#include<iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;

int main () {

    // Wczytanie danych

    auto start = high_resolution_clock::now();

    // Tutaj cos sie liczy

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time: " << duration.count() << " ms" << endl;
}