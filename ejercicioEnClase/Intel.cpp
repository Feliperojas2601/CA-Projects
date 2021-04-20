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
    asm("mov eax, [_p1]");
    asm("mov eax, [eax + 4]");
    asm("mov [_a], eax");
    //b = x[3];
    asm("mov eax, [_x + 3*4]");
    asm("mov [_b], eax");
    //c = a + b;
    asm("mov eax, [_a]");
    asm("mov edx, [_b]");
    asm("mov [_c], eax");
    asm("add [_c], edx");

    //i = 2;
    asm("mov dword ptr [_i], 2");
    //c = c + p2[i];
    asm("mov edx, [_i]");
    asm("mov eax, [_p2]");
    asm("mov eax, [eax + edx* 4]");
    asm("add [_c], eax");

    cout << c << endl;
    return 0;
}
