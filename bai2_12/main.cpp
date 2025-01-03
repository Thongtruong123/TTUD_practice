#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<pair<long long, long long>> a;
    long long key, value;

    while(cin >> key >> value){
        a.push_back({key, value});
    }
    sort(a.begin(), a.end(), [](pair<long long, long long> a, pair<long long, long long> b ){
         if(a.second != b.second){
            return a.second > b.second;
         }else{
         return a.first > b.first;
         }
         });
    for(auto& x: a){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
