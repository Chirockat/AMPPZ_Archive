#include<iostream>


using namespace std;

int main() {
    int counter = 0;

    string line;
    getline(cin, line);

    for (int i = 0; i < line.length(); i++) {
        if ((int)line[i] <= 90) {
            counter++;
        }
        else{
            counter--;
        }
    }
    if (counter > 0){
        for (int i = 0; i < line.length(); i++) {
            cout << (char)toupper(line[i]);
        }
    }
    else {
        for (int i = 0; i < line.length(); i++) {
            cout << (char)tolower(line[i]);
        }
    }
}