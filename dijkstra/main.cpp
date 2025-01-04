#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1e6 + 5; // so dinh toi da

vector<pair<int, int>> adj[MAXN];
vector<int> dist(MAXN, INF); // khoang cach tu nguon
vector<int> parent(MAXN, -1);

void dijkstra(int start, int n){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
    int u = pq.top().second;
    int w = pq.top().first;
    pq.pop();
    if(w > dist[u]) continue;
    for(auto edge: adj[u]){
        int v = edge.first;
        int w_u = edge.second;

        if(dist[u] + w_u < dist[v]){
            dist[v] = dist[u] + w_u;
            pq.push({dist[v], v});
            parent[v] = u;
        }
    }
    }
}

vector<int> get_path(int start, int end){
    vector<int> path;
    if(dist[end] == INF) return path;
    for(int v = end; v != -1; v = parent[v]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int n, m, start;
    cin >> n >> m >> start;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Đồ thị vô hướng
    }

    dijkstra(start, n);

    // Xuất khoảng cách từ đỉnh start đến mọi đỉnh
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;

    // Ví dụ in đường đi từ start đến đỉnh n
    vector<int> path = get_path(start, n);
    if (path.empty()) cout << "No path\n";
    else {
        for (int v : path) cout << v << " ";
        cout << endl;
    }
    return 0;
}
