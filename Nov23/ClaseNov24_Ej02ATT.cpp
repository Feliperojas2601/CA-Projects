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
    asm("mov _p1,%ebx");
    asm("mov _i,%edx");
    asm("mov (%ebx,%edx,4),%ebx");
    asm("mov %ebx,_a");

    //if (p1[j]>5)
    asm("mov _p1,%ebx");
    asm("mov _j,%edx");
    asm("mov (%ebx,%edx,4),%ebx");
    asm("cmp $5, %ebx");
    asm("jng else1");
    //{
        //a=a+p2[i];
        asm("mov _p2,%ebx");
        asm("mov _i,%edx");
        asm("mov (%ebx,%edx,4),%ebx");
        asm("add _a,%ebx");
        asm("mov %ebx,_a");
    //}
    asm("jmp endif1");
    //else
    asm("else1:");
    //{
        //a=a+p1[i+2];
        asm("mov _p1,%ebx");
        asm("mov _i,%edx");
        asm("mov 2*4(%ebx,%edx,4),%ebx");
        asm("add _a,%ebx");
        asm("mov %ebx,_a");
    //}
    asm("endif1:");
    //a=a+y[i+1];
    asm("mov _i,%edx");
    asm("mov _y+1*4(,%edx,4),%ebx");
    asm("add _a,%ebx");
    asm("mov %ebx,_a");

    cout<< a <<endl;
    cout << "Hello world!" << endl;
    return 0;
}
