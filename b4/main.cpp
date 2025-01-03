/*
#include <iostream>
using namespace std;

int main() {
    float x = 10;
    const float y = 10.5;
    float * const ptr = &x;
    *ptr = 19;
    *ptr += 1;
    ptr += 1;
    cout << *ptr;
    return 0;
}

#include "iostream"
using namespace std;

typedef struct { int Tu; int Mau; } PS;

PS operator += (PS &p1, PS p2) {
    p1.Tu = p1.Tu * p2.Mau + p2.Tu * p1.Mau;
    p1.Mau *= p2.Mau;
    return p1;
}

template <typename T>
PS operator += (PS &p1, T p2) {
    p1.Tu += p2 * p1.Mau;
    return p1;
}

int main(){
    PS p1 = {3, 4}, p2 = {2, 3};
    float x = 2.6;
    p1 += p2;
    p2 += x;
    cout << "p1 = " << p1.Tu << "/" << p1.Mau << " Va p2 = " << p2.Tu << "/" << p2.Mau;
}

#include<stdio.h>
int main() {
    int x = 6;
    printf("%c", (x >= 5) ? (x >= 7) ? (x >= 9) ? 'A' : 'B' : 'C' : 'D');
    return 0;
}


#include <iostream>
using namespace std;
int main() {
    int a = 9, b = 13;
    int *p = &a, *q = &b;
    ++a =  ~a + ~~b;
    p--;
    *p -= a + ~2;
    cout << a << ", " << b;
}

#include <iostream>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
using namespace std;

int main() {
    int a = 0;
    int b = 1;
    int c = MAX(++a, --b);
    cout << c;
    return 0;
}


#include<iostream>
using namespace std;

template <typename T>
T maxval(T x, T y){
    static int count = 0;
    cout << ++count << ", ";
    return (x > y) ? x : y;
}

int main() {
    int i = maxval(3, 7);
    cout << i << endl;  // In giá trị lớn hơn giữa 3 và 7 (7)

    double d = maxval(6.34, 18.523);
    cout << d << endl;  // In giá trị lớn hơn giữa 6.34 và 18.523 (18.523)

    d = maxval(16.34, 28.523);
    cout << d << endl;  // In giá trị lớn hơn giữa 16.34 và 28.523 (28.523)

    char ch = maxval('a', '6');
    cout << ch << endl;  // In giá trị lớn hơn giữa 'a' và '6' ('a')

    d = maxval(5.2, 4.5);
    cout << d << endl;  // In giá trị lớn hơn giữa 5.2 và 4.5 (5.2)

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int a = 15, b = 10;
    int *p = &a, *q = &b;

    *p-- += b ^ ~--a ;
    *p += 2;

    cout << a << ", " << b;
}


#include <iostream>
using namespace std;

int main() {
    int A[] = {2, 5, 6, 1} ;
int *p = A+1;
*p--; *p += 2;
p += 2; *p += 2;
    // In giá trị của tất cả các phần tử trong mảng A
    for (int i : A)  cout << i << ", ";
}


#include<iostream>
using namespace std;

int main(){
    int z=1, x = 0;
    int k, y = 2;
    auto func = [&, y] (int a)  {
        y += z++  + ++a;
    };
    func(10);
    cout << z << " , " << y << endl;
}
*/

#include "iostream"
using namespace std;

void for_each (int *arr, int n, void (*func)(int &a)){
    for (int i = 0; i < n; i++) {
        func(*(arr + i));
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;
    for_each(arr, 5, [] (int &a){
        a += 10;
    });
    for(int i = 0; i < 5; i++) cout << *p++ << " ";
    return 0;
}
