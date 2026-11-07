#include <iostream>
#include <vector>
#include <cmath>

#define print(var) cout << #var <<": " << var << endl;

using namespace std;

double WAGA = 300;

int main() {
    int32_t n;
    cin >> n;

    int64_t sum = 0;

    // ten wektor tu niepotrzebny 
    // troche, ale w ramach przypomnienia
    vector <int64_t> numbers (n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        if (numbers[i] < 300) {
            sum ++;
        }
        else {
            sum += ceil(numbers[i] / WAGA);
        }
        print(ceil(numbers[i] / WAGA));
        

    }
    cout << sum;
}