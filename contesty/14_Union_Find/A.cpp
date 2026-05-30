#include <iostream>
#include <vector>

using namespace std;

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

}