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
    a=p1[i] ;
    asm("");
//    if (p1[j]>5)
    asm("mov eax, [_p1]");
    asm("mov edx, [_j]");
    asm("mov eax, [eax+edx*4] ");
    asm("cmp eax, 5");
    asm("jng else1");
//    {
        a=a+p2[i];
    asm("jmp endif1");
//    }
//    else
    asm("else1:");
//    {
        a=a+p1[i+2];
//    }
    asm("endif1:");
    a=a+y[i+1];

    cout<< a <<endl;
    cout << "Hello world!" << endl;
    return 0;
}
