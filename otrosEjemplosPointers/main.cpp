#include <iostream>

using namespace std;

int vector[] = {28, 41, 7};
int *pi = vector;
int a;
int i;

int main()
{
    //a = *(pi + 1);
    //a = pi[1];

//    INTEL
//    asm("mov eax, [_pi]");
//    asm("mov eax, [eax + 4]");
//    asm("mov [_a], eax");

//    ATT
//    asm("mov _pi, %eax");
//    asm("mov 4(%eax),%eax");
//    asm("mov %eax, _a");

    //a = *(vector+1);
    //a = vector[1];

//    INTEL
//    asm("mov eax, [_vector + 4]");
//    asm("mov [_a], eax");

//    ATT
//    asm("mov _vector + 4, %eax");
//    asm("mov %eax, _a ");

    //pi=pi+1;
//    INTEL
//    asm("mov eax, [_pi]");
//    asm("add eax, 4");
//    asm("mov [_pi], eax");

//    ATT
//    asm("mov _pi, %eax");
//    asm("add $4, %eax");
//    asm("mov %eax, _pi");

    //a=*pi;

//    INTEL
//    asm("mov eax, [_pi]");
//    asm("mov eax, [eax]");
//    asm("mov dword ptr [_a], eax");

//    ATT
//    asm("mov _pi, %eax");
//    asm("mov (%eax), %eax");
//    asm("movl %eax, _a");

//-------------------------------------------------
    //i = 1;
//    INTEL
//    asm("mov dword ptr [_i], 1");

//    ATT
    asm("movl $1, _i");

    //a = vector[i];    //a <- 41

//    INTEL
//    asm("mov edx, [_i]");
//    asm("mov edx, [edx*4 + _vector]");
//    asm("mov [_a], edx");

//    ATT
//    asm("mov _i, %edx");
//    asm("mov _vector(, %edx, 4), %edx");
//    asm("mov %edx, _a");

//------------------------------------------

    // a = pi[i]

//    INTEL
//    asm("mov eax, [_i]");
//    asm("mov edx, [_pi]");
//    asm("mov eax, [eax*4 + edx]");
//    asm("mov [_a], eax");

//    ATT
    asm("mov _i,%eax");
    asm("mov _pi, %edx");
    asm("mov (%edx, %eax, 4), %eax");
    asm("mov %eax, _a");



    cout << a << endl;
    return 0;
}
