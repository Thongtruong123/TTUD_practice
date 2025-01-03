#include <iostream>
using namespace std;
void foo( int *m) {
   int *p = m;
    *p++; *p += 3;
    p += 2; *p += 1;
}
int main(){
    int A[]={ 2, 4, 6, 8, 10 } ;
    foo(A+1);
    for (int i : A)  cout << i << ", ";
}



int A[] = {2, 4, 6, 8,10} ;
int *p = &A[3];
*p-- =5; *p += 2;
p += 2; *p += 2;



#include<iostream>
using namespace std;

int main(){
    int x = 1;
    int y = 2;
    auto func = [&] (int a) mutable {
        x += y++  + a;
    };
    func(10);
    cout << x << " , " << y << endl;
}
