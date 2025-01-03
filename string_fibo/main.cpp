#include <iostream>

using namespace std;
string fibo(n, i){
string  fibo(1, 1) = 'A';
string fibo(2, 1) = 'B';
if(i <= FIBO(n-2)) return fibo(n-2, i);
else{
    return fibo(n-1, i - FIBO(n-2));
}
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
