#include <iostream>

using namespace std;

//extern C: para evitar mangling name function in c++
extern "C" int suma(int t_a,int t_b)
{                                           //: asm("push   ebp"); asm("mov ebp,esp"); asm("sub esp, 16");
    asm("sub esp,1*4");                     //crear espacio
    //int q=0;
    asm("mov dword ptr [ebp-4],0");
    //q=t_a+t_b;
    asm("mov    edx,[ebp+8]");              //edx <-- a:5
    asm("mov    eax,[ebp+12]");             //eax <-- b:8
    asm("add    eax,edx");                  //eax <-- 13
    asm("mov    [ebp-0x4],eax");  //q <-- 13

    //return q;
    asm("mov    eax,[ebp-4]");  //eax <-- 13

    asm("mov esp,ebp");                     //liberar espacio

}                                           //asm("mov esp,ebp"); asm("pop ebp"); asm("ret");

int c;
int main()
{

     asm("sub esp,4*4");
    //int a=5;        //en ebp-12
     asm("mov dword ptr [ebp-12],5");
    //int b=8;        //en ebp-16
     asm("mov dword ptr [ebp-16],8");


    //c=suma(a,b);
    //passing parameters
    asm("mov eax,[ebp-16]");
    asm("mov [esp+4],eax");
    asm("mov eax,[ebp-12]");
    asm("mov [esp],eax");
    //call function
    asm("call _suma");       //save (push) IP and jump to _suma
    asm("mov [_c],eax");     //el valor de retorno en eax : c <-- 13


    cout << c << endl;
    cout << "Hello world!" << endl;
    return 0;
}
