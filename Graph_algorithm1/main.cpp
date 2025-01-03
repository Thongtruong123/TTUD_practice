#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cur_num = 0;
vector<vector<int>> adj;
vector<pair<int, int>> bridges;
vector<int> num, low;
vector<bool> joint;
void Analyze(int v, int parent) {
    int child = 0;
    num[v] = low[v] = cur_num++;

    for (auto& u : adj[v]) {
        if (u == parent) continue;
        if (num[u] == -1) {
            Analyze(u, v);
            child++;

            low[v] = min(low[v], low[u]);

            if (parent == -1 && child > 1)
                joint[v] = true;
            else if (parent != -1 && low[u] >= num[v])
                joint[v] = true;


            if (low[u] > num[v])
                bridges.push_back({v, u});
        } else {

            low[v] = min(low[v], num[u]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    num.assign(n + 1, -1);
    low.assign(n + 1, -1);
    joint.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (num[i] == -1) {
            Analyze(i, -1);
        }
    }

    int joint_count = 0;
    for (int i = 1; i <= n; i++) {
        if (joint[i]) joint_count++;
    }

    cout  << joint_count << endl;
    cout << bridges.size() << endl;

    return 0;
}
