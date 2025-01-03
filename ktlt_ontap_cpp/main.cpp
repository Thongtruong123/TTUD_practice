#include <iostream>

using namespace std;

int add(int a, int b) {
return a + b;
}
int main()
{

int (*funcPtr)(int, int) = &add; // Khai báo con trỏ hàm.
int result = funcPtr(3, 4);
cout << result;
    return 0;
}
