
#include<bits/stdc++.h>
using namespace std;

//Truong Xuan Thong
//MSSV: 20220044
int ans = 10000;
int sum = 0;

void Try(int i, vector<vector<int>>& c, int &n, vector<int>& check, int cur_point){
    if( i == n){
        if(ans > sum + c[cur_point][1]) ans = sum + c[cur_point][1];
        return;
    }
    for(int j = 2; j <= n; j++){
        if( check[j] == 0 && sum + (n - i) < ans){
            sum += c[cur_point][j];
            check[j] = 1;
            Try(i + 1, c, n, check, j);
            check[j] = 0;
            sum -= c[cur_point][j];
        }
    }

}

int main(){
    int n;
    cin >> n;
    vector<int>check(n + 1, 0);
    vector<vector<int>> c( n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }
    check[1] = 1;
    Try(1, c, n, check, 1);
    cout << ans << endl;
    return 0;

}

