#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Minimalne drzewo rozpinajace, Kruskal

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ZBIÓR ROZŁĄCZNYCH
vector<int32_t> parent_node; 

// Operacja FIND: Szukanie głównego szefa z "kompresją ścieżki"
int32_t find_set(int32_t x) {
    // Jeśli wierzchołek jest swoim własnym szefem, to znaczy, że dotarliśmy na sam szczyt
    if (parent_node[x] == x) {
        return x;
    }
    
    // Jeśli nie, pytamy szefa wyżej. 
    // Magia kompresji ścieżki: od razu zapisujemy wynik w parent_node[x]!
    parent_node[x] = find_set(parent_node[x]); 
    
    return parent_node[x];
}

// 3. Operacja UNION: Łączenie dwóch zbiorów
void union_sets(int32_t a, int32_t b) {
    // Znajdujemy głównych szefów dla obu wierzchołków
    int32_t boss_a = find_set(a);
    int32_t boss_b = find_set(b);

    // Jeśli szefowie są różni, to wierzchołki są w różnych zbiorach
    if (boss_a != boss_b) {
        // Łączymy je: jeden szef staje się podwładnym drugiego
        parent_node[boss_a] = boss_b; 
    }
}



int main() {
    int32_t n, m;
    cin >> n >> m;

    struct edge_type {
        int32_t start;
        int32_t destination;
        int64_t distance;
    };

    vector <edge_type> all_edges;

    // ponoc dla Kruskala nie ma znaczenia ze drzewo jest nieskierowane, wiec wczytujemy krawedz tylko raz
    for (int i = 0; i < m; i++) {
        int32_t a,b;
        int64_t c;
        cin >> a >> b >> c;

        all_edges.push_back(edge_type{a, b, c});  
    }

    vector <edge_type> selected_edges;

    // Zbiór Rozłącznych?
    vector <int32_t> parent(n + 1);

    
}