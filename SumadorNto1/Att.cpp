#include <iostream>

using namespace std;

int n=5;
int sum=0;

int main()
{
    //while (n!=0)
    asm("initWhile1:");
    asm("mov _n, %eax");
    asm("je endWhile1");
    //{
        //sum=sum+n;
        asm("add %eax, _sum");
        //n=n-1;
        asm("subl $1, _n");
    //}
    asm("jmp initWhile1");
    asm("endWhile1:");

    cout << "sum = " << sum<<endl;
    return 0;
}
