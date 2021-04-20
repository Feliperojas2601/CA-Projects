#include <iostream>

using namespace std;

int a[3]={5,7,2};
int i;
int mayor=0;

int main()
{
    asm("movl $0, _i");
    asm("initfor1:");
    asm("cmpl $3,_i");
    asm("jnl endfor1");
    //for(i=0;i<3;i++)
    //{
        asm("mov _i, %edx");
        asm("mov _a(,%edx,4), %edx");
        asm("cmp _mayor, %edx");
        asm("jng endif1");
        //if (a[i]>mayor)
        //{
            //mayor=a[i];
            asm("mov _i, %eax");
            asm("mov _a(,%eax,4), %eax");
            asm("mov %eax, _mayor");
        //}
        asm("endif1:");
        asm("addl $1, _i");
        asm("jmp initfor1");
    //}
    asm("endfor1:");

    cout << mayor <<endl;
    cout << "Hello world" <<endl;
    return 0;
}
