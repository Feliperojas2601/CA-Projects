#include <iostream>

using namespace std;

int a[3]={5,7,2};
int i;
int result=0;

int main()
{
    asm("mov dword ptr [_i], 0");
    asm("initfor1:");
    asm("cmp dword ptr [_i],3");
    asm("jnl endfor1");
    //for(i=0;i<3;i++)
    //{
        //result=result+a[i];
        asm("mov edx, [_i]");
        asm("mov edx, [_a+edx*4]");
        asm("add [_result], edx");
        asm("add dword ptr [_i], 1");
        asm("jmp initfor1");
    //}
    asm("endfor1:");
    cout << result <<endl;
    cout << "Hello world" <<endl;
    return 0;
}
