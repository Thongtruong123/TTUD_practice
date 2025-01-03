#include<bits/stdc++.h>
using namespace std;

//Truong Xuan Thong
//MSSV: 20220044

int main(){
int n;
cin >> n;
vector<int> a(n + 1);
for(int i = 1; i <= n; i++){
    cin >> a[i];
}
vector<int> dp(n + 1, 1);
int max_len = 0;
int end_point = 1;

for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);

        }
        if( dp[i] > max_len){
                max_len = dp[i];
                end_point = i;
        }
}
cout << max_len << endl;
int k = end_point;
stack<int> s;
while ( k > 0){
    s.push(k);
    if(dp[k] == 1){
        break;
    }
    for(int p = k - 1; p >= 1; p--){
        if(dp[k] == dp[p] + 1 && a[k] > a[p]){
            k = p;
            break;
        }
    }
}
for(int i = 1; i <= max_len; i ++){
    cout << s.top() << " ";
    s.pop();
}
return 0;
}
