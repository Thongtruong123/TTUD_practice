#include <bits/stdc++.h>

using namespace std;
//Trương Xuân Thông 20220044
vector<string> ans;
int N, H;
string tmp;

void Try(int i, int cnt) {
    if (i == N + 1) {
        if (cnt == H)
            ans.push_back(tmp);
        return;
    }
    if (cnt == H) {
        tmp += '0';
        Try(i + 1, cnt);
        tmp.pop_back();
    } else {
        tmp += '0';
        Try(i + 1, cnt);
        tmp.pop_back();

        tmp += '1';
        Try(i + 1, cnt + 1);
        tmp.pop_back();
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> H;
        ans.clear();
        tmp.clear();
        Try(1, 0);

        sort(ans.begin(), ans.end());
        for (const string &s : ans) {
            cout << s << endl;
        }
    }
    return 0;
}
