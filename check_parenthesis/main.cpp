#include<bits/stdc++.h>
using namespace std;

string s;
stack<char> a;

bool check() {
    if (a.size() < 2) {
        return false;
    }

    char top1 = a.top();
    a.pop();
    char top2 = a.top();
    a.push(top1);


    if ((top2 == '(' && top1 == ')') || (top2 == '[' && top1 == ']') || (top2 == '{' && top1 == '}')) {
        return true;
    }
    return false;
}

int main() {
    cin >> s;

    for (int k = 0; k < s.length(); k++) {
        a.push(s[k]);

        if (check()) {
            a.pop();
            a.pop();
        }
    }


    if (!a.empty()) {
        cout << 0;
    } else {
        cout << 1;
    }

    return 0;
}
