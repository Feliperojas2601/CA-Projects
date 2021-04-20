#include <iostream>

using namespace std;

int a=5,b=8,c=2;  //a: 05 00 00 00 : 08 00 00 00 : 02 00 00 00

int *myPtr;

int main()
{
    //myPtr=&a;
    asm("mov dword ptr [_myPtr], offset [_a]");
    //*myPtr=13;
    asm("mov eax, [_myPtr]");
    asm("mov dword ptr [eax], 13");
    //c=*myPtr+*(myPtr+1);
    asm("mov eax, dword ptr [_myPtr]");
    asm("mov eax, [eax]");

    asm("mov edx, dword ptr [_myPtr]");
    asm("add edx, 4");
    asm("mov edx, [edx]");

    asm("add edx, eax");
    asm("mov dword ptr [_c], edx");

    cout << "c = " << c << endl;
    return 0;
}
