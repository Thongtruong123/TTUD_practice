#include <bits/stdc++.h>
using namespace std;

int dp[101][101][101];
vector<vector<int>> desired;
set<vector<int>> desired_set;

// Kiểm tra xem một khối có phải là khối mong muốn không
bool is_desired_block(int l, int w, int h) {
    vector<int> block = {l, w, h};
    sort(block.begin(), block.end());
    do {
        if (desired_set.count({block[0], block[1], block[2]}))
            return true;
    } while (next_permutation(block.begin(), block.end()));
    return false;
}

// Hàm tính thể tích lãng phí tối thiểu
int solve(int l, int w, int h) {
    if (l == 0 || w == 0 || h == 0) return 0;
    if (dp[l][w][h] != -1) return dp[l][w][h];

    // Nếu khối hiện tại là khối mong muốn
    if (is_desired_block(l, w, h))
        return dp[l][w][h] = 0;

    int ans = l * w * h; // Trường hợp xấu nhất: toàn bộ là lãng phí

    // Thử cắt theo chiều dài
    for (int i = 1; i < l; i++)
        ans = min(ans, solve(i, w, h) + solve(l-i, w, h));

    // Thử cắt theo chiều rộng
    for (int i = 1; i < w; i++)
        ans = min(ans, solve(l, i, h) + solve(l, w-i, h));

    // Thử cắt theo chiều cao
    for (int i = 1; i < h; i++)
        ans = min(ans, solve(l, w, i) + solve(l, w, h-i));

    return dp[l][w][h] = ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int L, W, H, N;
        cin >> L >> W >> H >> N;

        // Reset for new test case
        desired.clear();
        desired_set.clear();
        memset(dp, -1, sizeof(dp));

        // Read desired blocks
        for (int i = 0; i < N; i++) {
            int l, w, h;
            cin >> l >> w >> h;
            vector<int> block = {l, w, h};
           // sort(block.begin(), block.end());
            desired_set.insert(block);
            desired.push_back({l, w, h});
        }

        cout << solve(L, W, H) << endl;
    }
    return 0;
}
