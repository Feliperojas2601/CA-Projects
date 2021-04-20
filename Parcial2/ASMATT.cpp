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
    asm("mov _p1,%ebx");
    asm("mov _i,%edx");
    asm("mov (%ebx,%edx,4),%ebx");
    asm("mov %ebx,_a");
    //b=y[j+1];
    asm("mov _j,%edx");
    asm("mov _y+1*4(,%edx,4),%ebx");
     asm("mov %ebx,_b");
    //if (p2[j]<15)
    asm("mov _p2,%ebx");
    asm("mov _j,%edx");
    asm("mov (%ebx,%edx,4),%ebx");
    asm("cmp $15, %ebx");
    asm("jnl else1");
    //{
        //a=a+p2[i];
        asm("mov _p2,%ebx");
        asm("mov _i,%edx");
        asm("mov (%ebx,%edx,4),%ebx");
        asm("add _a,%ebx");
        asm("mov %ebx, _a");
        //a=a-p1[2];
        asm("mov _p1,%ebx");
        asm("mov 2*4(%ebx),%ebx");
        asm("sub %ebx, _a");

        asm("jmp endif1");
    //}
    //else
    asm("else1:");
    //{
        //a=a+p2[j+2];
        asm("mov _p2,%ebx");
        asm("mov _j,%edx");
        asm("mov 2*4(%ebx,%edx,4),%ebx");
        asm("add _a,%ebx");
        asm("mov %ebx, _a");
        //a=a-b;
        asm("mov _a,%ebx");
        asm("sub _b, %ebx");
        asm("mov %ebx, _a");
    //}
    asm("endif1:");
    //a=a+y[0];
    asm("mov _y, %ebx");
    asm("add _a,%ebx");
    asm("mov %ebx, _a");

    cout<< a <<endl;
    cout << "Hello world!" << endl;
    return 0;
}
