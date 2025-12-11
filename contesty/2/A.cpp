#include<iostream>
#include<string>

using namespace std;

int main() {
    int x = 0;

    int n;
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line;

        getline(cin, line);

        if (line[0] == '+' || line[2] == '+'){
            x++;
        }
        else {
            x--;
        }

    }
    cout << x;
}