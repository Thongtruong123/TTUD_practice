#include <bits/stdc++.h>

using namespace std;
#define MAX 10000;



int K, N;
int Q;
int Cmin = 0;
int f = 0, f_min;
int segments = 0, nbR = 0;
vector<int>d; // can van chuyen d[i] box đến diem thu i
vector<vector<int>>c;// ma tran khoang cach
vector<int> load; // tai trong hien tai cua xe
vector<int> y; // diem giao dau tien cua moi xe
vector<int> x; // diem tiep theo tren tuyen duong cua xe
vector<bool> visited;

void updateBest() {
    if (f < f_min) {
        f_min = f;  // Cập nhật lời giải tốt nhất
    }
}

bool checkX(int v, int k){
if( v > 0 && visited[v]) return false;
if( load[k] + d[v] > Q) return false;
return true;
}

void Try_X(int s, int k){
// thu gan gia tri cho x[s]
if(s == 0){
    if( k < K){
        Try_X(y[k + 1], k + 1);
    }
    return;
}
for( int v = 0; v<=N; v++){
    if(checkX(v, k)){
        x[s] = v;
        visited[v] = true;
        f += c[s][v];
        load[k] = load[k] + d[v];
        segments = segments + 1;
        if(v > 0){
            if( f + (N + nbR - segments)* Cmin < f_min){
                Try_X(v, k);
            }
        }else{
        if(k == K){
            if(segments == N + nbR) updateBest();
        }else{
        if( f + (N + nbR - segments) * Cmin < f_min){
            Try_X(y[k + 1], k + 1);
        }
        }
        }
        visited[v] = false;
        f = f - c[s][v];
        load[k] = load[k] - d[v];
        segments = segments - 1;
        }
    }
}

bool checkY(int v, int k){
if( v == 0) return true;
if(load[k] + d[v] > Q ) return false;
if( visited[v]) return false;
return true;
}

void Try_Y(int k){
    // thu gan gia tri cho y[k]
int s = 0;
if( y[k - 1]>0) s = y[k-1] + 1;
for( int v = s; v <=N ; v++){
    if(checkY(v, k)){
    y[k] = v;
    if(v > 0){
        segments = segments + 1;
        visited[v] = true;
        f = f + c[0][v];
        load[k] = load[k] + d[v];
    }
    if( k < K){ Try_Y( k + 1);
    }else{
    nbR = segments;
    Try_X(y[1], 1);
    }
   load[k] = load[k] - d[v];
   visited[v] = false;
   f = f - c[0][v];
   if( v> 0) segments = segments - 1;
}
}
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << " Nhap N, K";
    cin >> N >> K;
    cout << "Nhap Q";
    cin >> Q;
    cout << "Nhap ma tran d";
    d.resize( N + 1);
    x.resize( N + 1);
    y.resize( N + 1);
    for(int i = 1; i <=N; i++) cin >> d[i];
    c.resize(N + 1, vector<int>(N+ 1));
    cout << "Nhap ma tran c";
    for(int i = 0; i <=N ; i++){
        for(int j = 0; j<=N ; j++){
            cin >> c[i][j];
            if( c[i][j] < Cmin) Cmin = c[i][j];
        }
    }
    for(int i = 1; i<=N; i++) visited[i] = false;
    y[0] = 0;
    f_min = MAX;

    Try_Y(1);
    cout << f_min << endl;
    return 0;
}
