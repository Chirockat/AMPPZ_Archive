#include <iostream>

using namespace std;

int main() {
    int32_t n,m;
    cin >> n >> m;

    pair<int,int> point_A;

    char map [n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map [i][j];
            if (map [i][j] == 'A') {
                point_A.first = i;
                point_A.second = j;
            }
        }
    }

    while (1) {
        
    }

    
}