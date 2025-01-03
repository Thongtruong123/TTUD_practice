#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
struct Point {
    int x, y;
};

Point P[N];
int n;
vector<Point> C;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> P[i].x >> P[i].y;
}

int dist2(Point a, Point b) {
    int x = a.x - b.x;
    int y = a.y - b.y;
    return x * x + y * y;
}

int cross_product(Point O, Point A, Point B) {
    int xa = A.x - O.x, ya = A.y - O.y;
    int xb = B.x - O.x, yb = B.y - O.y;
    return xa * yb - ya * xb;
}

bool cmp(Point A, Point B) {
    int cp = cross_product(P[0], A, B);
    return cp == 0 ? dist2(P[0], A) < dist2(P[0], B) : cp > 0;
}

int ccw(Point a, Point b, Point c) {
    int cp = cross_product(a, b, c);
    return cp == 0 ? 0 : (cp < 0 ? -1 : 1);
}

void solve() {
    int k = 0;
    for (int i = 1; i < n; i++) {
        if (P[i].y < P[k].y || (P[i].y == P[k].y && P[i].x < P[k].x))
            k = i;
    }
    swap(P[0], P[k]);

    sort(P + 1, P + n, cmp);

    C.push_back(P[0]);
    C.push_back(P[1]);

    for (int i = 2; i < n; i++) {
        while (C.size() > 1 && ccw(C[C.size() - 2], C[C.size() - 1], P[i]) <= 0)
            C.pop_back();
        C.push_back(P[i]);
    }
    cout << C.size() << endl;
    for (int i = 0; i < C.size(); i++)
        cout << C[i].x << " " << C[i].y << '\n';
}

int main() {
    input();
    solve();
    return 0;
}
