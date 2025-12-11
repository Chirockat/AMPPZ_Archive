#include<iostream>

using namespace std;
int main() {

    while(true){
        int number;

        cin >> number;

        if(number!=42) {
            cout << number << endl;
        }
        else {
            break;
        }
    }
    
}