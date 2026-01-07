#include<iostream>

using namespace std;

int main() {
    string word1;
    string word2;

    getline(cin, word1);
    getline(cin, word2);

    if (word1.length() != word2.length()) {
        cout << "NO";
        exit(0);
    }

    int j = word2.length() - 1;

    for (int i = 0; i < word1.length(); i++) {
        if (word1[i] != word2[j]) {
            cout << "NO";
            exit(0);
        }
        j--;
    }

    cout << "YES";
}