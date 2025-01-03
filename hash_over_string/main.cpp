#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<n ; i++){
        string s;
        cin >> s;
        long long hash_value = 0;
        int length = s.length();

        for(int j = 0; j< length; j++){
            hash_value = (hash_value * 256 + s[j])%m;
        }
        cout << hash_value << endl;
    }


    return 0;
}
