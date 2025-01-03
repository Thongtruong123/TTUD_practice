#include <bits/stdc++.h>

using namespace std;
vector<long long> x;
int N, C;
int main()
{
    cin >> N >> C;
    x.resize( N + 1);
    for(int i=1; i<=N; i++){
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    int i = 1;
    int max_dis = x[N] - x[1];
    int trung_binh = max_dis / C;
    long long ket_qua = trung_binh;
    while(i < N){
        int j = i+1;
        while(x[j] - x[i] <= trung_binh && j <= N){
            j ++;
        }
        j --;
        ket_qua = min(ket_qua, x[j] - x[i]);
        i = j + 1;
    }


    cout << ket_qua << endl;
    return 0;
}
