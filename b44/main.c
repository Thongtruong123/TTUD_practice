/*
#include<stdio.h>
int f(int a, int b) {
    return b + a;
}
int main() {
    int j, i[5] = {10, 12, 14, 16, 18}, *p, *q;
    p = i; q = p;
    *q = f(i[0], *p++);
    printf("%d %d \n", *p, *q);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define INCREMENT(x) ++x

int main() {
    char* ptr = "DHBK-HN";
    int x = 10;
    printf("%s  ", 1 + INCREMENT(ptr + 1));
    printf("%d", 1 + INCREMENT(x + 1));
    return 0;
}


#include<stdio.h>
int main() {
    float x = 2.5;
    char *p = &x;            // Gán địa chỉ của x cho con trỏ kiểu char*
    printf("%d\n", *(p + 2));  // In giá trị tại vị trí p + 2
    return 0;
}


#include<stdio.h>
int f(int a, int b) {
    return b + a;  // Hàm trả về tổng của b và a
}

int main() {
    int j, i[5] = {10, 12, 14, 16, 18}, *p;
    p = i + 3;  // Con trỏ p trỏ đến phần tử i[3] (16)
    j = f(*i, *p--);  // Gọi hàm f với các đối số *i và *p trước khi p giảm
    printf("%d\n", j);  // In giá trị của j
    return 0;
}
*/
#include<stdio.h>

int f(int a, int b) {
    return b - a;  // Hàm trả về hiệu của b và a
}

int main() {
    int i = 10, *p;
    p = &i;  // Con trỏ p trỏ đến địa chỉ của i
    i = f(--i, *p);  // Gọi hàm f với --i (i giảm trước) và *p (giá trị của i)
    printf("%d\n", *p);  // In giá trị mà p trỏ tới (tức là giá trị của i)
    return 0;
}
