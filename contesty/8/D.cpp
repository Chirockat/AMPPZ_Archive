#include<iostream>

using namespace std;

int main() {
    int32_t n, t;
    cin >> n >> t;

    int64_t arr [n];
    int32_t x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x;
    }

    int32_t max_sum = 0;
    int32_t local_sum = 0;
    int64_t local_time = 0;

    int32_t i = 0;
    int32_t j = 0;

    // gasięnica, wydluzamy albo skracamy okno o 1 (zwykle)
    while (j < n) {
        if (local_time + arr[j] <= t) {
            local_time += arr[j]; 
            local_sum++;
            max_sum = max(local_sum, max_sum);
            j++; 
        }
        else {
            // to sie moze zdazyc jak ksiazka jest za wielka i nie da sie jej calej przeczytac
            if (i == j) {
                j++;
                i++;
            } else {
                local_time -= arr[i];
                local_sum--;
                i++;
            }
        }
    }

    cout << max_sum;
}