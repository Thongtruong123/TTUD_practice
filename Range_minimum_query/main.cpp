//C++

// M[i, j ] chỉ số min đoạn con từ a_j dài 2^i
//M[0, j] = j
// M[i, j] = M[i-1, j] hoặc M[i-1, j + 2^(i-1)] tùy vào a của cái nào nhỏ hơn thì chon
// rmq[i, j] = a[M[k, i]] hoac a[M[k, j - 2^k + 1]] với k thoa man 2 dãy đủ overlap, tức là k = int(log_2(j - i + 1))
#include <bits/stdc++.h>
using namespace std;
const int N  = 1e6 + 5;
int n,m, a[N];
int M[30][N];

void precompute(){
    memset(M, -1, sizeof(M));
    for (int j = 0; j <n; j++){
        M[0][j] = j;
    }
    for (int i = 1; (1<<i) <=n; i++){
        for(int j = 0; j<n; j++){
            if( a[M[i-1][j]] < a[M[i-1][j + (1 << ( i - 1))]])
            M[i][j] = M[i-1][ j];
        else
        M[i][j] = M[i-1][j + (1 << ( i - 1))];
    }
}
}
int rmq(int i, int j){
    int k = log2(j - i + 1);
    return a[M[k][ i]] < a[M[k][j - (1<<k) + 1]] ? a[M[k][ i]] : a[M[k][j - (1<<k) + 1]];
}

long long solve(){
    long long ans = 0;
    cin >> m;
    int i, j;
    for(int t = 0; t<m; t++){
        cin >> i >> j;

    ans += rmq(i, j);
    }
    return ans;
}

int main()
{
    cin >>n;
    for(int i = 0; i<n; i++) cin >> a[i];
    precompute();
    cout<< solve();

    return 0;

}
