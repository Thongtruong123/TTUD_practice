#include<bits/stdc++.h>
using namespace std;

int n, k, D;
vector<vector<int>> c;
vector<int> a, visited, picked;
int cur_len = 0;
int MIN = 1e5 + 7;
int min_len = 1;
int load;

int distance(int start, int n_end) {
    int s = 0;
    for (int x = start; x < n_end; x++) {
        s += c[a[x]][a[x + 1]];
    }
    return s;
}

void Try(int i) {
    if (i == 2 * n + 1) {
        if (cur_len + c[a[2 * n]][0] < MIN) {
            MIN = cur_len + c[a[2 * n]][0];
        }
        return;
    }

    for (int h = 1; h <= 2 * n; h++) {
        if (!visited[h]) {
            if (h <= n && load < k) {
                picked[h] = i;
                a[i] = h;
                visited[h] = 1;
                load += 1;
                cur_len += c[a[i - 1]][h];

                if (cur_len + (2 * n + 1 - i) * min_len < MIN) {
                    Try(i + 1);
                }

                visited[h] = 0;
                load -= 1;
                cur_len -= c[a[i - 1]][h];
            }
            else if (h > n && visited[h - n]) {
                a[i] = h;
                if (distance(picked[h - n], i) <= D) {
                    visited[h] = 1;
                    load -= 1;
                    cur_len += c[a[i - 1]][h];


                    if (cur_len + (2 * n + 1 - i) * min_len < MIN) {
                        Try(i + 1);
                    }

                    visited[h] = 0;
                    load += 1;
                    cur_len -= c[a[i - 1]][h];
                }
            }
        }
    }
}

int main() {
    cin >> n >> k >> D;
    c.resize(2 * n + 1, vector<int>(2 * n + 1));
    a.resize(2 * n + 1);
    picked.resize(n + 1);
    visited.resize(2 * n + 1, 0);
    load = 0;

    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
        }
    }

    Try(1);
    if(MIN == 1e5 + 7) << cout << -1;
    else
    cout << MIN;
    return 0;
}








/*
#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> c;
int MIN = 1e3 + 7;
int cur_length = 0;
vector<int> a, check;
int min_len = 1;
int load;

void Try(int i) {
    if (i == 2*n + 1) {
        if (cur_length + c[a[2*n]][0] < MIN) {
            MIN = cur_length + c[a[2*n]][0];
        }
        return;
    }

    for (int h = 1; h <= 2*n; h++) {
        if (check[h] == 0){
            if (load < k && h <= n) {
                check[h] = 1;
                a[i] = h;
                load += 1;
                cur_length += c[a[i-1]][h];

                if (cur_length + min_len * (2*n + 1 - i) < MIN) {
                    Try(i + 1);
                }


                check[h] = 0;
                load -= 1;
                cur_length -= c[a[i-1]][h];

            } else if (h > n && check[h - n] == 1) {
                check[h] = 1;
                a[i] = h;
                load -= 1;
                cur_length += c[a[i-1]][h];

                if (cur_length + min_len * (2*n + 1 - i) < MIN) {
                    Try(i + 1);
                }


                check[h] = 0;
                load += 1;
                cur_length -= c[a[i-1]][h];
            }
        }
    }
}

int main() {

    cin >> n >> k;
    c.resize(2*n + 1, vector<int>(2*n + 1));
    a.resize(2*n + 1);
    check.resize(2*n + 1, 0);
    load = 0;

    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            cin >> c[i][j];

        }
    }

    Try(1);
    cout << MIN;
    return 0;
}
*/
