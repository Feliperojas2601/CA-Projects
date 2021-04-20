#include <iostream>

using namespace std;

//extern C: para evitar name function mangling in c++
extern "C" int mix(int t_a,int t_b,int t_c)
{
                                   //: asm("push   ebp"); asm("mov ebp,esp"); asm("sub esp, espacio");
                                   // t_a ebp+8 t_b ebp +12 t_c ebp +16
                                   // q ebp -4 s ebp -8
    //int q=0,s=0;
    asm("sub esp, 2*4");
    asm("mov dword ptr [ebp-4],0");
    asm("mov dword ptr [ebp-8],0");
    //q=t_a+t_b;
    asm("mov eax, [ebp+8]");
    asm("mov edx, [ebp+12]");
    asm("add eax, edx");
    asm("mov [ebp-4],eax");
    //s=q-t_c;
    asm("mov edx, [ebp+16]");
    asm("mov eax, [ebp-4]");
    asm("sub eax, edx");
    asm("mov [ebp-8], eax");

    //return s;
    asm("mov esp,ebp");
}                                     //: asm("mov esp,ebp"); asm("pop ebp"); asm("ret"); //or: asm("pop ebp"); asm("ret");  si no se declaran local variables in C

int d;
int main()
{

    asm("sub esp, 6*4");
    //int a=5;
    asm("mov dword ptr [ebp-12], 5"); //en ebp-12   o  ebp-0xc
    //int b=8;
    asm("mov dword ptr [ebp-16],8");                         //en ebp-16   o  ebp-0x10
    //int c=4;                         //en ebp-20   o  ebp-0x14
    asm("mov dword ptr [ebp-20], 4");

    //d=mix(a,b,c);
    // pass arguments
    asm("mov eax, [ebp-20]");
    asm("mov [esp+8], eax");
    asm("mov eax, [ebp-16]");
    asm("mov [esp+4], eax");
    asm("mov eax, [ebp-12]");
    asm("mov [esp], eax");

    // call function
    asm("call _mix");
    asm("mov [_d], eax");

    cout << d << endl;
    cout << "Hello world!" << endl;
    return 0;
}
