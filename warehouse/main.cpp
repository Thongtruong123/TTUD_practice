#include<bits/stdc++.h>
using namespace std;

int N, T, D;
vector<int> a;
vector<int> t;


int main(){
cin >> N >> T >> D;
a.resize( N + 1);
t.resize(N + 1);
int max_good = 0;
vector<vector<int>>dp(N+1, vector<int>(T+1, 0));

for(int i = 1; i <=N; i++) cin >> a[i];
for(int i = 1; i <=N; i++) cin >> t[i];

for(int i = 1; i<=N; i++){
    for(int j = T; j >= t[i]; j--){
        for(int k = max(1, i - D); k <= i; k++){
            dp[i][j] = max(dp[i][j], dp[k][j - t[i]] + a[i]);
        }
        max_good = max(max_good, dp[i][j]);
    }
}

cout << max_good << endl;
return 0;
}
