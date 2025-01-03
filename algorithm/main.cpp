#include<bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n;
int graph[MAX][MAX];
bool visited[MAX];
int smin = INT_MAX;

void tsp(int current_pos, int k, int current_wei, int min_cost) {
    if (k == n && graph[current_pos][0]) {
        smin = min(smin, current_wei + graph[current_pos][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[current_pos][i]) {
            int new_wei = current_wei + graph[current_pos][i];

            // Tính toán min cost cho các đỉnh còn lại
            int remaining = n - k - 1;
            int new_mincost = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && graph[current_pos][j]) {
                    new_mincost = min(new_mincost, graph[current_pos][j]);
                }
            }

            if (new_wei + remaining * new_mincost < smin) {
                visited[i] = true;
                tsp(i, k + 1, new_wei, new_mincost);
                visited[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;
    cout << "Nhap ma tran trong so:";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) graph[i][j] = INT_MAX;  // Nếu không có cạnh, trọng số được xem là vô cực
        }
    }

    fill(visited, visited + n, false);
    visited[0] = true;

    tsp(0, 1, 0, 0);

    if (smin == INT_MAX) {
        cout << "Khong co chu trinh Hamilton" << endl;
    } else {
        cout << "Chu trinh Hamilton co tong trong so nho nhat la: " << smin << endl;
    }

    return 0;
}
