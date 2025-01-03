#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> segment(n);
    for(int i = 0; i<n; i++){
        cin >> segment[i].first >> segment[i].second;
    }
    // sắp xếp theo điểm kết thúc tăng dần
    sort(segment.begin(), segment.end(), [](pair<int, int> a, pair<int, int> b){
    // lambda function : [](pair<int, int>& a, pair<int, int>& b) {...} dinh nghia cach so sanh hai phan tu cua vector
    return a.second < b.second;
    });
    int cnt = 0;
    int last_end = -1; // diem ket thuc cua doan cuoi cung duoc chon
    for(int i = 0; i<n; i++){
        if(segment[i].first > last_end){
            cnt ++;
            last_end = segment[i].second;
        }
    }
    cout << cnt << endl;
    return 0;
}
