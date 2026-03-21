#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// Reprezentacja "nieskończoności" na potrzeby początkowych odległości
const int INF = 1e9;

// Wektory przesunięć i odpowiadające im znaki: Góra, Dół, Lewo, Prawo
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char dir_char[] = {'U', 'D', 'L', 'R'};

int main() {

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    int start_row = -1, start_col = -1;
    int end_row = -1, end_col = -1;

    // Wczytywanie mapy i lokalizacja punktów A i B
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                start_row = i;
                start_col = j;
            } else if (grid[i][j] == 'B') {
                end_row = i;
                end_col = j;
            }
        }
    }

    // Tablice do algorytmu: odległości i wykonany ruch 
    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<char>> move(n, vector<char>(m, ' '));

    // {odległość, {wiersz, kolumna}}
    set<pair<int, pair<int, int>>> q;

    // Inicjalizacja punktu startowego
    dist[start_row][start_col] = 0;
    q.insert({0, {start_row, start_col}});

    // Główna pętla algorytmu Dijkstry
    while (!q.empty()) {
        // Pobieramy wierzchołek o najmniejszej odległości z początku zbioru
        auto it = q.begin();
        int d = it->first;
        int row = it->second.first;
        int col = it->second.second;
        q.erase(it);

        // Jeśli dotarliśmy do celu, możemy przerwać szukanie (optymalizacja)
        if (row == end_row && col == end_col) break;

        // Sprawdzamy 4 sąsiednie pola
        for (int i = 0; i < 4; ++i) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            // Czy nowe pole jest w granicach mapy i nie jest ścianą?
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] != '#') {
                
                // Sprawdzamy czy nowy dystans jest lepszy niż stary
                // Tak na prawdę ma to sens tylko dla jednej iteracji, ale już zostawmy
                if (dist[row][col] + 1 < dist[new_row][new_col]) {
                    
                    // Jeśli wierzchołek był już w secie z gorszym wynikiem, usuwamy go
                    if (dist[new_row][new_col] != INF) {
                        q.erase({dist[new_row][new_col], {new_row, new_col}});
                    }
                    
                    // Aktualizujemy dane (zapisujemy tylko odległość i jaki ruch tu wykonalismy)
                    dist[new_row][new_col] = dist[row][col] + 1;
                    move[new_row][new_col] = dir_char[i];
                    
                    // Wstawiamy zaktualizowany wierzchołek do seta
                    q.insert({dist[new_row][new_col], {new_row, new_col}});
                }
            }
        }
    }

    // Sprawdzanie wyniku i wypisywanie wyjścia
    if (dist[end_row][end_col] == INF) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << dist[end_row][end_col] << "\n";
        
        // Odtwarzanie ścieżki od tyłu na podstawie  tablicy move
        string path = "";
        int curr_r = end_row;
        int curr_c = end_col;
        
        while (curr_r != start_row || curr_c != start_col) {
            char last_move = move[curr_r][curr_c];
            path += last_move;
            
            
            if (last_move == 'U') curr_r++;      
            else if (last_move == 'D') curr_r--; 
            else if (last_move == 'L') curr_c++; 
            else if (last_move == 'R') curr_c--; 
        }
        
        // Odwracamy string
        reverse(path.begin(), path.end());
        cout << path << "\n";
    }

    


    // // --- SEKCJA DEBUGOWANIA ---
    // cout << "\n=== DEBUG: ZAWARTOSC TABLIC ===\n";

    // cout << "\n1. Tablica DIST (Odleglosci):\n";
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         if (dist[i][j] == INF) cout << " . "; // Nieodwiedzone/sciana
    //         else cout << (dist[i][j] < 10 ? " " : "") << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n2. Tablica MOVE (Skad przyszlismy - kierunek):\n";
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         if (grid[i][j] == '#') cout << " # ";
    //         else if (move[i][j] == ' ') cout << " . ";
    //         else cout << " " << move[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    

    return 0;
}