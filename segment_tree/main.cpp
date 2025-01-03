#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
vector<int> a, max_val;

int n;

// Hàm xây dựng cây đoạn
void build(int id, int L, int R) {
    if (L == R) {
        max_val[id] = a[L];
        return;
    }
    int m = (L + R) / 2;
    int LC = 2 * id;
    int RC = 2 * id + 1;
    build(LC, L, m);
    build(RC, m + 1, R);
    max_val[id] = max(max_val[LC], max_val[RC]);
}

// Hàm truy vấn giá trị lớn nhất từ nút cây phân đoạn (id, [L, R])
int getmaxfromnode(int id, int L, int R, int i, int j) {
    if (i > R || j < L) return INF;
    if (i <= L && j >= R) return max_val[id];
    int m = (L + R) / 2;
    int LC = 2 * id;
    int RC = 2 * id + 1;
    int max_left = getmaxfromnode(LC, L, m, i, j);
    int max_right = getmaxfromnode(RC, m + 1, R, i, j);
    return max(max_left, max_right);
}

int Getmax(int i, int j) {
    return getmaxfromnode(1, 1, n, i, j);
}

// Hàm cập nhật giá trị tại a[index] = value từ nút cây phân đoạn (id, [L, R])
void updatefromnode(int id, int L, int R, int index, int value) {
    if (L > R) return;
    if (index < L || index > R) return;
    if (R == L) {
        max_val[id] = value;
        return;
    }
    int m = (L + R) / 2;
    int LC = id * 2;
    int RC = id * 2 + 1;
    updatefromnode(LC, L, m, index, value);
    updatefromnode(RC, m + 1, R, index, value);

    // Sau khi cập nhật, giá trị tại nút hiện tại sẽ là giá trị lớn nhất của hai con
    max_val[id] = max(max_val[LC], max_val[RC]);
}

void Update(int i, int v) {
    updatefromnode(1, 1, n, i, v); // Bắt đầu cập nhật từ nút gốc (id=1)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    a.resize(n + 1);
    max_val.resize(4 * n, INF);

    // Đọc dãy ban đầu
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Xây dựng cây đoạn từ dãy ban đầu
    build(1, 1, n);

    int m;
    cin >> m;

    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        if (s == "get-max") {
            int x, y;
            cin >> x >> y;
            // In ra kết quả truy vấn
            cout << Getmax(x, y) << endl;
        }
        if (s == "update") {
            int index, value;
            cin >> index >> value;
            // Cập nhật giá trị tại vị trí index
            Update(index, value);
        }
    }

    return 0;
}
