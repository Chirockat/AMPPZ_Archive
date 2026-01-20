#include<iostream>
#include<vector>



using namespace std;

int main() {
    int t;
    cin >> t;

    int a,b;

    vector <int> output;

    for (int i = 1; i <= t; i++) {
        cin >> a >> b;

        if (a % b == 0) {
            output.push_back(0);
            continue;
        }

        if (a <= b) {
            output.push_back(b-a);
            continue;
        }
        output.push_back(b - (a % b)); 
    }

    for (int i = 0; i < t; i++) {
        cout << output[i] << endl;
    }
}