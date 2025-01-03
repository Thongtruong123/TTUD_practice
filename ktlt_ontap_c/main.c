#include <stdio.h>
#include <stdlib.h>
int f(int a, int b){
    return b + a;
}
int main()
{
    int j, i[5] = {10, 12, 14, 16, 18}, *p;
    p = i + 3;
    printf("%d", *p--);
    j = f(*i, *p--);
    printf("%d\n", j);
    return 0;
}
