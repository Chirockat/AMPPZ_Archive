#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int16_t n;
    int32_t m, q;

    int16_t a,b;
    int64_t c;

    const int64_t INF = 1e18;

    
    cin >> n >> m >> q;

    // tutaj musi być macierz sąsiedztwa, w przeciwieństwie do Dijkstry
    // robimy na wektorach, bo łatwiej jest inicjalizować INF w ten sposób
    vector<vector<int64_t>> adj_matrix(n + 1, vector<int64_t> (n + 1, INF));


    for (int i = 1; i <= n; i++) {
        adj_matrix[i][i] = 0;
    }

    // wypełniamy macierz, juz tutaj dbamy zeby wpisac jak najkrotsza krawedz, inne nas nie interesuja
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (adj_matrix[a][b] > c) {
            adj_matrix[a][b] = c;
            adj_matrix[b][a] = c;
        }
        
    }


    for (int k = 1; k <= n ; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
                adj_matrix[j][i] = adj_matrix[i][j];
            }
        }
    }


    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (adj_matrix[a][b] == INF) {
            cout << -1 << endl;
        }
        else {
            cout << adj_matrix[a][b] << endl;
        }
        
    }

}