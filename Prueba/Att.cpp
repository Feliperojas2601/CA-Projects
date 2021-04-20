#include <iostream>

using namespace std;

int x=3,y;

int main()
{

    //if(x>5)
    asm("cmpl $5,_x");
    asm("jng else1");
    //{
        //y=8;
        asm("movl $8,_y");
        asm("jmp endif1");
    //}
    //else
    //{
    asm("else1:");
        //y=13;
        asm("movl $13,_y");
    //}
    asm("endif1:");
    cout << "y = " << y <<endl;
    return 0;
}
