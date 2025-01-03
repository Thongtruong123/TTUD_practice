#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

struct Edge {
    int v, capacity, flow;
    Edge(int v, int capacity) : v(v), capacity(capacity), flow(0) {}
};

vector<vector<int>> adj;
vector<Edge> edges;
vector<int> parent;

void addEdge(int u, int v, int capacity) {
    adj[u].push_back(edges.size());
    edges.emplace_back(v, capacity);

    adj[v].push_back(edges.size());
    edges.emplace_back(u, 0);
}

bool bfs(int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    queue<int> q;
    q.push(s);
    parent[s] = -2;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int id : adj[u]) {
            Edge &e = edges[id];
            if (parent[e.v] == -1 && e.flow < e.capacity) {
                parent[e.v] = id;
                if (e.v == t) return true;
                q.push(e.v);
            }
        }
    }
    return false;
}

int maxFlow(int s, int t, int n) {
    int flow = 0;
    parent.resize(n);

    while (bfs(s, t)) {
        int path_flow = INF;
        for (int v = t; v != s; ) {
            int id = parent[v];
            path_flow = min(path_flow, edges[id].capacity - edges[id].flow);
            v = edges[id ^ 1].v;
        }

        for (int v = t; v != s; ) {
            int id = parent[v];
            edges[id].flow += path_flow;
            edges[id ^ 1].flow -= path_flow;
            v = edges[id ^ 1].v;
        }
        flow += path_flow;
    }
    return flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, s, t;
    cin >> N >> M;
    cin >> s >> t;

    adj.resize(N);

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        addEdge(u - 1, v - 1, c);
    }

    cout << maxFlow(s - 1, t - 1, N) << endl;

    return 0;
}
