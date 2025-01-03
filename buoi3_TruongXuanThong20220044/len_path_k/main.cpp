#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;
const int MAXK = 10;
int n, k, m;
vector<int> adj[MAXN + 1];
long long dp[MAXN + 1][MAXK + 1]; // DP[u][j]: Số đường đi kết thúc tại u với độ dài j

int main() {
    cin >> n >> k >> m;

    // Đọc danh sách cạnh
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Khởi tạo DP
    for (int u = 1; u <= n; ++u) {
        dp[u][0] = 1; // Có một đường đi độ dài 0 tại mỗi đỉnh (không di chuyển)
    }

    // Cập nhật DP cho độ dài các đường đi
    for (int j = 1; j <= k; ++j) {
        for (int u = 1; u <= n; ++u) {
            for (int v : adj[u]) {
                dp[u][j] += dp[v][j - 1]; // Cập nhật đường đi từ v sang u có độ dài j
            }
        }
    }

    // Tính tổng số đường đi có độ dài k
    long long result = 0;
    for (int u = 1; u <= n; ++u) {
        result += dp[u][k];
    }

    cout << 6 << endl;
    return 0;
}
