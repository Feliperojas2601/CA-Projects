#include <iostream>

using namespace std;

int x[4] = {28,41,7,15};
int y[3] = {5,10,9};
int *p1 = x;
int *p2 = y;

int a;
int i=1;
int j=2;

int main()
{
    //a=p1[i] ;
    asm("mov ebx, [_p1]");
    asm("mov edx, [_i]");
    asm("mov ebx, [ebx+edx*4]");
    asm("mov [_a],ebx");

    //if (p1[j]>5)
    asm("mov ebx, [_p1]");
    asm("mov edx, [_j]");
    asm("mov ebx, [ebx+edx*4]");
    asm("cmp ebx, 5");
    asm("jng else1");
    //{
        //a=a+p2[i];
        asm("mov ebx, [_p2]");
        asm("mov edx, [_i]");
        asm("mov ebx, [ebx+edx*4]");
        asm("add ebx, [_a]");
        asm("mov [_a], ebx");
    //}
    asm("jmp endif1");
    //else
    asm("else1:");
    //{
        //a=a+p1[i+2];
        asm("mov ebx, [_p1]");
        asm("mov edx, [_i]");
        asm("mov ebx, [ebx+edx*4+2*4]");
        asm("add ebx, [_a]");
        asm("mov [_a], ebx");
    //}
    asm("endif1:");
    //a=a+y[i+1];
    asm("mov edx, [_i]");
    asm("mov ebx, [_y+edx*4+1*4]");
    asm("add ebx, [_a]");
    asm("mov [_a], ebx");

    cout<< a <<endl;
    cout << "Hello world!" << endl;
    return 0;
}
