#include <iostream>

using namespace std;

bool is_palindrome(string str) {
    int start, end;
    
    end = str.length() - 1;
    for (start = 0; start < str.length()/2 + 1; start++) {
        if(str[start] != str[end]) {
            return false;
        }
        end--;
    }
    return true;
}
    

int main() {
    cout << is_palindrome("abacba") << endl;
}