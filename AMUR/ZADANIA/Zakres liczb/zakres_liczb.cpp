#include <iostream>

#define print(var) cout << #var <<": " << var << endl;

using namespace std;

int main() {
    int16_t t;
    cin >> t;

    int32_t n;
    int64_t number;
    int64_t min = INT64_MAX;
    int64_t max = INT64_MIN;

    for (int i = 0; i < t; i++) {
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> number;
            
            if (number < min){
                min = number;
            }
            if (number > max) {
                max = number;
            }         
        }
        cout << max - min << endl;
        min = INT64_MAX;
        max = INT64_MIN;
    }

}