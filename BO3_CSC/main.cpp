#include <bits/stdc++.h>

using namespace std;
int MOD = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if( n < 3) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    sort(a.begin(), a.end());
    for(int i = 2; i < n; i++){
        int left = 0;
        int right = i - 1;
        while(left < right){
            if(a[left] + a[right] == a[i]){
                ans = (ans + 1)%MOD;
                left ++;
                right --;
            }else if(a[left] + a[right] < a[i]){
                left++;
            }else{
                right--;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
