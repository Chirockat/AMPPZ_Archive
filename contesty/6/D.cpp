#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>


using namespace std;

#define print(var) cout << #var <<": " << var << endl;


int main() {
    int n;
    cin >> n;

    // taki wektor definiujemy, bo w pierwszym elemencie zapisujemy info o
    // pierwotnej kolejnosci, jako ze bedziemy sortowac leksykograficznie
    vector <pair<int, string>> v;
    string request;

    for (int i = 0; i < n; i ++) {
        cin >> request;
        v.push_back({i, request});
    }
    
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        // bez tego kod nie dziala prawidlowo dla n > 16
        if (a.second == b.second) {
            return a.first < b.first; 
        }
        return a.second < b.second;
    });

    int j;
    int sufix = 1;
    bool last_check = false;

    for (int i = 0; i < n - 1; i ++) {
        j = i + 1;
        if (v[i].second == v[j].second) {
            for (j; v[i].second == v[j].second; j++) {
                if (j >= n) {
                    break;
                }

                v[j].second = v[i].second + to_string(sufix);
                sufix++;

                // dodane reczne sprawdzenie ostateniego elementu, bo z nim byl problem
                if (j == n-1) {
                    last_check = true;
                }
            }

        }
        v[i].second = "OK";

        i = i + sufix - 1;

        sufix = 1;
    }
    if (last_check == false) {
        v[n-1].second = "OK";
    }
  
    // sortujemy z powrotem do orginalnej kolejnosci
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.first < b.first;
    });


    for (int i = 0; i < n; i++) {
        cout << v[i].second << endl;
    }


}