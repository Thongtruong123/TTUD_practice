#include<bits/stdc++.h>
using namespace std;

int main(){
int n, K, Q;
cin >> n >> K >> Q;
vector<int> d(n + 1);
for(int i = 1; i<= n; i++) cin >> d[i];
vector<int> d(n + 1, vector<int>(n + 1));
for(int i = 1; i <= n; i+){
    for(int j = 1; j <= n; j++){
        cin >> d[i][j];
    }
}
return 0;

}
