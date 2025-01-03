#include <bits/stdc++.h>
using namespace std;

int n;
int a[20];
vector<int> subset;

void Try(int i) {
    if (i == n) {
        for (int x : subset) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    Try(i + 1);

    subset.push_back(a[i]);
    Try(i + 1);

    subset.pop_back();
}

int main() {
    cout << "Nhap so phan tu: ";
    cin >> n;
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Cac tap con la:" << endl;
    Try(0);
    return 0;
}
