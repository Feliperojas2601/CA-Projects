#include <iostream>

using namespace std;

//extern C: para evitar name function mangling in c++
extern "C" int suma(int t_a,int t_b)
{                                           //: asm("push   ebp"); asm("mov ebp,esp"); asm("sub esp, 16");

    int q=0;
    q=t_a+t_b;

    return q;
}                                           //: asm("mov esp,ebp"); asm("pop ebp"); asm("ret"); //or asm("pop ebp"); asm("ret");

int c;
int main()
{

    int a=5;                         //en ebp-12
    int b=8;                         //en ebp-16

    c=suma(a,b);

    cout << c << endl;
    cout << "Hello world!" << endl;
    return 0;
}
