#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >> n;
vector<int> a(n+1);
unordered_set<int> seen; // dung de luu cac phan tu da thay
for(int i = 1; i<=n; i++) cin >> a[i];
vector<int> kq(n+1, 0);
for(int i = 1; i<=n; i++){
    if(seen.find(a[i]) != seen.end()){
        kq[i] = 1;
    }else{
    seen.insert(a[i]);
    }
}
for(int i = 1; i<=n; i++){
    cout << kq[i] << endl;
}
return 0;

}
