/*
Cho hai dãy số nguyên đã được sắp xếp không giảm a và  b lần lượt có n và m phần tử. Hãy ghép chúng thành dãy  được bố trí theo thứ tự không giảm.

Giới hạn: n, m < = 10^5 và 0<=ai, bi <= 10^9
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[100001], b[100001];
    int n, m;
    cin >> n >> m;
    cout << "NHAP MANG A:" << endl;
    for(int i =0; i<n; i++) cin >> a[i];
    cout << "NHAP MANG b:" << endl;
    for(int i =0; i<m; i++) cin >> b[i];

    vector<int> c;
    int i = 0, j=0;
    while(i<n || j < m){
            if(j == m || (i <=n-1 && a[i] <= b[j])){
                c.push_back(a[i++]);
            }
            else{
                c.push_back(b[j++]);
            }
    }
    for(auto it: c){
        cout << it << " ";
    }
    return 0;
}
