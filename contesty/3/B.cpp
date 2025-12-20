#include<iostream>
#include<string>

using namespace std;

#define print(var) cout << #var <<": " << var << endl;

int main() {

    string line;
    getline(cin, line);

    int count_1 = 0;
    int count_2 = 0;
    int count_3 = 0;

    int number;
    int count_all;


    for(int i = 0; i < line.length(); i = i + 2) {

        number = (line[i] - '0');

        if (number == 1) {
            count_1 ++;
        }
        else if (number == 2) {
            count_2 ++;
        }
        else if (number == 3) {
            count_3 ++;
        }
    }

    count_all = count_1 + count_2 + count_3;

    for(int i = 1; count_1 > 0; count_1--) {
        cout << 1;

        count_all--;
        if (count_all > 0)
        {
            cout << '+';
        }
    }

    for(int i = 1; count_2 > 0; count_2--) {
        cout << 2;

        count_all--;
        if (count_all > 0)
        {
            cout << '+';
        }
    }

    for(int i = 1; count_3 > 0; count_3--) {
        cout << 3;

        count_all--;
        if (count_all > 0)
        {
            cout << '+';
        }
    }

}