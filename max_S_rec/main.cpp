#include <bits/stdc++.h>

using namespace std;
// Truong Xuan Thong 20220044
int main()
{
    int n;
    cin >> n;
    vector<int> h(n + 2);
    h[0] = -1;
    h[n + 1] = -1;
    for(int i = 1; i <= n; i ++) cin >> h[i];
    vector<int> max_left(n + 1, -1);
    vector<int>min_right(n + 1, n + 1);
    stack<int> st;

    for (int i = 1; i <= n; i++) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        max_left[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }


    while (!st.empty()) st.pop();


    for (int i = n; i >= 1; i--) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        min_right[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, h[i] * (min_right[i] - max_left[i] - 1));
    }
    cout << ans << endl;
    return 0;

}
