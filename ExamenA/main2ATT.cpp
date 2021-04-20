#include <iostream>

using namespace std;

int a[3]={5,7,2};
int i;
int result=0;

int main()
{
    asm("movl $0, _i");
    asm("initfor1:");
    asm("cmp $3, _i");
    asm("jnl endfor1");
    //for(i=0;i<3;i++)
    //{
        //result=result+a[i];
        asm("mov _i, %edx");
        asm("mov _a(,%edx,4),%edx");
        asm("add %edx, _result");
        asm("addl $1, _i");
        asm("jmp initfor1");
    //}
    asm("endfor1:");
    cout << result <<endl;
    cout << "Hello world" <<endl;
    return 0;
}
