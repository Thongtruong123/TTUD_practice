#include <bits/stdc++.h>

// de bai: https://wiki.vnoi.info/vi/algo/dp/dp-bitmask
// tom tat: đếm số hoán vị của tập 1 đến n sao cho 2 phần tử liên tiếp chênh lệch ko vượt quá k

using namespace std;
// Goi dp[X][p] la so luong day la hoan vi cua X con A vaf co phan tu cuoi cung
// duoc them vao la p
//Khi them 1 phan tu q vao X, can dam bao q ko thuoc X va abs(q-p) <=K . Do do:
// voi moi q ko thuoc X, dp[X hợp q][q] = sigma dp[X][p] với p thuoc X và abs(q-p) <=K
//Kết quả của bài toán là tổng số dãy được tạo ra từ dãy  a ban đầu với đầy đủ phần tử ở mọi trường hợp phần tử cuối cùng, tức sigma (p tư 1 den N) dp[a][p]
const int maxN = 1<<15 + 1;
int n, k;
long long dp[maxN][16];

//lay bit thu k cua so x
int getBit(int x, int k){
return (x >>k) & 1;
}

int solve(int n, int k){
for(int mask = 0; mask < (1 << n); mask ++)
    for(int k = 0; k <= n; k++) dp[mask][k] = 0;

//base case
dp[0][0] = 1;

for(int mask = 0; mask < (1 << n); mask ++){
    for(int q = 1; q <=n; q++){
        //check q nằm trong tập hợp (biểu diễn bằng mask)
        if(getBit(mask, q - 1)) continue;
        for(int p = 0; p<=n; p++){
            if( p != 0 && abs(q-p) > k) continue;
            // them q vao tap hop
            int newmask = mask | (1 << (q-1));
            dp[newmask][q] += dp[mask][p];

        }

    }
}
long long res = 0;
int fullmask = (1 << n) - 1;
for(int k = 1; k <=n; k++){
    res += dp[fullmask][k];
}

    return res;

}






int main()
{
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}
