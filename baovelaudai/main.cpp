//Truong Xuan Thong 20220044
#include <bits/stdc++.h>

using namespace std;

int main(){
int n, s;
cin >> n >> s;
vector<int> a(n + 1), k(n + 1);
for(int i = 0; i < n; i++){
    cin >> a[i] >> k[i];
}
int ans = accumulate(a.begin(), a.begin() + n, 0);
priority_queue<vector<int>, vector<vector<int>>> maxHeap;
for(int i = 0; i < n; i++){
    maxHeap.push({k[i], a[i], i});
}

while( s > 0 && !maxHeap.empty()){
    auto tmp = maxHeap.top();
    maxHeap.pop();
    if(tmp[1] >= tmp[0]){
        int div = tmp[1] / tmp[0];
        int assigned = min(s, div);
        if( s >= div)
        maxHeap.push({tmp[1] - assigned * tmp[0], tmp[1] - assigned * tmp[0], tmp[2]});

        s -= assigned;
        ans -= assigned * tmp[0];
    }
    else{
        tmp[0] = tmp[1];
        maxHeap.push(tmp);
    }

}
if(ans > 0)
    cout << ans << endl;
    else cout << 0;
    return 0;
}

