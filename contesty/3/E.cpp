#include<iostream>
#include<string>
#include <cctype>

using namespace std;

#define print(var) cout << #var <<": " << var << endl;

int main() {

    int n;
    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);

    int anton_count = 0;
    int danik_count = 0;

    for(int i = 0; i < n; i++) {
        if(line[i] == 'A') {
            anton_count++;
        }
        else {
            danik_count++;
        }
    }

    if(anton_count > danik_count) {
        cout << "Anton";
        exit(0);
    }
    if(anton_count < danik_count) {
        cout << "Danik";
        exit(0);
    }
    cout << "Friendship";
}