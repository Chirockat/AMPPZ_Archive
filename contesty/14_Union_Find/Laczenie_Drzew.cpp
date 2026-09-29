#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Mamy rozrzucone miasta i drogi, mamy je połączyć jak najmniejszym kosztem
// Wypisujemy ile krawędzi brakuje, po czym wypisujemy przykładowe rozwiązania

vector <int32_t> parent_node;


int32_t find_root(int32_t x) {
    if (parent_node[x] == x) {
        return x;
    }

    parent_node[x] = find_root(parent_node[x]);
    return parent_node[x];
}

void union_sets(int32_t a, int32_t b) {
    int32_t root_a = find_root(a);
    int32_t root_b = find_root(b);

    if (root_a != root_b) {
        parent_node[root_a] = root_b;
    }
}

int main() {
    int32_t n, m;
    cin >> n >> m;

    struct edge_type {
        int32_t start;
        int32_t destination;
    };

    vector <edge_type> edges;

    for (int i = 0; i < m; i++) {
        int32_t a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    set <int32_t> unique_roots;
    parent_node.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        parent_node[i] = i;
    }

    // Tyle zostało z naszej pętli charakterystycznej dla Kruskala
    // Tu po prostu łączymy istniejące krawędzie w jak największe drzewa
    for (const auto& edge:edges) {
        union_sets(edge.start, edge.destination);
    }

    // wrzucamy do zbioru wszystkie korzenie
    // struktura taka zeby były unikalne
    for (int i = 1; i <=n; i++) {
        unique_roots.insert(find_root(i));  
        // Myślałem wcześniej żeby wkładać od razu parent_node(i), 
        // ale nie zawsze zadziałało by to poprawnie
    }
    
    cout << unique_roots.size() - 1 << endl;

    int32_t previous_root = -1;

    for (int32_t current_root : unique_roots) {
        if (previous_root != -1) {
            // Jeśli mamy już poprzedni korzeń, wypisujemy drogę między nim a obecnym
            cout << previous_root << " " << current_root << "\n";
        }

        previous_root = current_root;
    }

}