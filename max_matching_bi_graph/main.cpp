#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10010;

int n, m;
vector<int> adj[MAXN];  // Danh sách kề, lưu các nhân viên có thể làm công việc i
int match[MAXN];  // Mảng lưu nhân viên đã được phân công cho mỗi công việc
bool visited[MAXN];  // Mảng đánh dấu nhân viên đã được kiểm tra trong DFS

// Hàm DFS tìm kiếm match tối đa
bool dfs(int task) {
    for (int staff : adj[task]) {
        if (!visited[staff]) {
            visited[staff] = true;  // Đánh dấu nhân viên này đã được kiểm tra
            if (match[staff] == -1 || dfs(match[staff])) {
                match[staff] = task;
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Đọc vào n và m
    cin >> n >> m;

    // Khởi tạo mảng match cho các nhân viên chưa được phân công công việc nào
    memset(match, -1, sizeof(match));

    // Đọc các công việc và danh sách nhân viên có thể làm mỗi công việc
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        adj[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> adj[i][j];
        }
    }

    // Tìm số lượng công việc tối đa có thể phân công
    int max_tasks = 0;
    for (int task = 1; task <= n; task++) {
        memset(visited, false, sizeof(visited));  // Reset mảng visited cho mỗi công việc
        if (dfs(task)) {
            max_tasks++;
        }
    }

    // In ra kết quả
    cout << max_tasks << endl;

    return 0;
}
