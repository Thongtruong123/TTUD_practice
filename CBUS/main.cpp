#include<bits/stdc++.h>
using namespace std;

int n, h;
vector<vector<int>> c;
vector<int> a; // luu vet duong di
vector<int> check;
int current_len = 0;
int min_dis = 1;
int MIN = 1e3;
int load = 0;

void Try(int i){
if(i == 2*n + 1){
    if(  current_len + c[a[2*n]][0] < MIN){
        MIN = current_len + c[a[2*n]][0];
    }
    return;
}

for(int k = 1; k<=2 *n ; i++){
    if( check[k] == 0){
        if( load < h && k <= n){
            a[i] = k;
            check[k] = 1;
            load ++;
            current_len += c[a[i-1]][k];
            if( current_len + (2*n - i + 2)*min_dis <= MIN){
                Try( i + 1);
                check[k] = 0;
                load --;
                current_len -= c[a[i-1]][k];
            }
        }else if(k > n && check[k - n] == 1){
        check[k] = 1;
        a[i] = k;
        load --;
        current_len += c[a[i-1]][k];
            if( current_len + (2*n - i + 2)*min_dis <= MIN){
                Try( i + 1);
                check[k] = 0;
                load ++;
                current_len -= c[a[i-1]][k];
            }

        }
    }
}
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin >> n >> h;
c.resize(2*n + 2, vector<int>(2*n+2));
for(int i = 0; i<=2*n; i++){
for(int j= 0; j<=2*n; j++){
    cin >> c[i][j];
    if( min_dis > c[i][j]) min_dis = c[i][j];
}
}
Try(1);
cout << MIN;

return 0;
}
