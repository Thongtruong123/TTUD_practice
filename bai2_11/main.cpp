#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i <= n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m + 1);
    for(int i = 0; i <= m; i++){
        cin >> b[i];
    }
    int ans = 0;
    vector<long long> c(m + n + 1, 0); // he so cua da thuc C
    for(int k = 0; k < m + n + 1; k++){
        for(int i = 0; i <= n; i++){
                if(k - i >= 0 && k - i <= m)
            c[k]  += a[i] * b[k - i];
        }
        ans ^= c[k];
    }

    cout << ans << endl;
    return 0;
}



