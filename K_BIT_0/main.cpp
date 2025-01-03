/*
#include<bits/stdc++.h>
using namespace std;

//Truong Xuan Thong
//MSSV: 20220044


void Try(int i, int cnt, vector<int> a, int n, int k){
    if( i == n + 1){
        for(int i = 1; i <= n; i++) cout << a[i] << " ";

    cout << endl;
    return;
}
a[i] = 0;
Try(i + 1, 0, a, n, k);

if( cnt < k - 1){
    a[i] = 1;
    Try(i + 1, cnt + 1, a, n, k);

}

}

int main(){
int n, k;
cin >> n >> k;
vector<int> a(n + 1);
Try(1, 0, a, n, k);
return 0;
}




#include<bits/stdc++.h>
using namespace std;

//Truong Xuan Thong
//MSSV: 20220044

int n;
vector<vector<bool>> check;
bool found = false;
bool isValid(int x, int y) {
    return (x > 0 && x <= n && y > 0  && y <= n);
}
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

vector<pair<int, int>> mov;
void Try(int i){
    if(found) return;
    if(i == n * n){
        for(int j = 0; j < n * n; j++) cout << "(" << mov[j].first << " " << mov[j].second << ")" << endl;
        found = true;
        return;
    }
    for(int k = 0; k < 8; k++){
        if(isValid(mov[i - 1].first + dx[k], mov[i - 1].second + dy[k]) && !check[mov[i - 1].first + dx[k]][mov[i - 1].second + dy[k]]){
            mov[i].first = mov[i - 1].first + dx[k];
            mov[i].second = mov[i - 1].second + dy[k];

            check[mov[i].first][mov[i].second] = true;
            Try(i + 1);
            check[mov[i].first][mov[i].second] = false;
        }
    }
}

int main(){
cin >> n;
check.resize(n + 1, vector<bool> ( n + 1, false));
mov.resize( n * n + 1);
mov[0]= {1, 1};
check[1][1] = true;
Try(1);
return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
