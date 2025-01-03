#include <bits/stdc++.h>
using namespace std;

long long inversion_merge(vector<int>&a, int left, int mid, int right){
vector<int>left_a( a.begin() + left, a.begin()+ mid + 1);
vector<int>right_a( a.begin() + mid + 1, a.begin() + right + 1);
int i = 0, j = 0, k = left;
long long inv_cnt = 0;
while(i < left_a.size() && j < right_a.size()){
    if(left_a[i] <= right_a[j]){
        a[k ++] = left_a[i++];
    }else{
    a[k ++ ] = right_a[j ++];
    inv_cnt += (left_a.size() - i);
    }
}
while(i < left_a.size()){
    a[k ++] = left_a[i ++];
}
while( j < right_a.size()){
    a[k ++] = right_a[j ++];
}
return inv_cnt;
}



long long mergesort_count( vector<int> &a, int left, int right){
long long inversion_cnt = 0;
if(left < right){
    int mid = left + ( right - left)/2;
    // dem so bo nghich the trong mang con ben trai
    inversion_cnt += mergesort_count(a, left, mid);
    // dem so bo nghich the trong mang con ben phai
    inversion_cnt += mergesort_count(a, mid + 1, right);
    // dem so bo nghich the khi tron
    inversion_cnt += inversion_merge(a, left, mid, right);

}
return inversion_cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i<=n; i++) cin >> a[i];
    cout << mergesort_count(a, 1, n) % (long long)(1e9 + 7) << endl;
    return 0;
}
