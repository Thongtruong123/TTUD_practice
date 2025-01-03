#include <bits/stdc++.h>
using namespace std;
//Truong Xuan Thong 20220044

long long bal_string(const string &s) {
    int n = s.length();

    unordered_map<int, int> prefixCount;
    int sum = 0;
    long long count = 0;
    prefixCount[0] = 1;

    for (int i = 0; i < n; ++i) {
        sum += (s[i] == '1') ? 1 : -1;

        if (prefixCount.find(sum) != prefixCount.end()) {
            count += prefixCount[sum];
        }
        prefixCount[sum]++;
    }

    return count;
}

int main() {

    string s;
    cin >> s;

    cout << bal_string(s) << endl;

    return 0;
}
