#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Wektor przechowujący rodziców wierzchołków
vector<int32_t> parent_node; 


// FIND: Szukanie korzenia drzewa, rekurencja
int32_t find_root(int32_t x) {
    // Jeśli wierzchołek jest korzeniem, zwróć go
    if (parent_node[x] == x) {
        return x;
    }
    
    // Kompresja ścieżki: podpinamy rekurencyjnie każdy węzeł bezpośrednio pod główny korzeń
    parent_node[x] = find_root(parent_node[x]); 
    return parent_node[x];
}

// UNION: Łączenie dwóch drzew
void union_sets(int32_t a, int32_t b) {
    int32_t root_a = find_root(a);
    int32_t root_b = find_root(b);

    // Jeśli korzenie są różne (różne zbiory), łączymy je
    if (root_a != root_b) {
        parent_node[root_a] = root_b; 
    }
    // Ciekawostka - tutaj arbitralnie drzewo a staje się poddrzewem b
    // Ale moglibyśmy to zoptymalizować, żeby mniejsze drzewo podpinać zawsze pod większe
}

int main() {
    int32_t n, m;
    cin >> n >> m;

    struct edge_type {
        int32_t start;
        int32_t destination;
        int64_t distance;
        
        bool operator<(const edge_type& other) const {
            return distance < other.distance;
        }
    };

    vector<edge_type> edges;

    for (int i = 0; i < m; i++) {
        int32_t a, b;
        int64_t c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    // DSU - (Disjoint Set Union)
    // Inicjalizacja DSU: każdy wierzchołek na początku jest swoim własnym korzeniem
    parent_node.resize(n + 1);
    for (int32_t i = 1; i <= n; i++) {
        parent_node[i] = i;
    }

    // Sortowanie krawędzi
    sort(edges.begin(), edges.end());

    // MST - Minimum Spanning Tree
    int64_t total_mst_weight = 0;
    vector<edge_type> mst_edges;

    // Główna pętla algorytmu Kruskala
    for (const auto& edge : edges) {
        // Jeśli krawędź łączy różne zbiory (nie tworzy cyklu)
        if (find_root(edge.start) != find_root(edge.destination)) {
            
            mst_edges.push_back(edge);
            total_mst_weight += edge.distance;
            
            // Scalanie zbiorów
            union_sets(edge.start, edge.destination);
        }
    }

    // Sprawdzamy, czy udało się połączyć wszystkie wierzchołki
    if (mst_edges.size() != n - 1) {
        cout << "IMPOSSIBLE\n"; 
    } else {
        cout << total_mst_weight << "\n";
    }

    return 0;
}