#include <iostream>

using namespace std;

int a=5,b=8,c=2;   //a: 05 00 00 00, b: 08 00 00 00, c = 02 00 00 00

int *myPtr1,*myPtr2;

int main()
{
    //myPtr1=&a;
    //asm("mov dword ptr [_myPtr1], offset [_a]");
    //or
    asm("lea eax, [_a]");
    asm("mov dword ptr [_myPtr1], eax");
    //*myPtr1=13;
    asm("mov eax, [_myPtr1]");
    asm("mov dword ptr [eax], 13");
    //myPtr2=&b;
    //asm("mov [_myPtr2], offset [_b]");
    //or
    asm("lea edx, [_b]");
    asm("mov dword ptr [_myPtr2], edx");
    //c=*myPtr1+*myPtr2;
    asm("mov eax, dword ptr [_myPtr1]"); //eax <-- &a
    asm("mov eax, [eax]");    //c = a

    asm("mov edx, dword ptr [_myPtr2]"); //eax <-- &a
    asm("mov edx, [edx]");    //c = a

    asm("add eax, edx");
    asm("mov [_c], eax");
    cout << "c = " << c << endl;
    return 0;
}
