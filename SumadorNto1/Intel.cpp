#include <iostream>

using namespace std;

int n=5;
int sum=0;

int main()
{
    //while (n!=0)
    asm("initWhile1:");
    asm("mov eax, _n");
    asm("je endWhile1");
    //{
        //sum=sum+n;
        asm("add _sum, eax");
        //n=n-1;
        asm("sub dword ptr _n,1");
    //}
    asm("jmp initWhile1");
    asm("endWhile1:");

    cout << "sum = " << sum<<endl;
    return 0;
}
