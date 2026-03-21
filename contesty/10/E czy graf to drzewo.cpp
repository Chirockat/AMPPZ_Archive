#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int num_nodes, num_edges;
    if (!(cin >> num_nodes >> num_edges)) return 0;

    // lista sąsiedztwa 
    vector<vector<int>> adjacency_list(num_nodes + 1);

    // Wczytywanie krawędzi
    for (int i = 0; i < num_edges; ++i) {
        int node_u, node_v;
        cin >> node_u >> node_v;
        
        // Graf jest nieskierowany, więc dodajemy połączenie w obie strony
        adjacency_list[node_u].push_back(node_v);
        adjacency_list[node_v].push_back(node_u);
    }

    // Drzewo musi mieć liczbę krawędzi równą liczba wierzchołków - 1
    if (num_edges != num_nodes - 1) {
        cout << "NO\n";
        return 0;
    }

    // Tablica do śledzenia, które wierzchołki już odwiedziliśmy
    vector<bool> is_visited(num_nodes + 1, false);
    
    // Kolejka do algorytmu BFS
    queue<int> nodes_queue;

    // Zaczynamy sprawdzanie od wierzchołka numer 1
    nodes_queue.push(1);
    is_visited[1] = true;
    
    int visited_count = 0;

    // Główna pętla BFS
    while (!nodes_queue.empty()) {
        int current_node = nodes_queue.front();
        nodes_queue.pop();
        
        visited_count++; 

        // Przeglądamy wszystkich sąsiadów aktualnego wierzchołka
        for (int neighbor : adjacency_list[current_node]) {
            if (!is_visited[neighbor]) {
                is_visited[neighbor] = true;
                nodes_queue.push(neighbor);
            }
        }
    }


    if (visited_count == num_nodes) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


    return 0;
}