#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, Q;
    cin >> n >> Q;

    if(n < 3){
        cout << 0;
        return 0;
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long ans = 0;
    const int MOD = 1e9 + 7;

    for(int i = 0; i < n - 2; i++){
        int left = i + 1;
        int right = n - 1;

        while(left < right){
            int sum = a[left] + a[right];
            if(sum == Q - a[i]){
                int l_count = 1, r_count = 1;

                while(left + 1 < right && a[left] == a[left + 1]){
                    l_count++;
                    left++;
                }
                while(left < right - 1 && a[right] == a[right - 1]){
                    r_count++;
                    right--;
                }

                ans = (ans + 1LL * l_count * r_count) % MOD;

                left++;
                right--;
            }
            else if(sum < Q - a[i]){
                left++;
            }
            else{
                right--;
            }
        }
    }

    cout << ans;
    return 0;
}
