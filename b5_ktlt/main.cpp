/*
#include <iostream>
using namespace std;

int n, M, m[100], v[100];
int x[100], best, sumV, sumM, All[100];

void init(){
    for (int i = n; i >= 1; --i){
        All[i] = All[i+1] + v[i];
    }
}

void print() {
    cout << best;
}

void process(int i){
    if (sumV + All[i] <= best || sumM > M) return;
    if (i > n){
        best = sumV;
        return;
    }
    process(i+1);
    sumM += m[i];
    sumV += v[i];
    process(i+1);
    sumM -= m[i];
    sumV -= v[i];
}

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> m[i] >> v[i];
    init();
    process(1);
    print();
    return 0;
}
*/
#include <iostream>
using namespace std;
#include <string.h>
#include <stack>

int par(string str){
    int a = str.length();
    cout << a;
    stack<char> S;
    char x, y;
    for (int i=0; i<a; i++){
        x = str[i];
        if (x == '(' || x == '[' || x == '{'){
            S.push(x);
            cout << "Kí tự:" << S.top() << endl;
        }

        else {
            if (x == ')') {
                if(S.empty())return 0;
                if (S.top() == '('){
                    S.pop();
                }
                else return 0;
            }
            else if (x == ']') {
                if(S.empty())return 0;
                if (S.top() == '['){
                    S.pop();
                }
                else return 0;
            }
            else if (x == '}') {
                if(S.empty())return 0;
                if (S.top() == '{'){
                    S.pop();
                }
                else return 0;
            }
            else
                return 0;
        }
    }
    if (!S.empty()){
        return 0;
    }
    else return 1;
}

int main(){
    int n;
    string str;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        cout << par(str) << endl;
    }

    return 0;
}
