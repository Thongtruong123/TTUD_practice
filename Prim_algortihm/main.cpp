#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> toado;
int m;
vector<pair<int, int>> gd1;
vector<vector<int>> adj; // luu tru cac dinh ke trong m canh da xay dung

int distance_pair(pair<int, int> a, pair<int, int> b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component){
    visited[u] = true;
    component.push_back(u);
    for(int v: adj[u]){
        if(!visited[v]){
            DFS(v, adj, visited, component);
        }
    }
}

int main()
{
    cin >> n;
    toado.resize(n + 1);
    for(int i = 1 ; i <= n; i ++){
        cin >> toado[i].first >> toado[i].second;
    }
    vector<vector<int>>dis(n + 1, vector<int>(n + 1, INT_MAX));
    cin >> m;
    gd1.resize(m);
    adj.resize(n + 1, vector<int>(n + 1));
    vector<bool>visited(n + 1, false);
    for(int i = 0; i < m; i ++){
        cin >> gd1[i].first >> gd1[i].second;
        adj[gd1[i].first].push_back(gd1[i].second);
        adj[gd1[i].second].push_back(gd1[i].first);
    }

    vector<vector<int>> components;

    for(int i = 1 ; i <= n; i ++){
        if(!visited[i]){
            vector<int>component;
            DFS(i, adj, visited, component);
            components.push_back(component);
        }
    }


     cout << "So tp lien thong: " << components.size() << endl;
     int s = components.size();
     vector<vector<int>>d(s + 1, vector<int>(s + 1));
     vector<vector<pair<int, int>>>new_adj(s + 1);
     for(int i = 0; i < s; i ++){
        for(int j = 0; j < s; j ++){
            if(i == j) d[i + 1][j + 1] = 0;
            else{
                int tmp = INT_MAX;
                for(auto& u: components[i]){
                    for(auto& v: components[j]){
                        tmp = min(tmp, distance_pair(toado[u], toado[v]));
                    }
                }
                d[i + 1][j + 1] = tmp;
                new_adj[i + 1].push_back({tmp, j + 1});
                new_adj[j + 1].push_back({tmp, i + 1});
            }
        }
     }

     vector<bool>check(s + 1, false);
    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second, w = p.first;
        if(check[u]) continue;
        check[u] = true;
        ans += w;

        for(const pair<int, int>& neighbor: new_adj[u]){
            int v = neighbor.first;
            int w2 = neighbor.second;
            if(!check[v]){
                pq.push({v, w2});
            }
        }
    }

    cout <<"Cp toi thieu: " << ans << endl;



    return 0;
}
