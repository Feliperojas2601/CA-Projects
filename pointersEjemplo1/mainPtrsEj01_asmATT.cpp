#include <iostream>

using namespace std;

int a=5,b=8,c=2;   //a: 05 00 00 00, b: 08 00 00 00, c = 02 00 00 00

int *myPtr1,*myPtr2;

int main()
{
    //myPtr1=&a;
    //asm("mov dword ptr [_myPtr1], offset [_a]");
    //or
    asm("lea _a, %eax");
    asm("mov %eax, _myPtr1");
    //*myPtr1=13;
    asm("movl _myPtr1, %eax");
    asm("movl $13, (%eax)");
    //myPtr2=&b;
    //asm("movl $_b, _myPtr2");
    //or
    asm("lea _b, %edx");
    asm("mov %edx, _myPtr2");
    //c=*myPtr1+*myPtr2;
    asm("mov _myPtr1, %eax"); //eax <-- &a
    asm("mov (%eax), %eax");    //c = a

    asm("mov _myPtr2, %edx"); //eax <-- &a
    asm("mov (%edx), %edx");    //c = a

    asm("add %edx, %eax");
    asm("mov %eax, _c");
    cout << "c = " << c << endl;
    return 0;
}
