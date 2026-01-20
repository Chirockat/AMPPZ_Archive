#include<iostream>
#include<set>

using namespace std;

#define print(var) cout << #var <<": " << var << endl;

// Ciekawostka - wcześniej próbowałem na
// unordered_set ale nie przeszło - time limit

int main() {
    int n;
    cin >> n;

    set<int> s;
    int32_t number;

    for (int i = 1; i <= n; i ++) {
        cin >> number;
        s.insert(number);
    }
    cout << s.size();
}