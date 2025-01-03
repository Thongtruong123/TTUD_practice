#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Cấu trúc cạnh, chứa đỉnh và trọng số
struct Edge {
    int v, weight;
    bool operator>(const Edge& other) const {
        return weight > other.weight; // Để tạo đống ưu tiên theo trọng số tăng dần
    }
};

int main() {
    int n, m; // n: số đỉnh, m: số cạnh
    cin >> n >> m;

    // Danh sách kề để lưu các cạnh
    vector<vector<Edge>> adj(n + 1);

    // Nhập các cạnh
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Đồ thị vô hướng
    }

    vector<bool> inMST(n + 1, false); // Mảng đánh dấu đỉnh đã có trong MST
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Đống ưu tiên (min-heap)

    int totalWeight = 0; // Tổng trọng số của MST
    pq.push({1, 0}); // Bắt đầu từ đỉnh 1, trọng số ban đầu là 0

    while (!pq.empty()) {
        // Lấy đỉnh có trọng số nhỏ nhất từ đống
        Edge e = pq.top();
        pq.pop();

        int u = e.v;
        if (inMST[u]) continue; // Nếu đỉnh đã có trong MST, bỏ qua

        inMST[u] = true; // Đánh dấu đỉnh u là đã có trong MST
        totalWeight += e.weight; // Cộng trọng số của cạnh vào tổng trọng số

        // Thêm tất cả các cạnh nối từ u đến các đỉnh chưa có trong MST vào đống ưu tiên
        for (const Edge& neighbor : adj[u]) {
            int v = neighbor.v;
            if (!inMST[v]) {
                pq.push(neighbor); // Thêm cạnh vào đống ưu tiên
            }
        }
    }

    // In tổng trọng số của cây khung
    cout << "Trọng số của cây khung có trọng số nhỏ nhất: " << totalWeight << endl;
    return 0;
}
