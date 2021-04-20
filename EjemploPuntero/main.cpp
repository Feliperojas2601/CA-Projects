#include <iostream>

using namespace std;

int a = 9;
int *myPtr;

int main()
{
////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ejemplo en c++
    //myPtr=&a;    //myPtr queda con la dirección de memoria del primer byte de a
    //*myPtr=13;

    //ejemplo en asm INTEL
    //myPtr=&a;    //myPtr queda con la dirección de memoria del primer byte de a
    //asm("mov dword ptr [_myPtr], offset [_a]");  //myPtr queda con la direccion de a
    //or
    asm("lea eax, [_a]");  //lea: load effective address:
    asm("mov dword ptr [_myPtr], eax");
    //*myPtr=13;
    asm("mov eax, [_myPtr]");
    asm("mov dword ptr [eax], 13");

///////////////////////////////////////////////////////////////////////////////////////////////////7/////

//    //ejemplo en c++
//    //myPtr=&a;    //myPtr queda con la dirección de memoria del primer byte de a
//    //*myPtr=13;
//
//    //ejemplo en asm ATT
//    //myPtr=&a;    //myPtr queda con la dirección de memoria del primer byte de a
//    //asm("movl $_a, _myPtr");  //myPtr queda con la direccion de a
//    //or
//    asm("lea _a, %eax");  //lea: load effective address:
//    asm("movl %eax, _myPtr");
//    //*myPtr=13;
//    asm("mov _myPtr, %eax");
//    asm("movl $13, (%eax)");

    cout << "Hello world!" << endl;
    return 0;
}
