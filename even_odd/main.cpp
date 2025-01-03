//C++
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int>dp(n, 1);
    int max_even = 0;
    int max_odd = 0;
    int ans = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] > a[i] && (a[i] + a[j])%2 != 0){
                if(a[j] %2 == 0 && dp[j] >= max_even){
                    dp[i] = dp[j] + 1;
                    max_odd = max(max_odd, dp[i]);
                    break;
                }
                if(a[j] %2 != 0 && dp[j] >= max_odd){
                    dp[i] = dp[j] + 1;
                    max_even = max(max_even, dp[i]);
                    break;
                }

            }
        }
    }
    cout << max(max_even, max_odd) << endl;
    }
    return 0;

}
*/
