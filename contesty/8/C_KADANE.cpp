#include<iostream>

using namespace std;

int main() {
    int32_t n;
    cin >> n;

    int64_t arr [n];
    int32_t x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x;
    }

    int64_t max_sum = arr[0];
    int64_t local_sum = 0;

    for (int i = 0; i < n; i++) {
        // Warunek dla samych ujemnych liczb, 
        if (local_sum == 0 && arr[i] <= 0) {
            max_sum = max(max_sum, arr[i]);
            continue;
        }

        local_sum += arr[i];

        max_sum = max(max_sum, local_sum);

        if (local_sum <= 0) {
            local_sum = 0;
        }
    }

    cout << max_sum;
}