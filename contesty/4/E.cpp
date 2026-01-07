#include<iostream>

using namespace std;

int main() {
    int weight1, weight2;
    int years = 1;

    cin >> weight1 >> weight2;

    while(1) {
        weight1 *= 3;
        weight2 *= 2;

        if (weight1 > weight2)
        {
            cout << years;
            break;
        }
        years++;
        
    }
}