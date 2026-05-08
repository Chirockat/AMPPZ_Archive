#include<iostream>
#include<vector>

using namespace std;

int main() {
    int16_t n;
    cin >> n;

    // wektor wejsciowy
    vector <vector<char>> grid(n, vector<char>(n));
    char c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            grid[i][j] = c;
        }
    }

    // wektor do przechowywania liczby sciezek dojscia do danego punktu (wypeniany dynamicznie)
    vector <vector<int32_t>> dp_grid(n, vector<int32_t>(n, 0));

    if (grid[0][0] == '*') {
        cout << 0 << endl;
        exit(0);
    }

    dp_grid[0][0] = 1;
    const int32_t MOD = 1000000007;
    

    // pierwszy wiersz wypelniamy osobno
    for (int j = 1; j < n; j++) {
        if (grid[0][j] == '*') {
            break;
        }    
        else {
            dp_grid[0][j] = dp_grid[0][j-1];
        }    
    }

    // pierwsza kolumne tez
    for (int i = 1; i < n; i++) {
        if (grid[i][0] == '*') {
            break;
        }    
        else {
            dp_grid[i][0] = dp_grid[i-1][0];
        }    
    }


    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == '*') {
                continue;
            }
            else {
                dp_grid[i][j] = (dp_grid[i - 1][j] + dp_grid[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp_grid[n-1][n-1] << endl;

    // sprawdzanie macierzy dp

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            cout << dp_grid[i][j] << ',';
        }
        cout << endl;
    }

}