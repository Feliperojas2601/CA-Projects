#include <iostream>

using namespace std;

int x[3] = {28, 41, 7};
int *p1 = x;
int a;
int i=1;

int main()
{
//-----------Ej 1------------------------
    //a=p1[i] ;
    //a=*(p1+i);
    //Intel
    //asm("mov ebx, [_p1]");
    //asm("mov edx, [_i]");
    //asm("mov ebx, [ebx+edx*4]");
    //asm("mov [_a],ebx");
    //or
    //asm("mov ebx, [_p1]");
    //asm("mov edx, [_i]");
    //asm("shl edx,2);
    //asm("mov ebx, [ebx+edx*1]");
    //asm("mov [_a],ebx");
    //or
    //asm("mov ebx, [_p1]");
    //asm("mov edx, [_i]");
    //asm("shl edx,2);
    //asm(add ebx,edx);
    //asm("mov ebx,[ebx]);
    //asm("mov [_a],ebx");
    // ...
    //ATT
    //asm("mov _p1,%ebx");
    //asm("mov _i,%edx");
    //asm("mov (%ebx,%edx,4),%ebx");
    //asm("mov %ebx,_a");
    //or
    //asm("mov _p1,%ebx");
    //asm("mov _i,%edx");
    //asm("shl $2, %edx);
    //asm("mov (%ebx,%edx,1),%ebx);
    //asm("mov %ebx,_a");
    //or
    //asm("mov _p1,%ebx");
    //asm("mov _i,%edx");
    //asm("shl $2, %edx);
    //asm("add %edx,%ebx");
    //asm("mov (%ebx),%ebx);
    //asm("mov %ebx,_a");
//---------------------------------------
//----  Ej 2-----------------------------
    //a=p1[i+1] ;
    //a=*(p1+i+1);
    //Intel
    //asm("mov ebx, [_p1]");
    //asm("mov edx, [_i]");
    //asm("mov ebx, [ebx+edx*4+1*4]");
    //asm("mov [_a], ebx");
    //or
    //asm("mov ebx, [_p1]");
    //asm("mov edx, [_i]");
    //asm("add edx, 1");
    //asm("mov ebx, [ebx+edx*4]");
    //asm("mov [_a], ebx");
    //ATT
    //asm("mov _p1,%ebx");
    //asm("mov _i,%edx
    //asm("mov 4(%ebx,%edx,4),%ebx");
    //asm("mov %ebx,_a");
    //or
    //asm("mov _p1,%ebx");
    //asm("mov _i,%edx");
    //asm("add $1, %edx");
    //asm("mov (%ebx,%edx,4),%ebx");
    //asm("mov %ebx,_a");
//---------------------------------------
//------------ Ej 3 ---------------------
    //a=x[i+1] ;
    //a=*(x+i+1);
    //Intel
    //asm("mov edx, [_i]");
    //asm("add edx,1");
    //asm("mov eax,_x[edx*4]");
    //asm("mov [_a], eax");
    //or
    //asm("mov edx, [_i]");
    //asm("mov eax,[edx*4+_x+1*4]");
    //asm("mov [_a], eax")
    //ATT
//    asm("mov _i,%edx");
//    asm("add $1, %edx");
//    asm("mov _x(,%edx,4),%eax");
//    asm("mov %eax,_a");
    //or
    //asm("mov _i,%edx");
    //asm("mov _x+1*4(,%edx,4),%eax");
    //asm("mov %eax,_a");
//--------------------------------------
    cout<< a <<endl;
    cout << "Hello world!" << endl;
    return 0;
}
