#include <iostream>

using namespace std;

extern "C" int suma(int t_a,int t_b)
{                                           //: asm("push   ebp"); asm("mov ebp,esp"); asm("sub esp, 16");

    int q=0;
    q=t_a+t_b;

    return q;
}                                           //: asm("mov esp,ebp"); asm("pop ebp"); asm("ret"); //or: asm("pop ebp"); asm("ret");


extern "C" int mix(int t_a,int t_b,int t_c)
{                                           //: asm("push   ebp"); asm("mov ebp,esp"); asm("sub esp, 16");

    int q=0,s=0;
    q=t_a+t_b;
    s=q-t_c;

    return s;                               //: asm("mov esp,ebp"); asm("pop ebp"); asm("ret");  //or: asm("pop ebp"); asm("ret");
}



int d,e;
int main()
{

    int a=5;                         //en ebp-12   o  ebp-0xc
    int b=8;                         //en ebp-16   o  ebp-0x10
    int c=4;                         //en ebp-20   o  ebp-0x14

    e=suma(b,c);
    d=mix(e,c,a);

    cout << d << endl;
    cout << "Hello world!" << endl;
    return 0;
}
