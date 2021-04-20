#include <iostream>

using namespace std;

int x[] = {1,2,3,4,5};
int y[] = {6,7,8,9};

int *p1 = x;
int *p2 = y;

int a;
int b;
int c;
int i;

int main()
{
    //a = p1[1];
    asm("mov _p1, %eax");
    asm("mov 4(%eax), %eax");
    asm("mov %eax, _a");
    //b = x[3];
    asm("mov $3, %edx");
    asm("mov _x(,%edx,4), %eax");  //   asm("mov eax, [_x + 3*4]");
    asm("mov %eax, _b");
    //c = a + b;
    asm("mov _a, %eax");
    asm("mov _b, %edx");
    asm("mov %eax, _c");
    asm("add %edx, _c");

    //i = 2;
    asm("movl $2, _i");
    //c = c + p2[i];
    asm("mov _i,  %edx");
    asm("mov _p2, %eax");
    asm("mov (%eax, %edx, 4), %eax");
    asm("add %eax, _c");

    cout << c << endl;
    return 0;
}
