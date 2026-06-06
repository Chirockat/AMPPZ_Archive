#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

vector <int32_t> parent_node;
vector <int32_t> component_size; // NOWE: Wektor przechowujący rozmiar każdej wyspy

int find_root(int32_t x) {
    if (parent_node[x] == x) {
        return x;
    }
    parent_node[x] = find_root(parent_node[x]);
    return parent_node[x];
}

int main() {

    int32_t n, m;
    cin >> n >> m;

    parent_node.resize(n + 1);
    component_size.resize(n + 1); 

    for (int i = 1; i <= n; i++) {
        parent_node[i] = i;
        component_size[i] = 1; 
    }

    int32_t components_count = n;
    int32_t max_size = 1;

    for (int i = 0; i < m; i++) {
        int32_t a, b;
        cin >> a >> b;
        
        int32_t root_a = find_root(a);
        int32_t root_b = find_root(b);

        // Jeśli miasta są z różnych wysp, łączymy je
        if (root_a != root_b) {
            
            // Zmieniamy Union - podpinamy drzewo mniejsze pod wieksze
            if (component_size[root_a] < component_size[root_b]) {
                parent_node[root_a] = root_b;
                component_size[root_b] += component_size[root_a]; // Powiększamy wyspę B
                max_size = max(max_size, component_size[root_b]); // Sprawdzamy, czy mamy nowy rekord
            } else {
                parent_node[root_b] = root_a;
                component_size[root_a] += component_size[root_b]; // Powiększamy wyspę A
                max_size = max(max_size, component_size[root_a]); // Sprawdzamy, czy mamy nowy rekord
            }

            components_count--; 
        }

        cout << components_count << " " << max_size << "\n";
    }
    
    return 0;
}