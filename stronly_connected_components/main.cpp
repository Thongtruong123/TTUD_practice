#include <bits/stdc++.h>

using namespace std;

int N, M;

void DFS(int u, vector<vector<int>>& adj, vector<int>& visited, stack<int>& Stack) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, adj, visited, Stack);
        }
    }
    Stack.push(u);
}

void DFS_reverse(int u, vector<vector<int>>& adjT, vector<int>& visited) {
    visited[u] = 1;
    for (int v : adjT[u]) {
        if (!visited[v]) {
            DFS_reverse(v, adjT, visited);
        }
    }
}

int main() {
    cin >> N >> M;


    vector<vector<int>> adj(N + 1), adjT(N + 1);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adjT[y].push_back(x);
    }


    stack<int> Stack;
    vector<int> visited(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            DFS(i, adj, visited, Stack);
        }
    }


    fill(visited.begin(), visited.end(), 0);
    int ans = 0;
    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v]) {
            ans++;
            DFS_reverse(v, adjT, visited);
        }
    }

    cout << ans << endl;
    return 0;
}
