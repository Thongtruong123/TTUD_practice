#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// Cấu trúc để lưu cạnh
struct Edge {
    int to, weight;
};

// Biến toàn cục
vector<vector<Edge>> adj; // Danh sách kề
vector<int> d;            // Khoảng cách từ nút bắt đầu
int farthest_node;        // Đỉnh xa nhất được tìm thấy

// Hàm khởi tạo
void Init(int n) {
    d.assign(n, -1); // Đặt tất cả khoảng cách bằng -1
}

// DFS để tìm đỉnh xa nhất từ một đỉnh u
void DFS(int u) {
    for (auto edge : adj[u]) { // Duyệt tất cả các cạnh kề
        int v = edge.to;
        int w = edge.weight;
        if (d[v] < 0) { // Chưa thăm đỉnh này
            d[v] = d[u] + w; // Cập nhật khoảng cách
            DFS(v);          // Đệ quy DFS từ đỉnh v
        }
    }
}

// Hàm tìm đường đi dài nhất
void LongestPathOnTree(int n) {
    // Bước 1: Chọn một đỉnh s bất kỳ
    Init(n);
    d[0] = 0;  // Bắt đầu từ đỉnh 0
    DFS(0);    // Tìm đỉnh xa nhất từ đỉnh 0

    // Bước 2: Tìm đỉnh xa nhất x từ s
    farthest_node = max_element(d.begin(), d.end()) - d.begin();

    // Bước 3: Tìm đỉnh xa nhất y từ x
    Init(n);
    d[farthest_node] = 0;
    DFS(farthest_node);
    int y = max_element(d.begin(), d.end()) - d.begin();

    // Bước 4: Độ dài đường kính
    cout << "Chiều dài đường đi dài nhất là: " << d[y] << endl;
}

int main() {
    int n;
    cout << "Nhập số đỉnh: ";
    cin >> n;

    adj.resize(n);

    cout << "Nhập các cạnh (u, v, w):\n";
    for (int i = 0; i < n - 1; i++) { // Cây có n đỉnh sẽ có n-1 cạnh
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; // Chuyển về chỉ số 0-based nếu nhập từ 1

        // Thêm cạnh vào danh sách kề
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Gọi hàm tìm đường đi dài nhất
    LongestPathOnTree(n);

    return 0;
}
