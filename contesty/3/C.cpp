#include<iostream>
#include<string>

using namespace std;

#define print(var) cout << #var <<": " << var << endl;

int main() {

    int n;
    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);

    int output = 0;

    for (int i = 1; i <= n; i++) {
        if(line[i] == line[i-1]) {
            output++;
        }
    }
    cout << output;
}