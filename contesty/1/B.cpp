#include<iostream>
#include<string>

using namespace std;
int main() {
    int n;

    cin >> n;
    cin.ignore(); // trzeba bo sie jedna linia mniej wczytuje bo costam \n zostaje

    for(int i = 0; i < n; i++) {
        
        string line;

        getline(cin, line);

        if (line.length() > 10) {
            char start = line[0];
            char end = line[line.length() - 1];
            int middle_size = line.length() -2;

            cout << start + to_string(middle_size) + end << endl;
        }
        else {
            cout << line << endl;
        }
    }

}
