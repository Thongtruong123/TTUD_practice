/*
#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int, int>>> adj;
vector<int> d;
vector<int>parent;
int max_dist;
int max_edge;

void Init(vector<int>&d, vector<int>&parent){
    fill(d.begin(), d.end(), -1);
    fill(parent.begin(), parent.end(), -1);

}

void dfs(int u, vector<int>&parent){
d[u] = 0;
max_edge = u;
max_dist = 0;
for(auto& edge: adj[u]){
    if(d[edge.first] == -1){
        d[edge.first] = d[u] + edge.second;
        parent[edge.first] = u;
        if(d[edge.first] > max_dist){
                max_dist = d[edge.first];
                max_edge = edge.first;
        }
        dfs(edge.first, parent);
    }
}
}

int main(){
    cin >> n;
    adj.resize(n + 1, vector<pair<int, int>>(n + 1));
    d.resize(n + 1);
    parent.resize(n + 1);
    Init(d, parent);
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, 0);
    int s = max_edge;
    Init(d, parent);
    dfs(s, parent);
    cout << max_dist << endl;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int, int>>> adj;
vector<int> d;
vector<int> parent;
int max_dist;
int max_edge;

void Init(vector<int>& d, vector<int>& parent) {
    fill(d.begin(), d.end(), -1);
    fill(parent.begin(), parent.end(), -1);
}

void dfs(int u) {
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (d[v] == -1) {
            d[v] = d[u] + w;
            parent[v] = u;
            if (d[v] > max_dist) {
                max_dist = d[v];
                max_edge = v;
            }
            dfs(v);
        }
    }
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    d.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }


    Init(d, parent);
    d[1] = 0;
    max_dist = 0;
    dfs(1);
    int s = max_edge;

    Init(d, parent);
    d[s] = 0;
    max_dist = 0;
    dfs(s);


    cout << max_dist << endl;


    vector<int> path;
    int u = max_edge;
    while (u != -1) {
        path.push_back(u);
        u = parent[u];
    }
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}



