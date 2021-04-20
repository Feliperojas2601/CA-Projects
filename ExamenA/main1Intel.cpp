#include <iostream>

using namespace std;

int a[3]={5,7,2};
int i;
int mayor=0;

int main()
{
    asm("mov dword ptr [_i],0");
    asm("initfor1:");
    asm("cmp dword ptr [_i], 3");
    asm("jnl endfor1");
    //for(i=0;i<3;i++)
    //{
        asm("mov edx, [_i]");
        asm("mov edx, [_a+edx*4]");
        asm("cmp edx, [_mayor]");
        asm("jng endif1");
        //if (a[i]>mayor)
        //{
            //mayor=a[i];
            asm("mov eax, [_i]");
            asm("mov eax, [_a+eax*4]");
            asm("mov [_mayor], eax");
        //}
        asm("add dword ptr [_i],1");
        asm("jmp initfor1");
        asm("endif1:");
    //}
    asm("endfor1:");

    cout << mayor <<endl;
    cout << "Hello world" <<endl;
    return 0;
}
