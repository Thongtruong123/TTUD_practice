#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K1, K2;

int main() {
    cin >> N >> K1 >> K2;

    // Mảng dp[i][0] chứa các chuỗi kết thúc ở ngày i bằng nghỉ
    // Mảng dp[i][1] chứa các chuỗi kết thúc ở ngày i bằng làm việc
    vector<vector<vector<string>>> dp(N + 1, vector<vector<string>>(2));
    dp[0][0].push_back("");
    dp[0][1].push_back("");

    for (int i = 1; i <= N; ++i) {
        // Nếu ngày i là ngày nghỉ, thì ngày trước đó phải là ngày làm việc
        for (const string &prev : dp[i - 1][1]) {
            dp[i][0].push_back(prev + "0");
        }

        // Nếu ngày i là ngày làm việc, xét các đoạn làm việc có độ dài từ K1 đến K2
        for (int j = K1; j <= K2; ++j) {
            if (i - j >= 0) {
                for (const string &prev : dp[i - j][0]) {
                    dp[i][1].push_back(prev + string(j, '1'));
                }
            }
        }
    }

    vector<string> ans;
    ans.insert(ans.end(), dp[N][0].begin(), dp[N][0].end());
    ans.insert(ans.end(), dp[N][1].begin(), dp[N][1].end());

    sort(ans.begin(), ans.end());

    for (const string &tmp : ans) {
        cout << tmp << endl;
    }

    return 0;
}
