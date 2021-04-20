#include <iostream>

using namespace std;

int x=3,y;

int main()
{

    //if(x>5)
    asm("cmp dword ptr _x,5");
    asm("jng else1");
    //{
        //y=8;
        asm("mov dword ptr _y,8");
        asm("jmp endif1");
    //}
    //else
    //{
    asm("else1:");
        //y=13;
        asm("mov dword ptr _y,13");
    //}
    asm("endif1:");

    cout << "y = " << y <<endl;
    return 0;
}
