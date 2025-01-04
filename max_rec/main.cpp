#include <bits/stdc++.h>
using namespace std;

// Hàm tính diện tích lớn nhất trong histogram
int maxHistogramArea(vector<int> &heights) {
    int m = heights.size();
    vector<int> R(m), L(m);
    stack<int> s;

    // Tính toán ranh giới phải (right limit)
    for (int i = 0; i < m; i++) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            R[s.top()] = i; // Gán ranh giới phải
            s.pop();
        }
        s.push(i);
    }
    // Pop các phần còn lại trong stack (ranh giới phải là cuối cùng)
    while (!s.empty()) {
        R[s.top()] = m;
        s.pop();
    }

    // Tính toán ranh giới trái (left limit)
    for (int i = m - 1; i >= 0; i--) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            L[s.top()] = i; // Gán ranh giới trái
            s.pop();
        }
        s.push(i);
    }
    // Pop các phần còn lại trong stack (ranh giới trái là đầu tiên)
    while (!s.empty()) {
        L[s.top()] = -1;
        s.pop();
    }

    // Tính diện tích lớn nhất
    int maxArea = 0;
    for (int i = 0; i < m; i++) {
        int width = R[i] - L[i] - 1; // Tính chiều rộng
        maxArea = max(maxArea, heights[i] * width); // Tính diện tích
    }

    return maxArea;
}

// Hàm tìm diện tích hình chữ nhật lớn nhất trong ma trận nhị phân
int hcn_largest(vector<vector<int>> &matrix) {
    if (matrix.empty()) return 0; // Nếu ma trận rỗng, trả về 0

    int n = matrix.size(); // Số hàng
    int m = matrix[0].size(); // Số cột
    vector<int> heights(m, 0); // Mảng chiều cao
    int max_area = 0; // Biến để lưu diện tích lớn nhất

    // Cập nhật chiều cao cho từng hàng
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Cập nhật chiều cao cho histogram
            if (matrix[i][j] == 1) {
                heights[j] += 1; // Tăng chiều cao
            } else {
                heights[j] = 0; // Reset chiều cao
            }
        }
        // Tìm diện tích lớn nhất trong histogram tại hàng i
        max_area = max(max_area, maxHistogramArea(heights));
    }
    return max_area;
}

int main() {
    int n, m;
    cin >> n >> m; // Đọc kích thước của ma trận
    vector<vector<int>> matrix(n, vector<int>(m)); // Khởi tạo ma trận nhị phân

    // Đọc ma trận nhị phân
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // In ra diện tích lớn nhất của hình chữ nhật chứa toàn bộ ô đen
    cout << hcn_largest(matrix) << endl;
    return 0;
}
