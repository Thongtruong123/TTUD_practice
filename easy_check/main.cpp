#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    int tmp = 1;
    int i = 0;
    while(i < n){
        if(a[i] < a[i + 1]) tmp++;
        else{
            ans = max(ans, tmp);
            tmp = 1;
        }
        i++;
    }

    cout << ans << endl;
    return 0;
}
