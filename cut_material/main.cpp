#include <bits/stdc++.h>
using namespace std;
int H, W;
int n;
vector<int> h, w;
vector<vector<int>> mark;
int cnt = 0; // tra ve ket qua bai toan
void do_mark(int k,int vx, int vy,  int v0, int mark_value){
    int hk  = h[k];
    int wk  = w[k];
    if( v0 == 1){
        hk = w[k];
        wk = h[k];
}
for(int i = vx; i < vx+hk ; i++)
    for(int j = vy ;j < vy+wk; j++)
        mark[i][j] = mark_value;
}

bool check(int k, int vx, int vy, int v0){
    int hk  = h[k];
    int wk  = w[k];
    if( v0 == 1){
        hk = w[k];
        wk = h[k];
}
if( vx + hk -1 > H || vy + wk -1 > W) return false;
for(int i = vx; i < vx+hk ; i++)
    for(int j = vy; j < vy+wk; j++)
        if(mark[i][j] == 1) return false;
return true;
}

void Try(int k){
    if( k == n+ 1){ cnt = 1;
    return;
    }
    for(int v0  = 0; v0 <=1; v0 ++){
        int hk  = h[k];
    int wk  = w[k];
    if( v0 == 1){
        hk = w[k];
        wk = h[k];
    }
    for(int i = 1; i<= H - hk + 1; i ++){
        for(int j = 1; j <= W - wk + 1; j ++){
            if(check(k, i, j, v0)){
                do_mark(k, i, j, v0, 1);
                Try( k + 1);
                do_mark(k, i, j, v0, 0);
            }
        }
    }
    }
}
int main()
{
cin >> H >> W;
cin >> n;
h.resize(n  + 1);
w.resize(n + 1);
mark.resize(H+1, vector<int>(W+1, 0));
for (int i = 1; i<=n ; i++) cin >> h[i] >> w[i];
Try(1);
cout << cnt;
return 0;
};
