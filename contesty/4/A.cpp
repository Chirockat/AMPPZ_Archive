#include<iostream>
#include<string>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    string answer = "";

    for (int i = 0; i < line.length(); i++) {
        if (toupper(line[i]) == ('A') || toupper(line[i]) == ('O') ||  toupper(line[i]) == ('Y') || 
        toupper(line[i]) == ('E') || toupper(line[i]) == ('U') || toupper(line[i]) == ('I')) {
            continue;
        }
        answer = answer + '.';
        answer = answer + (char)tolower(line[i]);
        
    }
    cout << answer;
}