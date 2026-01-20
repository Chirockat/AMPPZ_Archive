#include<iostream>
#include<set>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace std;

#define print(var) cout << #var <<": " << var << endl;


int main() {
    int n;

    cin >> n;

    //template set
    set<int> ts;
    //set
    set<int> s;
    vector<int> wynik;
    int liczba;

    
    for(int i = 1; i <= n; i++) {
        ts.insert(i);
    }
    for(int i = 1; i <n; i++) {
        cin >> liczba;
        s.insert(liczba);
    }
    
    set_difference(ts.begin(), ts.end(), s.begin(), s.end(), back_inserter(wynik)); 

    cout << wynik.back();  
}