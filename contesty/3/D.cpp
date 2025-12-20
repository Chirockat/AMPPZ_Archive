#include<iostream>
#include<string>
#include <cctype>

using namespace std;

#define print(var) cout << #var <<": " << var << endl;

int main() {
    string line1;
    getline(cin, line1);

    string line2;
    getline(cin, line2);



    for(int i =0 ; i < line1.length(); i++) {
        if(toupper(line1[i])  == toupper(line2[i])) {
            continue;
        }
        
        if(toupper(line1[i])  > toupper(line2[i])) {
            cout << 1;
            exit(0);
        }

        if(toupper(line1[i])  < toupper(line2[i])) {
            cout << -1;
            exit(0);
        }
    }
    cout << 0;
}