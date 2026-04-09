#include<iostream>
#include<vector>

using namespace std;

int main () {
    int32_t n, m;

    cin >> n >> m;

    vector<vector<pair<int32_t, int64_t>>> neighborhood_list(n + 1);

    int32_t a, b;
    int64_t c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        
        neighborhood_list[a].push_back(make_pair(b, c));
    }
}