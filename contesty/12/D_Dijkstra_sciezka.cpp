#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>

using namespace std;

int main() {
    int32_t n, m;
    const int64_t INF = 1e18;

    cin >> n >> m;

    // lista sasiedztwa
    vector<vector<pair<int32_t, int64_t>>> neighborhood_list(n + 1);

    // tablica dystansow
    vector<int64_t> dist_list(n + 1, INF);

    // tablica poprzednikow, domyślnie wypełniona -1
    vector<int32_t> parent_list(n + 1, -1);
    

    // kolejka priorytetowa
    // Skomplikowanie to wyglada, glownie dlatego ze sortujemy po 
    // najmniejszej odleglosci w miare wstawiania do kolejki
    priority_queue< pair<int64_t, int32_t>, vector<pair<int64_t, int32_t>>, greater<pair<int64_t, int32_t>> > pq;

    int32_t a, b;
    int64_t c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        neighborhood_list[a].push_back(make_pair(b, c));
        neighborhood_list[b].push_back(make_pair(a, c));
    }
    
    //testowe wypisywanie listy sasiedztwa

    /*
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto p : neighborhood_list[i]) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
    */

    dist_list[1] = 0;
    pq.push({ 0,1 });

    while (!pq.empty()) {
        int64_t current_dist = pq.top().first;
        int32_t current_city = pq.top().second;

        pq.pop();

        if (current_dist > dist_list[current_city]) {
            continue;
        }

        for (auto edge : neighborhood_list[current_city]) {
            int32_t neighbor_city = edge.first;
            int64_t travel_cost = edge.second;

            int64_t new_route_dist = current_dist + travel_cost;

            if (new_route_dist < dist_list[neighbor_city]) {
                dist_list[neighbor_city] = new_route_dist;
                parent_list[neighbor_city] = current_city;

                pq.push({ new_route_dist, neighbor_city });

            }
        }


        
    }

    if (dist_list[n] == INF) {
    cout << -1 << endl;
    } 
    
    else {
    vector<int32_t> path;
    int32_t curr = n; 
    
    while (curr != -1) {
        path.push_back(curr);
        curr = parent_list[curr]; 
    }
    
    reverse(path.begin(), path.end());
    
    for (int32_t city : path) {
        cout << city << " ";
    }

    cout << endl;
    
    }

}