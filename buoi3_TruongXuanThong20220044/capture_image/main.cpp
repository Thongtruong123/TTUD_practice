#include <bits/stdc++.h>

using namespace std;

//Truong Xuan Thong 20220044
const int INF = 1e9;
int n, r;
vector<vector<int>> dist;
vector<int> place;
vector<bool> visited;
int min_cost;

void solve(int idx, int current_cost, int start, int end, int count) {
    if (idx == count) {
        if (dist[place[idx - 1]][end] > 0) {
            min_cost = min(min_cost, current_cost + dist[place[idx - 1]][end]);
        }
        return;
    }

    for (int i = 1; i < count - 1; ++i) {
        if (!visited[place[i]] && dist[place[idx - 1]][place[i]] > 0) {
            visited[place[i]] = true;
            solve(idx + 1, current_cost + dist[place[idx - 1]][place[i]], start, end, count);
            visited[place[i]] = false;
        }
    }
}

int main() {
    cin >> n >> r;  // Nhập số lượng điểm và số người tham quan
    dist.resize(n + 1, vector<int>(n + 1));

    // Nhập ma trận chi phí đi lại giữa các địa điểm
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> dist[i][j];
        }
    }


    while (r--) {
        string line;
        getline(cin >> ws, line);

        stringstream ss(line);
        place.clear();

        int x;
        while (ss >> x) {
            place.push_back(x);
        }

        int start = place.front();
        int end = place.back();
        int count = place.size();

        visited.assign(n + 1, false);
        min_cost = INF;

        visited[start] = true;
        solve(1, 0, start, end, count);

        if (min_cost == INF) {
            cout << 0 << endl;
        } else {
            cout << min_cost << endl;
        }
    }

    return 0;
}
