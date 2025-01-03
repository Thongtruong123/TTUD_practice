#include <bits/stdc++.h>

using namespace std;
int n;
vector<int>a;
vector<int>s;
void Try(int i, int sum){
    if(i >= n){
        s.push_back(sum);
        return;
    }
    Try(i + 1, sum - a[i]);
    Try(i + 1, sum + a[i]);
}

int main()
{
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    Try(0, 0);

    for(int i = 0; i < s.size(); i++) s[i] = abs(s[i]);
    sort(s.begin(), s.end());
    cout << s[0] << endl;
    return 0;
}
