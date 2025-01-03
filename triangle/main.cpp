#include <bits/stdc++.h>
using namespace std;

void Try(int i, int j, vector<vector<int>>& a, int& ans, int sum) {
    // Nếu đã đến hàng cuối cùng, kiểm tra giá trị tổng
    if (i == a.size()) {
        ans = min(ans, sum);
        return;
    }

    // Di chuyển đến các chỉ số hợp lệ trong hàng dưới
    if (j < a[i].size()) {
        Try(i + 1, j, a, ans, sum + a[i][j]);    // Di chuyển xuống chỉ số j
    }
    if (j + 1 < a[i].size()) {
        Try(i + 1, j + 1, a, ans, sum + a[i][j + 1]);  // Di chuyển xuống chỉ số j + 1
    }
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int ans = INT_MAX;
    // Bắt đầu từ phần tử đầu tiên (hàng 0, cột 0)
    Try(1, 0, triangle, ans, triangle[0][0]);
    return ans;
}

int main() {
    vector<vector<int>> triangle = {{-1}, {2, 3}, {1, -1, -3}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}
