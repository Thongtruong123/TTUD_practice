#include<bits/stdc++.h>
using namespace std;

int main()
{
    set <string> database;
    string input;

    while(true){
    cin >> input;
    if(input == "*") break;
    database.insert(input);
    }

    while(true){
        cin >> input;
        if( input == "***") break;
        string key;
        cin >> key;
        if(input == "find"){
            cout << (database.count(key) > 0 ? 1:0) << endl;
        }
        else if(input == "insert"){
            auto result = database.insert(key);
            cout << (result.second ? 1 : 0) << endl;
            // reesult.second tra ve lieu co chen thanh cong hay khong
        }
    }


    return 0;
}
