#include <iostream>

using namespace std;

int x[4] = {28,41,7,15};
int y[4] = {37,23,6,11};
int *p1 = x;
int *p2 = y;

int a;
int b;
int i=1;
int j=1;

int main()
{
    //a=p1[i] ;
    asm("mov ebx, [_p1]");
    asm("mov edx, [_i]");
    asm("mov ebx, [ebx+edx*4]");
    asm("mov [_a], ebx");
    //b=y[j+1];
    asm("mov edx, [_j]");
    asm("mov ebx, [_y+edx*4+1*4]");
    asm("mov [_b],ebx");
    //if (p2[j]<15)
    asm("mov ebx, [_p2]");
    asm("mov edx, [_j]");
    asm("mov ebx, [ebx+edx*4]");
    asm("cmp ebx, 15");
    asm("jnl else1");
    //{
        //a=a+p2[i];
        asm("mov ebx, [_p2]");
        asm("mov edx, [_i]");
        asm("mov ebx, [ebx+edx*4]");
        asm("add ebx, [_a]");
        asm("mov [_a], ebx");
        //a=a-p1[2];
        asm("mov ebx, [_p1]");
        asm("mov ebx, [ebx+2*4]");
        asm("sub [_a],ebx");

        asm("jmp endif1");
    //}
    //else
    asm("else1:");
    //{
        //a=a+p2[j+2];
        asm("mov ebx, [_p2]");
        asm("mov edx, [_j]");
        asm("mov ebx, [ebx+edx*4+2*4]");
        asm("add ebx, [_a]");
        asm("mov [_a], ebx");
        //a=a-b;
        asm("mov ebx, [_a]");
        asm("sub ebx, [_b]");
        asm("mov [_a], ebx");
    //}
    asm("endif1:");
    //a=a+y[0];
    asm("mov ebx, [_y]");
    asm("add ebx, [_a]");
    asm("mov [_a], ebx");

    cout<< a <<endl;
    cout << "Hello world!" << endl;
    return 0;
}
