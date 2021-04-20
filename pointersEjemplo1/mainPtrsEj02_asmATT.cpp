#include <iostream>

using namespace std;

int a=5,b=8,c=2;  //a: 05 00 00 00 : 08 00 00 00 : 02 00 00 00

int *myPtr;

int main()
{
    //myPtr=&a;
    asm("movl $_a, _myPtr");
    //*myPtr=13;
    asm("mov _myPtr, %eax");
    asm("movl $13, (%eax)");
    //c=*myPtr+*(myPtr+1);
    asm("mov _myPtr, %eax");
    asm("mov (%eax), %eax");

    asm("mov _myPtr, %edx");
    asm("add $4, %edx");
    asm("mov (%edx), %edx");

    asm("add %eax, %edx");
    asm("mov %edx, _c");

    cout << "c = " << c << endl;
    return 0;
}
