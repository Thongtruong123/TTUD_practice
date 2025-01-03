#include <bits/stdc++.h>

using namespace std;
int n;
const int MAXN = 100005;
vector<vector<pair<int, int>>> adj;
vector<int> d(MAXN);
vector<int> N(MAXN);
vector<int>p(MAXN);
vector<int> f(MAXN);

void DFS1(int u){
    for(auto& edge: adj[u]){
        int v = edge.first;
        int w = edge.second;
        if(p[v] == 0){
            p[v] = u;
            DFS1(v);
            d[u] = d[u] + d[v] + N[v]*w;
            N[u] += N[v];
        }
    }
}

void Phase1(){
    for(int v = 1; v <= n; v++){
        p[v] = 0;
        d[v] = 0;
        N[v] = 1;
        f[v] = 0;
    }
    p[1] = 1;
    DFS1(1);
}

void DFS2(int u){
    for(auto& edge: adj[u]){
        int v = edge.first;
        int w = edge.second;
        if(p[v] == 0){
            int F = f[u] - (d[v] + N[v]*w);
            f[v] = F + d[v] + w * ( n - N[v]);
            p[v] = u;
            DFS2(v);
        }
    }

}

void Phase2(){
    for(int i = 1; i <= n; i++){
        p[i] = 0;
    }
    f[1] = d[1];
    p[1] = 1;
    DFS2(1);
}

int main()
{
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Phase1();
    Phase2();
    int max_ans = 0;
    for(int i = 1; i <= n; i++){
        if(f[i] > max_ans) max_ans = f[i];
    }
    cout << max_ans << endl;
    return 0;
}
