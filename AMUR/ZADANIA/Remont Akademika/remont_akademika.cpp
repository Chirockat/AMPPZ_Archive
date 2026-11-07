#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int32_t n;
    cin >> n;

    int64_t sum_students = 0;
    int16_t room_students;
    int32_t output = n;

    vector <int16_t> pokoje (n);

    for (int i = 0; i < n; i++) {
        cin >> room_students >> pokoje[i];
        sum_students += room_students;
    }
    
    // dziwna konstrukcja dla sortowania od najwiekszego 
    // do najmniejszego, warto zapamietac
    sort(pokoje.begin(), pokoje.end(), greater<int>());

    // jesli jacys studenci sa, to co najmniej 1 pokój bedzie zajety
    if (sum_students != 0) {
        output--;
    }

    for (int i = 0; i < n; i++) {
        if (sum_students > pokoje[i]) {
            output--;
            sum_students -= pokoje[i];
        }
        else {
            break;
        }
    }

    cout << output << endl;

}