#include <iostream>

using namespace std;

int a[3] = {5, 7, 2};
int i = 1, j = 2, k = 0;

int main()
{
//==============================
//    //primer ejemplo c++
//    //a[1] = a[2];
//
//==============================
//    //primer ejemplo INTEL
//    //a[1] = a[2];
//    asm("mov eax, dword ptr [_a+8]"); //eax <-- a[2]
//    asm("mov dword ptr [_a+4], eax");

//==============================

//    //primer ejemplo ATT
//    //a[1] = a[2];
//    asm("movl _a+8, %eax"); //eax <-- a[2]
//    asm("mov %eax, _a+4");

//==============================

//Segundo ejemplo en c++
    //a[k] = a[i] + a[j];
//===============================

////Segundo ejemplo en INTEL
//    //a[k] = a[i] + a[j];
//    asm("mov edx, dword ptr [_i]");
//    asm("mov ecx, [edx*4+_a]");
//
//    asm("mov edx, dword ptr [_j]");
//    asm("mov edx, [edx*4+_a]");
//
//    asm("add ecx, edx"); // ecx <-- a[i] + a[j]
//    asm("mov edx, dword ptr [_k]");
//    asm("mov [edx*4+_a], ecx");

//================================

//Segundo ejemplo en ATT
    //a[k] = a[i] + a[j];
    asm("movl _i, %edx");
    asm("mov _a(,%edx,4), %ecx");

    asm("movl _j, %edx");
    asm("mov _a(,%edx,4), %edx");

    asm("add %edx, %ecx"); // ecx <-- a[i] + a[j]
    asm("movl _k, %edx");
    asm("mov %ecx, _a(,%edx,4)");



    cout << "Hello world!" << endl;
    return 0;
}
