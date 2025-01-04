#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct data {
    int x, y;
};

int n, u, v, res;
data a[100], t;
vector<data> f, g;

void dfs1(int i) {
    if (i == n / 2 + 1) {
        f.push_back(t);
        return;
    }
    dfs1(i + 1);
    t.x += a[i].x;
    t.y += a[i].y;
    dfs1(i + 1);
    t.x -= a[i].x;
    t.y -= a[i].y;
}

void dfs2(int i) {
    if (i == n + 1) {
        g.push_back(t);
        return;
    }
    dfs2(i + 1);
    t.x += a[i].x;
    t.y += a[i].y;
    dfs2(i + 1);
    t.x -= a[i].x;
    t.y -= a[i].y;
}

bool cmp(const data& u, const data& v) {
    return (u.x < v.x) || (u.x == v.x && u.y < v.y);
}

int Search(int x, int y) {
    int l = 0, r = f.size() - 1, ans = 0, k, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (f[mid].x < x) {
            l = mid + 1;
        } else if (f[mid].x > x) {
            r = mid - 1;
        } else {
            if (f[mid].y < y) {
                while (f[mid].x == x && f[mid].y < y && mid < r) mid++;
                if (f[mid].x != x || f[mid].y != y) return 0;
            } else if (f[mid].y > y) {
                while (f[mid].x == x && f[mid].y > y && mid > l) mid--;
                if (f[mid].x != x || f[mid].y != y) return 0;
            }
            ans = 1;
            k = mid + 1;
            while (f[k].x == x && f[k].y == y && k <= r) ans++, k++;
            k = mid - 1;
            while (f[k].x == x && f[k].y == y && k >= l) ans++, k--;
            return ans;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    cin >> u >> v;

    // Tính tổng các véc tơ cho phần đầu (1 đến n/2)
    t.x = 0;
    t.y = 0;
    dfs1(1);
    sort(f.begin(), f.end(), cmp);  // Sắp xếp các tổng véc tơ của phần đầu

    // Tính tổng các véc tơ cho phần sau (n/2+1 đến n)
    t.x = 0;
    t.y = 0;
    dfs2(n / 2 + 1);

    // Duyệt qua tất cả các tổng của phần sau và tìm số cách kết hợp
    for (int i = 0; i < g.size(); i++) {
        int x = u - g[i].x;
        int y = v - g[i].y;
        res += Search(x, y);
    }

    cout << res;
    return 0;
}
