#include<bits/stdc++.h>
using namespace std;
#define N 9

vector<vector<int>> a; // mang dau vao
int cnt = 0; // biến đếm
bool check(int row, int col, int num){
for(int i = 0; i< N; i++){
    if(a[row][i]== num){
        return false;
    }
    if(a[i][col] == num){
        return false;
    }
}
// kiem tra o vuong 3*3
int x = row/3;
int y = col/3;
for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
        if(a[3*x + i][3*y + j] == num){
            return false;
        }
    }
}
return true;
}


void solve(int x, int y){
    if( y == 9){
        if(x == 8){
            cnt ++;
            return;
        }else{
        solve(x+1, 0);
        }
    }
    else if( a[x][y] == 0){
        for(int i = 1; i<= 9; i++){
            if( check(x, y, i)){
                a[x][y] = i;
                solve(x, y+1);
                a[x][y] = 0;
            }
        }
    }
    else{
        solve(x, y+1);
    }
}
int main()
{
    a.resize(10, vector<int>(10));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> a[i][j];
        }
    }
    solve(0, 0);
    cout << cnt << endl;
    return 0;
}
