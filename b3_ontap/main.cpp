//C++
#include <bits/stdc++.h>
using namespace std;

vector<int>a;
vector<int>s;

void Try(int i, int sum, int n){
    if(i == n + 1) {
            s.push_back(sum);
            return;
    }

    Try(i + 1, sum, n);

    Try(i + 1, sum + a[i], n);
}
int main()
{
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int M;
    cin >> M;
    Try(0, 0, n);
    sort(s.begin(), s.end());
    auto it = upper_bound(s.begin(), s.end(), M);
    int result = (it == s.begin()) ? M : M - *(--it);

    // In kết quả
    cout << result;
    return 0;
}
