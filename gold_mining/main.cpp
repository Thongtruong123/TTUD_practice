#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int L1, L2;


int main(){
cin >> n >> L1 >> L2;
a.resize( n + 1);

int max_gold = 0;
vector<int>dp(n+1,0);

for(int i = 1; i <=n; i++) cin >> a[i];


for(int i = 1; i<=n; i++){
        dp[i] = a[i];
        for(int j = max(1, i - L2); j <=  i - L1 && j >=1; j++){
            dp[i] = max(dp[i], dp[j] + a[i]);
        }
        max_gold = max(max_gold, dp[i]);

}

cout << max_gold << endl;
return 0;
}
